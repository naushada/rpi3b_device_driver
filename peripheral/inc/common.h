#ifndef __COMMON_H__
#define __COMMON_H__

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define SHIFT 0

#define GET_BITS(x, pos, bits)                       (~(~0U << (bits))) & ((x) >>  ((pos) - (bits) + 1))
#define CLR_BITS(x, pos, bits)                       (~(~(~0U << (bits)) << (((pos) - (bits) + 1))) & (x))
#define SET_BITS(x, pos, bits, value)                CLR_BITS((x), (pos), (bits)) | \
                                                              ((~(~0U << (bits))) & (value)) << ((pos) - (bits) + 1)

#define GET(device, register, x)                      device ## __ ## register ## _GET((x))
#define CLR(device, register, x)                      device ## __ ## register ## _CLR((x))
#define SET(device, register, x, value)               device ## __ ## register ## _SET((x),(value))

#define GET_ex(device, register, x, pos, bits)        device ## __ ## register ## _GET((x), (pos), (bits))
#define CLR_ex(device, register, x, pos, bits)        device ## __ ## register ## _CLR((x), (pos), (bits))
#define SET_ex(device, register, x, pos, bits, value) device ## __ ## register ## _SET((x), (pos), (bits), (value))

#define GET_exx(device, register, x, pos, bits)        device ## __ ## register ## _GET((x), (pos), (bits))
#define CLR_exx(device, register, x, pos, bits)        device ## __ ## register ## _CLR((x), (pos), (bits))
#define SET_exx(device, register, x, pos, bits, value) device ## __ ## register ## _SET((x), (pos), (bits), (value))

#endif /*__COMMON_H__*/
