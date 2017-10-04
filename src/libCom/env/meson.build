com_src += files('envSubr.c')

# We have to copy envDefs.h to the build directory because the
# script below expects it in the current working directory when it
# is running.
configure_file(
    input: 'envDefs.h',
    output: 'envDefs.h',
    configuration: configuration_data()
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

install_headers('envDefs.h')
