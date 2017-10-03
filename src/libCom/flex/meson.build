parse_tab = yacc.process('parse.y', extra_args: ['-l', '-d'])

parse_c = custom_target(
    'parse.c',
    command: [mv, '@INPUT0@', '@OUTPUT@'],
    input: parse_tab,
    output: 'parse.c'
)
parse_h = custom_target(
    'parse.h',
    command: [mv, '@INPUT1@', '@OUTPUT@'],
    input: parse_tab,
    output: 'parse.h'
)

flex_src = files(
    'ccl.c',
    'dfa.c',
    'ecs.c',
    'gen.c',
    'misc.c',
    'nfa.c',
    'sym.c',
    'tblcmp.c'
)
flex_exe = executable(
    'e_flex',
    flex_src,
    parse_c,
    parse_h,
    epics_temp_file,
    include_directories: com_inc
)

#flex_static = configure_file(
#    command: [cp, '@INPUT@', '@OUTPUT@'],
#    input: 'flex.skel.static',
#    output: 'flex.skel.static'
#)
#
#flex_skel = files('flex.skel.static')

flex = generator(
    flex_exe,
    output: '@BASENAME@.c',
    arguments: [
        '-S@SOURCE_DIR@/src/libCom/flex/flex.skel.static',
        '-t',
        '@INPUT@',
    ],
    capture: true,
)
