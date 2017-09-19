#aslib_lex_c = flex.process('asLib_lex.l')
#aslib_lex_c = configure_file(command: flex, capture: true, output: '')
aslib_lex_c = custom_target(
    'asLib_lex.c',
    command: [flex_exe, '-Ssrc/libCom/flex/flex.skel.static', '-t', '@INPUT@'],
    capture: true,
    output: 'asLib_lex.c',
    input: 'asLib_lex.l',
)

aslib_c = yacc.process(
    'asLib.y',
    #extra_depends: aslib_lex_c.full_path(),
    #include_directories: include_directories(meson.current_build_dir())
)
com_src += [aslib_c] + files('asTrapWrite.c')
as_includes = ['asLib.h', 'asTrapWrite.h']
