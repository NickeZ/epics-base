project('epics-base', 'c', 'cpp')

# Build first asLib_lex.c with `ninja -C build src/libCom/as/asLib_lex.c`
# Then build the whole project with `ninja -C build`.

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

if compiler_class == 'gcc' or compiler_class == 'clang'
    # _GNU_SOURCE is set by default in g++/clang++
    add_global_arguments(
        '-D_GNU_SOURCE',
        language: 'c',
    )
    add_global_arguments(
        '-D_DEFAULT_SOURCE',
        language: ['c', 'cpp'],
    )
endif


if os_class == 'linux'
    add_global_arguments(
        '-DUNIX',
        '-Dlinux',
        language: ['c', 'cpp'],
    )
    add_global_link_arguments(
        '-lrt',
        '-ldl',
        language: ['c', 'cpp'],
    )
endif

if target_machine.cpu_family() == 'x86_64'
    add_global_arguments(
        '-D_X86_64_',
        language: ['c', 'cpp'],
    )
endif

mv = find_program('mv')
cp = find_program('cp')
perl = find_program('perl')

subdir('src')
