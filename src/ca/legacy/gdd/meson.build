aitGen_exe = executable(
    'aitGen',
    'aitTypes.c',
    'aitGen.c',
    include_directories: com_inc,
    link_with: com,
)

aitConvertGenerated_cpp = custom_target(
    'aitConvertGenerated.cc',
    command: [aitGen_exe, '@OUTPUT@'],
    output: 'aitConvertGenerated.cc',
)

aitConvertGenerated_dummy_cpp = custom_target(
    'dummy',
    command: 'true',
    output: '',
    depends: aitConvertGenerated_cpp,
)

gdd_inc = include_directories('.')

install_headers(
    'gdd.h',
    'gddI.h',
    'gddContainer.h',
    'gddContainerI.h',
    'gddArray.h',
    'gddArrayI.h',
    'gddScalar.h',
    'gddScalarI.h',
    'gddNewDel.h',
    'gddUtils.h',
    'gddUtilsI.h',
    'gddErrorCodes.h',
    'aitTypes.h',
    'aitConvert.h',
    'aitHelpers.h',
    'dbMapper.h',
    'gddAppTable.h',
    'gddAppFuncTable.h',
    'smartGDDPointer.h',
    'gddEnumStringTable.h',
)

gdd_src = files(
    'gdd.cc',
    'gddTest.cc',
    'gddAppTable.cc',
    'gddNewDel.cc',
    'gddAppDefs.cc',
    'aitTypes.c',
    'aitConvert.cc',
    'aitHelpers.cc',
    'gddArray.cc',
    'gddContainer.cc',
    'gddErrorCodes.cc',
    'gddUtils.cc',
    'gddEnumStringTable.cc',
)

genApps_exe = executable(
    'genApps',
    'genApps.cc',
    gdd_src,
    aitConvertGenerated_dummy_cpp,
    include_directories: com_inc,
    link_with: com,
)

genApps = find_program('genApps')

gddApps_h = configure_file(
    command: [genApps, '@OUTPUT@'],
    output: 'gddApps.h',
)

#gddApps_h = custom_target(
#    'gddApps.h',
#    command: [genApps_exe, '@OUTPUT@'],
#    output: 'gddApps.h',
#)

gdd = library(
    'gdd',
    aitConvertGenerated_dummy_cpp,
    gddApps_h,
    gdd_src,
    'dbMapper.cc',
    include_directories: [com_inc, ca_inc],
    link_with: com,
    install: true,
)

#install_headers('gddApps.h')
#install_headers(gddApps_h)
