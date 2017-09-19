# We would like to implement flex as a Generator but it is missing a 'capture'
# option right now.
#aslib_lex_c = flex.process('asLib_lex.l')

# Instead we implement it as a custom target
aslib_lex_c = custom_target(
    'asLib_lex.c',
    command: [flex_exe, '-Ssrc/libCom/flex/flex.skel.static', '-t', '@INPUT@'],
    capture: true,
    output: 'asLib_lex.c',
    input: 'asLib_lex.l',
)

# We would also like to depend on the aslib_lex_c file above but that
# functionality is also missing.
aslib_c = yacc.process(
    'asLib.y',
    #extra_depends: aslib_lex_c.full_path(),
)
com_src += [aslib_c] + files('asTrapWrite.c')
as_includes = ['asLib.h', 'asTrapWrite.h']
