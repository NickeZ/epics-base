yacc_src = files(
    'closure.c',
    'error.c',
    'lalr.c',
    'lr0.c',
    'antelope.c',
    'mkpar.c',
    'output.c',
    'reader.c',
    'skeleton.c',
    'symtab.c',
    'verbose.c',
    'warshall.c',
    '../osi/os/posix/epicsTempFile.cpp',
)

yacc_exe = executable('antelope', sources: yacc_src, include_directories: com_inc)

yacc = generator(
    yacc_exe,
    output: ['@BASENAME@.tab.c', '@BASENAME@.tab.h'],
    arguments: ['-b@BUILD_DIR@/@BASENAME@', '@EXTRA_ARGS@', '@INPUT@']
)
