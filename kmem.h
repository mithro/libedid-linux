/**
 * Maps the kernel memory functions to the user space versions.
 **/
#ifndef _KMEM_H_
#define _KMEM_H_

#include <stdlib.h>

#define kmalloc(size, ...) malloc(size)
#define krealloc(ptr, size, ...) realloc(ptr, size)
#define kmemdup(ptr, size, ...) memdup(ptr, size)

inline void* memdup(const void* d, size_t s) {
   void* p; 
   return ((p = malloc(s))?memcpy(p, d, s):NULL);
}

#endif
