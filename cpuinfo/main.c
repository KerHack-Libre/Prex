
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 

#include "cpuinfo.h" 


int main (int ac , char  **av ) 
{
  int pstatus = EXIT_SUCCESS ; 
  
  //!si je specifie  null  je dois tout afficher 
  get_cpu(NULL) ; 

_epilog: 
  return pstatus ; 
}
