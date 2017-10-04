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

epics_types_test = executable(
    'epicsTypesTest',
    'epicsTypesTest.c',
    include_directories: [com_inc, include_directories('.')],
    link_with: com,
)
test('epicsTypesTest', epics_types_test)

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

epics_calc_test = executable(
    'epicsCalcTest',
    'epicsCalcTest.cpp',
    include_directories: [com_inc, include_directories('.')],
    link_with: com,
)
test('epicsInlineTest', epics_calc_test)
