/**
 * Maps the kernel memory functions to the user space versions.
 **/
#ifndef _KMEM_H_
#define _KMEM_H_

#include <stdlib.h>
#include <string.h>

#define kmalloc(size, ...) malloc(size)
#define krealloc(ptr, size, ...) realloc(ptr, size)
#define kmemdup(ptr, size, ...) memdup(ptr, size)
#define kcalloc(n, size, ...) calloc(n, size)
#define kzalloc(ptr, size, ...) zalloc(size)
#define kfree(ptr, ...) free(ptr)

#define memchr_inv(s, c, n) memchr(s, c, n)

void* zalloc(size_t s);
void* memdup(const void* d, size_t s);

#endif
