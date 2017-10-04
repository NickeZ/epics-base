com_src += files(
    'errlog.c',
    'errSymLib.c',
)

com_src += configure_file(
    command: [
        perl,
        files('makeStatTbl.pl'),
        files(
            '../osi/devLib.h',
            '../osi/epicsTime.h',
            '../as/asLib.h',
            '../../ioc/db/dbAccessDefs.h',
            '../../ioc/dbStatic/devSup.h',
            '../../ioc/dbStatic/drvSup.h',
            '../../ioc/dbStatic/recSup.h',
            '../../ioc/dbStatic/dbStaticLib.h',
            '../error/errMdef.h',
            '../../ca/legacy/pcas/generic/casdef.h',
            '../../ca/legacy/gdd/gddAppFuncTable.h',
        ),
    ],
    output: 'errSymTbl.c',
)

install_headers(
    'epicsPrint.h',
    'errMdef.h',
    'errSymTbl.h',
    'errlog.h',
    'error.h',
)
