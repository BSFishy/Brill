conf_data = configuration_data()
conf_data.set('version', meson.project_version())
conf_data.set('llvm_version', llvm_version)
configure_file(input : files('brill_version.h.in'),
               output : 'brill_version.h',
               configuration : conf_data)

brill_inc = include_directories('.')