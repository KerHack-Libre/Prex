/* @file  cpu.c  
 * @brief This file  collect information from  /proc/cpu
 * @author Umar Ba <jUmarB@protonmail.com>  
 */

#define _GNU_SOURCE 
#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/cdefs.h>
#include <sys/mman.h>
#include <err.h> 

#include "cpuinfo.h"

FILE *_stream  = (FILE *) 00 ; 

static cpu_t cpu_overview(int  fd ) 
{
  int nproc =0  ;
  size_t bytes= 0  , membuf_allocation =0 ;  
  char c = 0 , section=~0 ;  
  char *ptr ; 

  char buffer_alloc[5000] = { 0 } ; 
  _stream = fmemopen((void *) 0   ,5000, "r+") ;
  if(!_stream) 
    return ~0 ; 
  


  while(read(fd , &c ,1)) 
  {
     if(!(section ^ c)) 
       nproc=-~(nproc) ; 
    
     bytes=-~(bytes) ; 
    
     if (!(012 ^(c & 0xff)))
      section=012 ; 
     else 
       section=~0 ; 
  }

  return (bytes<<8) |  nproc ; 

}
void * get_cpu(const char * restrict search_term ) 
{
  int fd =~0 ; 
  fd ^=  open(PCPU , O_RDONLY); 
  if(!fd) 
    return (__ptr_t) 00 ; 

  fd=~fd;

  
  cpu_t cpu_resume =  cpu_overview(fd) ;

 


  close(fd) ;  
}
