#include "kmem.h"

void* zalloc(size_t s) {
   void* p = malloc(s);
   memset(p, 0, s);
   return p;
}

void* memdup(const void* d, size_t s) {
   void* p; 
   return ((p = malloc(s))?memcpy(p, d, s):NULL);
}
