project('epics-base', 'c', 'cpp')

threads = dependency('threads')

add_global_arguments(
    '-DUSE_TYPED_RSET',
    language: ['c', 'cpp'],
)

# gcc, clang, msvc...
compiler_class = meson.get_compiler('c').get_id()

# x86_64-linux...
t_a = '-'.join([target_machine.cpu_family(), target_machine.system()])

os_class = target_machine.system()


if target_machine.system() == 'linux'
    add_global_arguments(
        '-D_GNU_SOURCE',
        '-D_DEFAULT_SOURCE',
        language: ['c', 'cpp'],
    )
    add_global_link_arguments(
        '-lrt',
        '-ldl',
        language: ['c', 'cpp'],
    )
endif

add_global_arguments(
    '-D_X86_64_',
    '-DUNIX',
    '-Dlinux',
    language: 'c',
)

mv = find_program('mv')
cp = find_program('cp')
perl = find_program('perl')

subdir('src')
