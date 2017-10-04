install_headers(
    'cadef.h',
    'caerr.h',
    'caeventmask.h',
    'caProto.h',
    'db_access.h',
    'addrList.h',
    'cacIO.h',
    'caDiagnostics.h',
)
ca_src = files(
    'cac.cpp',
    'cacChannel.cpp',
    'cacChannelNotify.cpp',
    'cacContextNotify.cpp',
    'cacReadNotify.cpp',
    'cacWriteNotify.cpp',
    'cacStateNotify.cpp',
    'access.cpp',
    'iocinf.cpp',
    'convert.cpp',
    'test_event.cpp',
    'repeater.cpp',
    'searchTimer.cpp',
    'disconnectGovernorTimer.cpp',
    'repeaterSubscribeTimer.cpp',
    'baseNMIU.cpp',
    'nciu.cpp',
    'netiiu.cpp',
    'udpiiu.cpp',
    'tcpiiu.cpp',
    'noopiiu.cpp',
    'netReadNotifyIO.cpp',
    'netWriteNotifyIO.cpp',
    'netSubscription.cpp',
    'tcpSendWatchdog.cpp',
    'tcpRecvWatchdog.cpp',
    'bhe.cpp',
    'ca_client_context.cpp',
    'oldChannelNotify.cpp',
    'oldSubscription.cpp',
    'getCallback.cpp',
    'getCopy.cpp',
    'putCallback.cpp',
    'syncgrp.cpp',
    'CASG.cpp',
    'syncGroupNotify.cpp',
    'syncGroupReadNotify.cpp',
    'syncGroupWriteNotify.cpp',
    'localHostName.cpp',
    'comQueRecv.cpp',
    'comQueSend.cpp',
    'comBuf.cpp',
    'hostNameCache.cpp',
    'msgForMultiplyDefinedPV.cpp',
)

ca_inc = [
    com_inc,
    include_directories(
        '.',
    )
]

ca = library(
    'ca',
    link_with: com,
    sources: ca_src,
    include_directories: ca_inc,
    dependencies: threads,
    install: true,
)

executable(
    'caRepeater',
    files('caRepeater.cpp'),
    include_directories: [com_inc, ca_inc],
    link_with: [ca, com],
)

executable(
    'catime',
    files('catimeMain.c', 'catime.c'),
    include_directories: [com_inc, ca_inc],
    link_with: [ca, com],
)

executable(
    'acctst',
    files('acctstMain.c', 'acctst.c'),
    include_directories: [com_inc, ca_inc],
    link_with: [ca, com],
)

executable(
    'caEventRate',
    files('caEventRateMain.cpp', 'caEventRate.cpp'),
    include_directories: [com_inc, ca_inc],
    link_with: [ca, com],
)

executable(
    'casw',
    files('casw.cpp'),
    include_directories: [com_inc, ca_inc],
    link_with: [ca, com],
)

executable(
    'caConnTest',
    files('caConnTestMain.cpp', 'caConnTest.cpp'),
    include_directories: [com_inc, ca_inc],
    link_with: [ca, com],
)

ca_test = executable(
    'ca_test',
    files('test/ca_test_main.c', 'test/ca_test.c'),
    include_directories: [com_inc, ca_inc, include_directories('test')],
    link_with: [ca, com],
)

#test('ca_test_test', ca_test)
