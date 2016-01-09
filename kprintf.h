/**
 * Maps the kernel printf style functions to the user space versions.
 **/
#ifndef _KPRINT_H_
#define _KPRINT_H_

#include <stdarg.h>
#include <stdio.h>

#define printk(...) printf(__VA_ARGS__)
#define dev_warn(dev, ...) printf("WARN: " __VA_ARGS__)

#define KERN_ERR "ERR: "
#define DUMP_PREFIX_NONE ""
#define drm_debug 1
#define DRM_UT_KMS 1

#endif
