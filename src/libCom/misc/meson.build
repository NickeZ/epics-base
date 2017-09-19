com_src += files('alarmString.c', 'aToIPAddr.c', 'adjustment.c', 'cantProceed.c', 'epicsConvert.c', 'epicsExit.c', 'epicsStdlib.c', 'epicsString.c', 'truncateFile.c', 'ipAddrToAsciiAsynchronous.cpp', 'epicsUnitTest.c')


configure_file(
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
#custom_target('epicsVersion.h' command: ['makeEpicsVersion.pl', '-o', ''])
