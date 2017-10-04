tools = ['caget.c', 'camonitor.c', 'cainfo.c', 'caput.c']

foreach t : tools
    executable(
        t.split('.')[0],
        'tool_lib.c',
        t,
        include_directories: [com_inc, ca_inc],
        link_with: [com, ca],
        install: true,
    )
endforeach
