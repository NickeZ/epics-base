dbrecstd_src = files()

subdir('rec')

dbrecstd = library('dbRecStd', dbrecstd_src,
    link_with: [com, ca, dbcore],
    include_directories: [com_inc, ca_inc, dbcore_inc],
    dependencies: threads,
    install: true,
)
