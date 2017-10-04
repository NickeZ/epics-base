cas_inc = include_directories('generic', 'io/bsdSocket')
cas_src = []
subdir('generic')
subdir('io/bsdSocket')

cas_st = library(
    'cas-st',
    cas_src,
    cas_st_src,
    link_with: [com, gdd, ca],
    include_directories: [
        com_inc,
        ca_inc,
        gdd_inc,
        cas_inc,
        include_directories('generic/st'),
    ],
    install: true,
)

# Does not build..
#cas_mt = library(
#    'cas-mt',
#    cas_src,
#    cas_mt_src,
#    link_with: [com, gdd, ca],
#    include_directories: [
#        com_inc,
#        ca_inc,
#        gdd_inc,
#        cas_inc,
#        include_directories('generic/mt'),
#    ],
#)

subdir('example/directoryService')
