/**   
 * @file  execbn.c  
 * @brief Get current executable basenames (short and long )  
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

#include <stdlib.h>
#include <unistd.h> 
#include "execbn.h"

char  *basename_short = (char *)0, 
      *basename_long  = (char *)0; 

static char execpath[PNAME_LEN] = {0} ; 

static void __getpbn(void)
{
   unsigned int self_fd = ~0 , 
                c =~0; 
   ssize_t rblnk =~0 ; 
   char  *slash=(char *)0; 

   rblnk^=readlink(SELF ,  execpath , PNAME_LEN) ; 

   basename_long = (char *)&execpath ; 
   
   while(*(execpath+(++c))) 
   { 
     if(!((*(execpath+c) & 0xff) ^ 0x2f))
       slash=(execpath+c);  
   } 
   
   basename_short= slash+1; 
  
}
