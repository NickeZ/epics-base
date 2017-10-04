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

simple_tests_c = [
    'epicsTypesTest',
    'epicsMathTest',
    'epicsMMIOTest',
    'epicsEllTest',
    'epicsEnvTest',
    'epicsErrlogTest',
    'epicsStdioTest',
    'epicsStdlibTest',
    'epicsSockResolveTest',
    'epicsStringTest',
    'epicsTimeZoneTest',
    'epicsThreadOnceTest',
    'epicsThreadHooksTest',
    'epicsThreadPoolTest',
    'epicsExitTest',
    'ringPointerTest',
    'ringBytesTest',
    'epicsSpinTest',
    'macDefExpandTest',
    'cvtFastTest',
    'macLibTest',
    'taskwdTest',
    'epicsStackTraceTest',
]

simple_tests_cpp = [
    'epicsCalcTest',
    'epicsAlgorithmTest',
    'epicsTimeTest',
    'epicsThreadTest',
    'epicsThreadPriorityTest',
    'epicsThreadPrivateTest',
    'epicsTimerTest',
    'epicsEventTest',
    'epicsMutexTest',
    'epicsAtomicTest',
    'blockingSockTest',
    'epicsMessageQueueTest',
    'ipAddrToAsciiTest',
]

testharness_src = files()

foreach t : simple_tests_c
    test(t, executable(
        t,
        ''.join([t, '.c']),
        include_directories: [com_inc, include_directories('.')],
        link_with: com,
    ))
    testharness_src += files(''.join([t, '.c']))
endforeach

foreach t : simple_tests_cpp
    test(t, executable(
        t,
        ''.join([t, '.cpp']),
        include_directories: [com_inc, include_directories('.')],
        link_with: com,
    ), timeout: 120)
    testharness_src += files(''.join([t, '.cpp']))
endforeach


# vxworks/rtems
#testharness_src += files('epicsRunLibComTests.c')
#test('testHarness', executable(
#    'testHarness',
#    testharness_src,
#    include_directories: [com_inc, include_directories('.')],
#    link_with: com,
#))
