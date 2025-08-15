/*
 * 
 *
 */
#if !defined(__PROCPU_INFO_H)
#define  __PROCPU_INFO_H 

#define _Nullable 

#define PCPU  "/proc/cpuinfo"  

typedef struct __cpu_info_t  cpu_info_t ; 
struct __cpu_info_t  {
  char *_label ; 
  char *_descval;
};

//!faire un linked list 

typedef  int  cpu_t ;  

/*!
 * 
 * */
void  *  get_cpu(const char *restrict  _Nullable  __search_term) ;
static cpu_t ci_overview(int __fd )  ; 


#endif /* ! __PROCPU_INFO_H */
