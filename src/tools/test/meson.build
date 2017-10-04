tests = [
    'Breaktable',
    'DBD',
    'Device',
    'Driver',
    'Function',
    'macLib',
    'Menu',
    'Recfield',
    'Recordtype',
    'Registrar',
    'Snippets',
    'Variable',
]

foreach t : tests
    configure_file(
        input: ''.join([t, '.plt']),
        output: ''.join([t, '.t']),
        configuration: configuration_data(),
    )
    test(
        t,
        perl,
        args: [
            '-I',
            join_paths(
                meson.source_root(),
                'src',
                'tools',
            ),
            '-MTest::Harness',
            '-e',
            'runtests @ARGV if @ARGV;',
            ''.join([t,'.t']),
        ],
        workdir: meson.current_build_dir(),
    )
endforeach
