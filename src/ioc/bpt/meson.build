install_headers('cvtTable.h')

menuconvert_dbd = pod_gen.process('menuConvert.dbd.pod')

#menuconvert_h = menu_gen.process('menuConvert.dbd')

executable(
    'makeBpt',
    'makeBpt.c',
    include_directories: [ca_inc, com_inc],
)

#dbcore_src += menuconvert_h
