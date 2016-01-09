/**
 * Maps the kernel printf style functions to the user space versions.
 **/
#ifndef _KPRINT_H_
#define _KPRINT_H_

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

#define printk(...) printf(__VA_ARGS__)
#define printk_once(...) printf(__VA_ARGS__)
#define no_printk(...)

#define dev_warn(dev, ...) printf("WARN: " __VA_ARGS__)

#define KERN_DEBUG "DEBUG: "
#define KERN_INFO "INFO: "
#define KERN_WARNING "WARN: "
#define KERN_ERR "ERR: "


#define drm_debug 1
#define DRM_UT_KMS 1

#define DRM_DEBUG_KMS(...) printf("DEBUG: " __VA_ARGS__)
#define DRM_DEBUG(...) printf("DEBUG: " __VA_ARGS__)

#define DRM_ERROR_KMS(...) printf("ERROR: " __VA_ARGS__)
#define DRM_ERROR(...) printf("ERROR: " __VA_ARGS__)

enum {
        DUMP_PREFIX_NONE,
        DUMP_PREFIX_ADDRESS,
        DUMP_PREFIX_OFFSET
};
extern int hex_dump_to_buffer(const void *buf, size_t len, int rowsize,
                              int groupsize, char *linebuf, size_t linebuflen,
                              bool ascii);
extern void print_hex_dump(const char *level, const char *prefix_str,
                           int prefix_type, int rowsize, int groupsize,
                           const void *buf, size_t len, bool ascii);
extern void print_hex_dump_bytes(const char *prefix_str, int prefix_type,
                                 const void *buf, size_t len);

#define print_hex_dump_debug(prefix_str, prefix_type, rowsize,          \
                             groupsize, buf, len, ascii)                \
        print_hex_dump(KERN_DEBUG, prefix_str, prefix_type, rowsize,    \
                       groupsize, buf, len, ascii)

#endif
