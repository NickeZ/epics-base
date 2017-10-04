epics_unit_test_test = executable(
    'epicsUnitTestTest',
    'epicsUnitTestTest.c',
    include_directories: [com_inc, include_directories('.')],
    link_with: com,
)
configure_file(
    input: 'epicsUnitTestTest.plt',
    output: 'epicsUnitTestTest.t',
    configuration: configuration_data(),
)
test(
    'epicsUnitTestTest',
    perl,
    args: [
        '-MTest::Harness',
        '-e',
        'runtests @ARGV if @ARGV;',
        'epicsUnitTestTest.t',
    ],
    workdir: meson.current_build_dir(),
)

epics_inline_test = executable(
    'epicsInlineTest',
    'epicsInlineTest1.c',
    'epicsInlineTest2.c',
    'epicsInlineTest3.cpp',
    'epicsInlineTest4.cpp',
    include_directories: [com_inc, include_directories('.')],
    link_with: com,
)
test('epicsInlineTest', epics_inline_test)

tests = [
    'epicsTypesTest.c',
    'epicsMathTest.c',
    'epicsMMIOTest.c',
    'epicsEllTest.c',
    'epicsEnvTest.c',
    'epicsErrlogTest.c',
    'epicsStdioTest.c',
    'epicsStdlibTest.c',
    'epicsSockResolveTest.c',
    'epicsStringTest.c',
    'epicsTimeZoneTest.c',
    'epicsThreadOnceTest.c',
    'epicsThreadHooksTest.c',
    'epicsThreadPoolTest.c',
    'epicsExitTest.c',
    'ringPointerTest.c',
    'ringBytesTest.c',
    'epicsSpinTest.c',
    'macDefExpandTest.c',
    'cvtFastTest.c',
    'macLibTest.c',
    'taskwdTest.c',
    'epicsStackTraceTest.c',
    'epicsCalcTest.cpp',
    'epicsAlgorithmTest.cpp',
    'epicsTimeTest.cpp',
    'epicsThreadTest.cpp',
    'epicsThreadPriorityTest.cpp',
    'epicsThreadPrivateTest.cpp',
    'epicsTimerTest.cpp',
    'epicsEventTest.cpp',
    'epicsMutexTest.cpp',
    'epicsAtomicTest.cpp',
    'blockingSockTest.cpp',
    'epicsMessageQueueTest.cpp',
    'ipAddrToAsciiTest.cpp',
]

testharness_src = files()

foreach t : tests
    name = t.split('.')[0]
    test(name, executable(
        name,
        t,
        include_directories: [com_inc, include_directories('.')],
        link_with: com,
    ), timeout: 120)
    testharness_src += files(t)
endforeach

benchmarks = [
    'epicsThreadPerform.cpp',
    'epicsMaxThreads.c',
    'buckTest.c',
    #'fdmgrTest.c', # Depends on CA
    'epicsAtomicPerform.cpp',
    'cvtFastPerform.cpp',
]

foreach b : benchmarks
    name = b.split('.')[0]
    benchmark(name, executable(
        name,
        b,
        include_directories: [com_inc, include_directories('.')],
        link_with: com,
    ))
endforeach


# vxworks/rtems
#testharness_src += files('epicsRunLibComTests.c')
#test('testHarness', executable(
#    'testHarness',
#    testharness_src,
#    include_directories: [com_inc, include_directories('.')],
#    link_with: com,
#))
