//
// fileDescriptorManager.process(delay);
// (the name of the global symbol has leaked in here)
//

//
// Example EPICS CA server
//


#include <exServer.h>
#include <fdManager.h>

const pvInfo exServer::pvList[] = {
	pvInfo (1.0e-1, "jane", 10.0f, 0.0f, excasIoSync),
	pvInfo (2.0, "fred", 10.0f, -10.0f, excasIoSync),
	pvInfo (1.0e-1, "janet", 10.0f, 0.0f, excasIoAsync),
	pvInfo (2.0, "freddy", 10.0f, -10.0f, excasIoAsync)
};


//
// static data for exServer
//
gddAppFuncTable<exPV> exServer::ft;

//
// main()
//
int main (int argc, const char **argv)
{
	osiTime		begin(osiTime::getCurrent());
	exServer	*pCAS;
	unsigned 	debugLevel = 0u;
	float		executionTime;
	aitBool		forever = aitTrue;
	int		i;

	pCAS = new exServer(32u,5u,500u);
	if (!pCAS) {
		return (-1);
	}

	for (i=1; i<argc; i++) {
		if (sscanf(argv[i], "-d %u", &debugLevel)==1) {
			continue;
		}
		if (sscanf(argv[i],"-t %f", &executionTime)==1) {
			forever = aitFalse;
			continue;
		}
		printf ("usage: %s -d<debug level> -t<execution time>\n", 
			argv[0]);
		return (1);
	}

	pCAS->setDebugLevel(debugLevel);

	if (forever) {
		osiTime	delay(1000u,0u);
		//
		// loop here forever
		//
		while (aitTrue) {
			fileDescriptorManager.process(delay);
		}
	}
	else {
		osiTime total(executionTime);
		osiTime delay(osiTime::getCurrent() - begin);
		//
		// loop here untime the specified execution time
		// expires
		//
		while (delay < total) {
			fileDescriptorManager.process(delay);
			delay = osiTime::getCurrent() - begin;
		}
	}
	return (0);
}

//
// exServer::exServer()
//
exServer::exServer(unsigned pvMaxNameLength, unsigned pvCountEstimate, 
	unsigned maxSimultaneousIO) :
	caServer(pvMaxNameLength, pvCountEstimate, maxSimultaneousIO)
{
	ft.installReadFunc("status",exPV::getStatus);
	ft.installReadFunc("severity",exPV::getSeverity);
	ft.installReadFunc("seconds",exPV::getSeconds);
	ft.installReadFunc("nanoseconds",exPV::getNanoseconds);
	ft.installReadFunc("precision",exPV::getPrecision);
	ft.installReadFunc("graphicHigh",exPV::getHighLimit);
	ft.installReadFunc("graphicLow",exPV::getLowLimit);
	ft.installReadFunc("controlHigh",exPV::getHighLimit);
	ft.installReadFunc("controlLow",exPV::getLowLimit);
	ft.installReadFunc("alarmHigh",exPV::getHighLimit);
	ft.installReadFunc("alarmLow",exPV::getLowLimit);
	ft.installReadFunc("alarmHighWarning",exPV::getHighLimit);
	ft.installReadFunc("alarmLowWarning",exPV::getLowLimit);
	ft.installReadFunc("units",exPV::getUnits);
	ft.installReadFunc("value",exPV::getValue);
}

//
// exServer::pvExistTest()
//
caStatus exServer::pvExistTest(const casCtx &ctxIn, const char *pPVName, 
				gdd &canonicalPVName)
{
	const pvInfo	*pPVI;

	pPVI = exServer::findPV(pPVName);
	if (pPVI) {
		if (pPVI->getIOType()==excasIoAsync) {
			exAsyncExistIO	*pIO;
			pIO = new exAsyncExistIO(pPVI, ctxIn, canonicalPVName);
			if (pIO) {
				return S_casApp_asyncCompletion;
			}
			else {
				return S_casApp_noMemory;
			}
		}

		//
		// there are no name aliases in this
		// server's PV name syntax
		//
		canonicalPVName.put (pPVI->getName());
		return S_casApp_success;
	}

	return S_casApp_pvNotFound;
}

//
// findPV()
//
const pvInfo *exServer::findPV(const char *pName)
{
	const pvInfo *pPVI;
	const pvInfo *pPVAfter = 
		&exServer::pvList[NELEMENTS(exServer::pvList)];

	for (pPVI = exServer::pvList; pPVI < pPVAfter; pPVI++) {
		if (strcmp (pName, pPVI->getName().string()) == '\0') {
			return pPVI;
		}
	}
	return NULL;
}

//
// exServer::createPV()
//
casPV *exServer::createPV (const casCtx &ctxIn, const char *pPVName)
{
	const pvInfo	*pInfo;

	pInfo = exServer::findPV(pPVName);
	if (!pInfo) {
		return NULL;
	}

	switch (pInfo->getIOType()){
	case excasIoSync:
		return new exSyncPV (ctxIn, *pInfo);
	case excasIoAsync:
		return new exAsyncPV (ctxIn, *pInfo);
	default:
		return NULL;
	}
}

//
// exServer::createPV()
//
void exServer::show (unsigned level)
{
	//
	// server tool specific show code goes here
	//

	//
	// print information about ca server libarary
	// internals
	//
	this->caServer::show(level);
}

//
// this is a noop that postpones the timer expiration
// destroy so the exAsyncIO class will hang around until the
// casAsyncIO::destroy() is called
//
void exAsyncIOTimer::destroy()
{
}

//
// exAsyncExistIO::expire()
// (a virtual function that runs when the base timer expires)
//
void exAsyncExistIO::expire()
{
        //
        // post IO completion
        //
        this->postIOCompletion(S_cas_success);
}

