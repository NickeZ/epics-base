com_src += files(
    'epicsThread.cpp',
    'epicsMutex.cpp',
    'epicsEvent.cpp',
    'epicsTime.cpp',
    'epicsMessageQueue.cpp',
    'epicsMath.cpp',
    'epicsGeneralTime.c',
    'osiClockTime.c',
    'osiSock.c',
    'epicsReadline.c',
    'epicsStdio.c',
    'devLibVME.c',
    'epicsStackTrace.c',
)

if meson.get_compiler('c').get_id() == 'gcc'
    osi_compiler = join_paths('compiler', 'gcc')
elif meson.get_compiler('c').get_id() == 'clang'
    osi_compiler = join_paths('compiler', 'clang')
else
    osi_compiler = join_paths('compiler', 'default')
endif

osi_machine = [join_paths('os', 'default')]
if target_machine.system() == 'linux'
    osi_machine += [
        join_paths('os', 'posix'),
        join_paths('os', 'Linux'),
    ]
    epics_temp_file = files(join_paths('os', 'posix', 'epicsTempFile.cpp'))
    com_src += files(
        join_paths('os', 'posix', 'epicsAtomicOSD.cpp'),
        join_paths('os', 'posix', 'osdSock.c'),
        join_paths('os', 'posix', 'osdSockAddrReuse.cpp'),
        join_paths('os', 'posix', 'systemCallIntMech.cpp'),
        join_paths('os', 'default', 'epicsSocketConvertErrnoToString.cpp'),
        join_paths('os', 'default', 'osdAssert.c'),
        join_paths('os', 'posix', 'osdFindSymbol.c'),
        join_paths('os', 'default', 'osdInterrupt.c'),
        join_paths('os', 'default', 'osdPoolStatus.c'),
        join_paths('os', 'default', 'osdSignal.cpp'),
        join_paths('os', 'default', 'osdEnv.c'),
        join_paths('os', 'posix', 'epicsTempFile.cpp'),
        join_paths('os', 'posix', 'osdStdio.c'),
        join_paths('os', 'posix', 'osdThread.c'),
        join_paths('os', 'Linux', 'osdThreadExtra.c'),
        join_paths('os', 'default', 'osdThreadHooks.c'),
        join_paths('os', 'posix', 'osdMutex.c'),
        join_paths('os', 'posix', 'osdSpin.c'),
        join_paths('os', 'posix', 'osdEvent.c'),
        join_paths('os', 'posix', 'osdTime.cpp'),
        join_paths('os', 'posix', 'osdProcess.c'),
        join_paths('os', 'default', 'osdNetIntf.c'),
        join_paths('os', 'default', 'osdMessageQueue.cpp'),
        join_paths('os', 'default', 'devLibVMEOSD.c'),
        join_paths('os', 'Linux', 'osdBackTrace.cpp'),
        join_paths('os', 'Linux', 'osdFindAddr.c'),
    )
elif target_machine.system() == 'vxWorks'
    com_src += files('osiNTPTime.c')
elif target_machine.system() == 'RTEMS'
    com_src += files(
        'osiNTPTime.c',
        join_paths('os', 'RTEMS', 'osdMessageQueue.c')
    )
else
    com_src += files(join_paths('os', 'default', 'epicsAtomicOSD.cpp'))
endif


com_inc += [include_directories(osi_compiler, osi_machine)]
