 /**
 * @file  cpuinfo.h
 * @brief cpu information  collection data
 * @licence Copyright (C) 2025  Umar Ba <jUmarB@protonmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

 */

#define _GNU_SOURCE 
#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/cdefs.h>
#include <errno.h> 
#include <err.h> 

#include "cpuinfo.h"

char * cpu_raw_info =  (char * ) 00 ; 

static cpu_t cpu_overview(int  fd ) 
{
  struct { 
    size_t _size ;  
    int  _section ;  
    int  _nproc ; 
  }cpu_base_info= {0,~0,0} ; 
  
  char c =0 ; 
  
  while(read(fd , &c , 1))
  {
    if(!(cpu_base_info._section ^ (c & 0xff))) 
    {
      cpu_base_info._nproc = -~(cpu_base_info._nproc) ; 
      cpu_base_info._section= ~0; /* ! force to reset  */
    }
    
    if(!((c & 0xff )^0xa))  
      cpu_base_info._section = 0xa ;
    else 
      cpu_base_info._section=~0; 

    cpu_base_info._size= -~(cpu_base_info._size) ; 
  } 

  return   (cpu_base_info._size << 8 |  cpu_base_info._nproc) ;  
}


void * get_cpu(const char * restrict search_term ) 
{
  int fd =~0 ; 
  fd^= open(PCPU  , O_RDONLY) ;
  if(!fd) 
    return (__ptr_t*)00; 

  fd =~fd ; 
  
  
  cpu_t summary =  cpu_overview(fd) ;  
  cpu_raw_info = (char *) malloc(sizeof(char) *  (summary >> 8) +1 ) ;
  if (!cpu_raw_info) 
  {
     close(fd) ; 
     return (__ptr_t*) 00; 
  } 

  size_t rb =~0 ; 
  rb ^=  read(fd,  cpu_raw_info ,  (summary >> 8)) ; 

  if (!rb)  
  {
    close(fd) ; 
    return  (__ptr_t *) -EIO ;  
  }
  
  rb=~(rb^1) ; 



  close(fd) ; 
}


static void  __dealloc(void) 
{
  if(!cpu_raw_info)  return ; 
  free(cpu_raw_info) ; 
  cpu_raw_info =(void *) 0 ; 
}

