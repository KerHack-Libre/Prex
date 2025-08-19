
project('Prex', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])
cc =  meson.get_compiler('c')

add_project_arguments(
  cc.get_supported_arguments(
    '-Wformat',
    '-Wunused'
    ),
  language:'c' 
  )

prex_sources_files=[ 
  'cpuinfo/cpuinfo.c', 
  'misc/execbn.c'
  ]

prex_include=[
  'cpuinfo', 
  'misc'
  ]

prex_lib =both_libraries('Prex' ,  prex_sources_files , include_directories:[prex_include])
executable('Prex',
           install : false)
