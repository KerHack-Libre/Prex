project('cpuinfo', 'c',
  version : '0.1',
  default_options : ['warning_level=3']) 

cc =meson.get_compiler('c') 

add_project_arguments(
  cc.command_arguments(
     '-Wformat',
     '-Wunused'
    )
  ,
  language:'c'
  )
executable('cpuinfo',
           'main.c',
           'cpuinfo.c',
           install : true)
