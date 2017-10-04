com_src += files(
    'alarmString.c',
    'aToIPAddr.c',
    'adjustment.c',
    'cantProceed.c',
    'epicsConvert.c',
    'epicsExit.c',
    'epicsStdlib.c',
    'epicsString.c',
    'truncateFile.c',
    'ipAddrToAsciiAsynchronous.cpp',
    'epicsUnitTest.c'
)

epics_version = configure_file(
    command: [
        perl,
        files('makeEpicsVersion.pl'),
        '-o',
        'epicsVersion.h',
        join_paths(
            meson.source_root(),
            'configure',
            'CONFIG_BASE_VERSION',
        )
    ],
    output: 'epicsVersion.h'
)

install_headers(
    'alarm.h',
    'alarmString.h',
    'adjustment.h',
    'cantProceed.h',
    'dbDefs.h',
    'epicsConvert.h',
    'epicsExit.h',
    'epicsStdlib.h',
    'epicsString.h',
    'epicsTypes.h',
    'shareLib.h',
    'epicsExport.h',
    'unixFileName.h',
    'locationException.h',
    'ipAddrToAsciiAsynchronous.h',
    'epicsUnitTest.h',
    'testMain.h',
    epics_version,
)
