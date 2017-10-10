install_data('assembleSnippets.pl', install_dir: get_option('bindir'))
install_data('convertRelease.pl', install_dir: get_option('bindir'))
install_data('cvsclean.pl', install_dir: get_option('bindir'))
install_data('dbdExpand.pl', install_dir: get_option('bindir'))
install_data('dbdReport.pl', install_dir: get_option('bindir'))
install_data('dbdToHtml.pl', install_dir: get_option('bindir'))
install_data('dbdToMenuH.pl', install_dir: get_option('bindir'))
install_data('dbdToRecordtypeH.pl', install_dir: get_option('bindir'))
install_data('dbExpand.pl', install_dir: get_option('bindir'))
install_data('dos2unix.pl', install_dir: get_option('bindir'))
install_data('expandVars.pl', install_dir: get_option('bindir'))
install_data('fullPathName.pl', install_dir: get_option('bindir'))
install_data('genVersionHeader.pl', install_dir: get_option('bindir'))
install_data('installEpics.pl', install_dir: get_option('bindir'))
install_data('makeIncludeDbd.pl', install_dir: get_option('bindir'))
install_data('makeMakefile.pl', install_dir: get_option('bindir'))
install_data('makeTestfile.pl', install_dir: get_option('bindir'))
install_data('mkmf.pl', install_dir: get_option('bindir'))
install_data('munch.pl', install_dir: get_option('bindir'))
install_data('podRemove.pl', install_dir: get_option('bindir'))
install_data('podToHtml.pl', install_dir: get_option('bindir'))
install_data('registerRecordDeviceDriver.pl', install_dir: get_option('bindir'))
install_data('replaceVAR.pl', install_dir: get_option('bindir'))
install_data('tap-to-junit-xml.pl', install_dir: get_option('bindir'))
install_data('useManifestTool.pl', install_dir: get_option('bindir'))

install_data('DBD.pm', install_dir: join_paths(get_option('libdir'), 'perl'))

dbdtomenuh = find_program('dbdToMenuH.pl')
dbdtorecordtypeh = find_program('dbdToRecordtypeH.pl')
podremove = find_program('podRemove.pl')

menu_gen = generator(
    dbdtomenuh,
    arguments: [
        '-o', join_paths('@BUILD_DIR@', '@BASENAME@.h'),
        '@INPUT@',
        '-I', '.', '..',
    ],
    output: '@BASENAME@.h',
)

pod_gen = generator(
    podremove,
    arguments: [
        '-o', join_paths('@BUILD_DIR@', '@BASENAME@'),
    ],
    output: '@BASENAME@',
)


subdir('EPICS')
subdir('DBD')
subdir('test')
