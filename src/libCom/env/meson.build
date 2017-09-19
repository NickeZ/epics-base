com_src += files('envSubr.c')

configure_file(
    command: [
        'cp',
        '@INPUT@',
        '@OUTPUT@',
    ],
    input: 'envDefs.h',
    output: 'envDefs.h',
)

com_src += configure_file(
    command: [
        perl,
        '-I',
        join_paths(
            meson.source_root(),
            'src',
            'tools',
        ),
        files('bldEnvData.pl'),
        '-t',
        t_a,
        '-c',
        compiler_class,
        '-s',
        os_class,
        join_paths(
            meson.source_root(),
            'configure',
        )
    ],
    output: 'envData.c'
)
