executable('caDirServ',
    files('main.cc', 'directoryServer.cc'),
    include_directories: [com_inc, gdd_inc, cas_inc, ca_inc],
    link_with: [com, gdd, cas_st, ca],
    install: true,
)
