flex_skel = ''.join([
    '-S',
    join_paths([
        meson.source_root(),
        'src/libCom/flex/flex.skel.static',
    ]),
])

dblex_c = custom_target(
    'dbLex.c',
    command: [flex_exe, flex_skel, '-t', '@INPUT@'],
    output: 'dbLex.c',
    input: 'dbLex.l',
    capture: true,
)

dbyacc_c = custom_target(
    'dbYacc.tab.c',
    command: [yacc_exe, '-b@OUTDIR@/@BASENAME@', '@INPUT@'],
    output: ['@BASENAME@.tab.c', '@BASENAME@.tab.h'],
    input: 'dbYacc.y',
    depends: dblex_c,
)

install_headers(
    'dbBase.h',
    'dbFldTypes.h',
    'dbStaticLib.h',
    'dbStaticPvt.h',
    'link.h',
    'special.h',
    'guigroup.h',
    'devSup.h',
    'drvSup.h',
    'recSup.h',
    'dbStaticIocRegister.h',
)

dbcore_src += files(
    'dbStaticLib.c',
    'dbPvdLib.c',
    'dbStaticRun.c',
    'dbStaticIocRegister.c',
)
dbcore_src += dbyacc_c
