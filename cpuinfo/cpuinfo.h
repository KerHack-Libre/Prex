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

#if !defined(__PROCPU_INFO_H)
#define  __PROCPU_INFO_H 

#ifdef  __cplusplus   
#define  PROC_CPUINFO  extern  "C" 
#else 
# define PROC_CPUINFO  /*  !NOTHING... */ 
#endif  /*__cplusplus  */ 


#define _Nullable 

#define PCPU  "/proc/cpuinfo"  

typedef struct __cpu_info_t  cpu_info_t ; 
struct __cpu_info_t  {
  char *_label ; 
  char *_descval;
};

typedef  unsigned int  cpu_t ;

//!Hold  all information  about cpu 
extern char * cpu_raw_info ; 
/** 
 * @fn ci_overview(int) 
 * @brief get overview  about cpuinfo  file
 * @param fd - file descriptor 
 * @return cpu_t - The first bits  has the size of file  
 *                 and the last  8 bits the nprocs 
 * */
static cpu_t ci_overview(int __fd)  ; 

PROC_CPUINFO void  * get_cpu(const char *restrict  _Nullable  __search_term) ;

/**
 * @brief deallocate   cpu_raw_info  at the end of the program 
 */ 

PROC_CPUINFO   static void  __dealloc(void) __attribute__((destructor)) ; 

#endif /* ! __PROCPU_INFO_H */
