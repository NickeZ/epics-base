flex_skel = ''.join([
    '-S',
    join_paths([
        meson.source_root(),
        'src/libCom/flex/flex.skel.static',
    ]),
])
dbloadtemplate_lex_c = custom_target(
    'dbLoadTemplate_lex.c',
    command: [flex_exe, flex_skel, '-t', '@INPUT@'],
    capture: true,
    output: 'dbLoadTemplate_lex.c',
    input: 'dbLoadTemplate_lex.l',
)

dbloadtemplate_c = custom_target(
    'dbLoadTemplate.tab.c',
    command: [yacc_exe, '-b@OUTDIR@/@BASENAME@', '@INPUT@'],
    output: ['@BASENAME@.tab.c', '@BASENAME@.tab.h'],
    input: 'dbLoadtemplate.y',
    depends: dbloadtemplate_lex_c,
)

install_headers(
    'dbLoadTemplate.h',
    'dbtoolsIocRegister.h',
)

dbcore_src += files(
    'dbtoolsIocRegister.c',
)
dbcore_src += dbloadtemplate_c

executable(
    'msi',
    'msi.c',
    include_directories: com_inc,
    link_with: com,
    install: true,
)
