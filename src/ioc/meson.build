dbcore_inc = include_directories(
    'as',
    'db',
    'dbStatic',
    'dbtemplate',
    'misc',
    'rsrv',
)
dbcore_src = files()

subdir('as')
subdir('bpt')
subdir('db')
subdir('dbStatic')
subdir('dbtemplate')
subdir('misc')
subdir('registry')
subdir('rsrv')

dbcore = library(
    'dbCore',
    dbcore_src,
    include_directories: [ca_inc, com_inc],
    link_with: [ca, com],
)

executable(
    'ascheck',
    ascheck_src,
    include_directories: [ca_inc, com_inc, dbcore_inc],
    link_with: [com, ca, dbcore],
)
