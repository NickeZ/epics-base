# Currently it is not possible to depend on a generated file.
#aslib_lex_c = flex.process('asLib_lex.l')
#aslib_lex_c_dep = declare_dependency(sources: [aslib_lex_c])

# Use this to test drive the above generator
#custom_target('hello', input: aslib_lex_c, output: 'hello', command: ['echo', 'hello'], capture: true)

# Instead we implement it as a custom target
flex_skel = ''.join([
    '-S',
    join_paths([
        meson.source_root(),
        'src/libCom/flex/flex.skel.static',
    ]),
])
aslib_lex_c = custom_target(
    'asLib_lex.c',
    command: [flex_exe, flex_skel, '-t', '@INPUT@'],
    capture: true,
    output: 'asLib_lex.c',
    input: 'asLib_lex.l',
)

#aslib_c = yacc.process(
#    'asLib.y',
#    extra_depends: aslib_lex_c,
#)

aslib_c = custom_target(
    'asLib.tab.c',
    command: [yacc_exe, '-b@OUTDIR@/@BASENAME@', '@INPUT@'],
    output: ['@BASENAME@.tab.c', '@BASENAME@.tab.h'],
    input: 'asLib.y',
    depends: aslib_lex_c,
)
com_src += [aslib_c] + files('asTrapWrite.c')
as_includes = ['asLib.h', 'asTrapWrite.h']

install_headers('asLib.h', 'asTrapWrite.h')
