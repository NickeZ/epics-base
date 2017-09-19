com_src = []
com_inc = [
    include_directories(
        'as',
        'bucketLib',
        'calc',
        'cppStd',
        'cvtFast',
        'cxxTemplates',
        'dbmf',
        'ellLib',
        'env',
        'error',
        'fdmgr',
        'freeList',
        'gpHash',
        'iocsh',
        'log',
        'macLib',
        'misc',
        'osi',
        'pool',
        'ring',
        'taskwd',
        'timer',
        'yajl',
    )
]
# epicsTempFile is used by flex
subdir('osi')
# Creates yacc tool
subdir('yacc')
# Creates flex tool
subdir('flex')

subdir('as')
subdir('bucketLib')
subdir('calc')
subdir('cvtFast')
subdir('cxxTemplates')
subdir('dbmf')
subdir('ellLib')
subdir('env')
subdir('error')
subdir('fdmgr')
subdir('freeList')
subdir('gpHash')
subdir('iocsh')
subdir('log')
subdir('macLib')
subdir('misc')
subdir('pool')
subdir('ring')
subdir('taskwd')
subdir('timer')
subdir('yajl')
com = library('com', sources: com_src, include_directories: com_inc, dependencies: threads)

executable('iocLogServer', sources: 'log/iocLogServer.c', link_with: com, include_directories: com_inc)
