
/*  $Id$
 *
 *                    L O S  A L A M O S
 *              Los Alamos National Laboratory
 *               Los Alamos, New Mexico 87545
 *
 *  Copyright, 1986, The Regents of the University of California.
 *
 *  Author: Jeff Hill
 */

#include "iocinf.h"
#include "netSubscription_IL.h"
#include "nciu_IL.h"

tsFreeList < class netSubscription, 1024 > netSubscription::freeList;

netSubscription::netSubscription ( nciu &chan, chtype typeIn, unsigned long countIn, 
    unsigned short maskIn, cacNotify &notifyIn ) :
    cacNotifyIO (notifyIn), baseNMIU (chan), 
    type (typeIn), count (countIn), mask (maskIn)
{
    this->subscriptionMsg ();
}

netSubscription::~netSubscription () 
{
    this->chan.subscriptionCancelMsg ( this->getId () );
}

void netSubscription::destroy()
{
    this->baseNMIU::destroy ();
}

int netSubscription::subscriptionMsg ()
{
    return this->chan.subscriptionMsg ( this->getId (), this->type, 
        this->count, this->mask );
}

void netSubscription::disconnect ( const char * /* pHostName */ )
{
}

void netSubscription::completionNotify ()
{
    this->cacNotifyIO::completionNotify ();
}

void netSubscription::completionNotify ( unsigned typeIn, 
	unsigned long countIn, const void *pDataIn )
{
    this->cacNotifyIO::completionNotify ( typeIn, countIn, pDataIn );
}

void netSubscription::exceptionNotify ( int status, const char *pContext )
{
    this->cacNotifyIO::exceptionNotify ( status, pContext );
}

void netSubscription::exceptionNotify ( int statusIn, 
    const char *pContextIn, unsigned typeIn, unsigned long countIn )
{
    this->cacNotifyIO::exceptionNotify ( statusIn, 
          pContextIn, typeIn, countIn );
}

void netSubscription::show ( unsigned level ) const
{
    printf ( "event subscription IO at %p, type %s, element count %lu, mask %u\n", 
        this, dbf_type_to_text ( this->type ), this->count, this->mask );
    if ( level > 0u ) {
        this->baseNMIU::show ( level - 1u );
    }
}
