# @file  meson.build 
# @brief build for  cpuinfo 
# @author 
project('cpuinfo', 'c',
  version : '0.1',
  default_options : ['c_std=gnu99' ,'warning_level=3']) 

cc =meson.get_compiler('c') 

add_project_arguments(
  cc.get_supported_arguments(
     '-Wformat',
     '-Wunused'
    )
  ,
  language:'c'
  )


cpuinfo_libraries  =  both_libraries('cpuinfo','cpuinfo.c',name_prefix:'prex_' )  
executable('cpuinfo',
           'main.c',
           link_with:  cpuinfo_libraries, 
           install : true)
