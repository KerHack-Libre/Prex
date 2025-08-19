/**   
 * @file  execbn.h 
 * @brief Get executable basenames (short and long)    
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


#if !defined(exec_basename) 
#define exec_basename  

#if __glibc_has_attribute(constructor) 
# define __dtor  __attribute__((constructor)) 
#else 
# define __dtor /*!NOTHING */ 
#endif 

#define SELF "/proc/self/exe" 
#define PNAME_LEN  1024 
extern  char   
  * basename_short,  /*! This 'll git you the basename program only  */
  * basename_long ;  /*! This 'll give you  the basename  program including the full path with slashes  */ 

/** 
 * @file __getpbn(void) 
 * @brief  get program basename 
 */
static void __getpbn(void)  __attribute__((constructor)) ; 


#endif /*! exec_basename */ 
