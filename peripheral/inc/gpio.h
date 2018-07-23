#ifndef __GPIO_H__
#define __GPIO_H__

//#include <common.h>


/* @brief:
 *  Each 32bits register can accomodate 10 gpios FSEL, hence division by 10.
 *  gpios (0-9), (10-19), (20-29), (30-39), (40-49) and (50-53) will be 
 *  programmed in register FSEL0, FSEL1, FSEL2, FSEL3, FSEL4 and FSEL5 respectively.
 */
#define xSET_GPSELn(offset, register, x, value) SET((offset), (register), (x), (value)) 
#define SET_GPFSELn(x, offset, gpio, value) xSET_GPSELn(GPIO_GPFSEL ## offset, \
                                                FSEL ## gpio, (x), (value))

#define GET_GPFSELn(gpio) xGET_GPFSELn(GPIO_GPFSEL ## gpio)
#define xGET_GPFSELn(offset) gpio_read(offset)

/* @brief:
 *  Each 32bits register can accomodate 32 gpios GPCLR, hence division by 32.
 *  gpios (0-31), (32-54), will be 
 *  programmed in register GPCLR0 + (GPIO0-GPIO31) and GPCLR1 + (GPIO32-GPIO54) bitmap respectively.
 */
#define GET_GPCLRn(gpio) xGET_GPCLRn(GPIO_CLR ## ((unsigned int)gpio >> 5))
#define xGET_GPCLRn(offset) gpio_read(offset)

#define xSET_GPCLRn(offset, register, x, value) SET((offset), (register), (x), (value)) 
#define SET_GPCLRn(x, gpio, value) xSET_GPCLRn((GPIO_GPCLR ## ((unsigned int)gpio >> 5), \
                                               (GPIO ## ((unsigned int)gpio & 31), \
                                               (x), (value))

#define GET_GPLEVn(gpio) xGET_GPLEVn(GPIO_LEV ## ((unsigned int)gpio >> 5))
#define xGET_GPLEVn(offset) gpio_read(offset)

#define xSET_GPLEVn(offset, register, x, value) SET((offset), (register), (x), (value)) 
#define SET_GPLEVn(x, gpio, value) xSET_GPLEVn((GPIO_GPLEV ## ((unsigned int)gpio >> 5), \
                                               (GPIO ## ((unsigned int)gpio & 31), \
                                               (x), (value))
/* @brief: Refister's offset
 *
 */
#define GPIO_GPFSEL0               (0x00 >> SHIFT)
#define GPIO_GPFSEL1               (0x04 >> SHIFT)
#define GPIO_GPFSEL2               (0x08 >> SHIFT)
#define GPIO_GPFSEL3               (0x0C >> SHIFT)
#define GPIO_GPFSEL4               (0x10 >> SHIFT)
#define GPIO_GPFSEL5               (0x14 >> SHIFT)

#define GPIO_GPSET0                (0x1C >> SHIFT)
#define GPIO_GPSET1                (0x20 >> SHIFT)
/*Reserved*/
#define GPIO_GPSET2                (0x24 >> SHIFT)

/*GPIO CLREAR REGISTER*/
#define GPIO_GPCLR0                (0x28 >> SHIFT)
#define GPIO_GPCLR1                (0x2C >> SHIFT)
/*Reserved*/
#define GPIO_GPCLR2                (0x30 >> SHIFT)

/*LEV{n} setting of GPIO*/
#define GPIO_GPLEV0                (0x34 >> SHIFT)
#define GPIO_GPLEV1                (0x38 >> SHIFT)
/*It's reserved*/
#define GPIO_GPLEV2                (0x3C >> SHIFT)

#define GPIO_GPEDS0                (0x40 >> SHIFT)
#define GPIO_GPEDS1                (0x44 >> SHIFT)
#define GPIO_GPEDS2                (0x48 >> SHIFT)

#define GPIO_GPREN0                (0x4C >> SHIFT)
#define GPIO_GPREN1                (0x50 >> SHIFT)
#define GPIO_GPREN2                (0x54 >> SHIFT)

#define GPIO_GPFEN0                (0x58 >> SHIFT)
#define GPIO_GPFEN1                (0x5C >> SHIFT)
#define GPIO_GPFEN2                (0x60 >> SHIFT)

#define GPIO_GPHEN0                (0x64 >> SHIFT)
#define GPIO_GPHEN1                (0x68 >> SHIFT)
#define GPIO_GPHEN2                (0x6C >> SHIFT)


#define GPIO_GPLEN0                (0x70 >> SHIFT)
#define GPIO_GPLEN1                (0x74 >> SHIFT)
#define GPIO_GPLEN2                (0x78 >> SHIFT)

#define GPIO_GPAREN0               (0x7C >> SHIFT)
#define GPIO_GPAREN1               (0x80 >> SHIFT)
#define GPIO_GPAREN2               (0x84 >> SHIFT)

#define GPIO_GPAFEN0               (0x88 >> SHIFT)
#define GPIO_GPAFEN1               (0x8C >> SHIFT)
#define GPIO_GPAFEN2               (0x90 >> SHIFT)

#define GPIO_GPPUD                 (0x94 >> SHIFT)
#define GPIO_GPPUDCLK0             (0x98 >> SHIFT)
#define GPIO_GPPUDCLK1             (0x9C >> SHIFT)

/* GPIO's Registers details
 * The FSEL{n} field determines the functionality of the nth GPIO pin
 */
#define GPIO_GPFSEL0__FSEL9_GET(x)        GET_BITS((x), (29), (3)) 
#define GPIO_GPFSEL0__FSEL9_SET(x, value) SET_BITS((x), (29), (3), (value))
#define GPIO_GPFSEL0__FSEL9_CLR(x)        CLR_BITS((x), (29), (3))

#define GPIO_GPFSEL0__FSEL8_GET(x)        GET_BITS((x), (26), (3)) 
#define GPIO_GPFSEL0__FSEL8_SET(x, value) SET_BITS((x), (26), (3), (value))
#define GPIO_GPFSEL0__FSEL8_CLR(x)        CLR_BITS((x), (26), (3))

#define GPIO_GPFSEL0__FSEL7_GET(x)        GET_BITS((x), (23), (3)) 
#define GPIO_GPFSEL0__FSEL7_SET(x, value) SET_BITS((x), (23), (3), (value))
#define GPIO_GPFSEL0__FSEL7_CLR(x)        CLR_BITS((x), (23), (3))

#define GPIO_GPFSEL0__FSEL6_GET(x)        GET_BITS((x), (20), (3)) 
#define GPIO_GPFSEL0__FSEL6_SET(x, value) SET_BITS((x), (20), (3), (value))
#define GPIO_GPFSEL0__FSEL6_CLR(x)        CLR_BITS((x), (20), (3))

#define GPIO_GPFSEL0__FSEL5_GET(x)        GET_BITS((x), (17), (3)) 
#define GPIO_GPFSEL0__FSEL5_SET(x, value) SET_BITS((x), (17), (3), (value))
#define GPIO_GPFSEL0__FSEL5_CLR(x)        CLR_BITS((x), (17), (3))

#define GPIO_GPFSEL0__FSEL4_GET(x)        GET_BITS((x), (14), (3)) 
#define GPIO_GPFSEL0__FSEL4_SET(x, value) SET_BITS((x), (14), (3), (value))
#define GPIO_GPFSEL0__FSEL4_CLR(x)        CLR_BITS((x), (14), (3))

#define GPIO_GPFSEL0__FSEL3_GET(x)        GET_BITS((x), (11), (3)) 
#define GPIO_GPFSEL0__FSEL3_SET(x, value) SET_BITS((x), (11), (3), (value))
#define GPIO_GPFSEL0__FSEL3_CLR(x)        CLR_BITS((x), (11), (3))

#define GPIO_GPFSEL0__FSEL2_GET(x)        GET_BITS((x), (8), (3)) 
#define GPIO_GPFSEL0__FSEL2_SET(x, value) SET_BITS((x), (8), (3), (value))
#define GPIO_GPFSEL0__FSEL2_CLR(x)        CLR_BITS((x), (8), (3))

#define GPIO_GPFSEL0__FSEL1_GET(x)        GET_BITS((x), (5), (3)) 
#define GPIO_GPFSEL0__FSEL1_SET(x, value) SET_BITS((x), (5), (3), (value))
#define GPIO_GPFSEL0__FSEL1_CLR(x)        CLR_BITS((x), (5), (3))

#define GPIO_GPFSEL0__FSEL0_GET(x)        GET_BITS((x), (2), (3)) 
#define GPIO_GPFSEL0__FSEL0_SET(x, value) SET_BITS((x), (2), (3), (value))
#define GPIO_GPFSEL0__FSEL0_CLR(x)        CLR_BITS((x), (2), (3))

/*GPIO Pin 10th onwards*/
#define GPIO_GPFSEL1__FSEL19_GET(x)        GET_BITS((x), (29), (3)) 
#define GPIO_GPFSEL1__FSEL19_SET(x, value) SET_BITS((x), (29), (3), (value))
#define GPIO_GPFSEL1__FSEL19_CLR(x)        CLR_BITS((x), (29), (3))

#define GPIO_GPFSEL1__FSEL18_GET(x)        GET_BITS((x), (26), (3)) 
#define GPIO_GPFSEL1__FSEL18_SET(x, value) SET_BITS((x), (26), (3), (value))
#define GPIO_GPFSEL1__FSEL18_CLR(x)        CLR_BITS((x), (26), (3))

#define GPIO_GPFSEL1__FSEL17_GET(x)        GET_BITS((x), (23), (3)) 
#define GPIO_GPFSEL1__FSEL17_SET(x, value) SET_BITS((x), (23), (3), (value))
#define GPIO_GPFSEL1__FSEL17_CLR(x)        CLR_BITS((x), (23), (3))

#define GPIO_GPFSEL1__FSEL16_GET(x)        GET_BITS((x), (20), (3)) 
#define GPIO_GPFSEL1__FSEL16_SET(x, value) SET_BITS((x), (20), (3), (value))
#define GPIO_GPFSEL1__FSEL16_CLR(x)        CLR_BITS((x), (20), (3))

#define GPIO_GPFSEL1__FSEL15_GET(x)        GET_BITS((x), (17), (3)) 
#define GPIO_GPFSEL1__FSEL15_SET(x, value) SET_BITS((x), (17), (3), (value))
#define GPIO_GPFSEL1__FSEL15_CLR(x)        CLR_BITS((x), (17), (3))

#define GPIO_GPFSEL1__FSEL14_GET(x)        GET_BITS((x), (14), (3)) 
#define GPIO_GPFSEL1__FSEL14_SET(x, value) SET_BITS((x), (14), (3), (value))
#define GPIO_GPFSEL1__FSEL14_CLR(x)        CLR_BITS((x), (14), (3))

#define GPIO_GPFSEL1__FSEL13_GET(x)        GET_BITS((x), (11), (3)) 
#define GPIO_GPFSEL1__FSEL13_SET(x, value) SET_BITS((x), (11), (3), (value))
#define GPIO_GPFSEL1__FSEL13_CLR(x)        CLR_BITS((x), (11), (3))

#define GPIO_GPFSEL1__FSEL12_GET(x)        GET_BITS((x), (8), (3)) 
#define GPIO_GPFSEL1__FSEL12_SET(x, value) SET_BITS((x), (8), (3), (value))
#define GPIO_GPFSEL1__FSEL12_CLR(x)        CLR_BITS((x), (8), (3))

#define GPIO_GPFSEL1__FSEL11_GET(x)        GET_BITS((x), (5), (3)) 
#define GPIO_GPFSEL1__FSEL11_SET(x, value) SET_BITS((x), (5), (3), (value))
#define GPIO_GPFSEL1__FSEL11_CLR(x)        CLR_BITS((x), (5), (3))

#define GPIO_GPFSEL1__FSEL10_GET(x)        GET_BITS((x), (2), (3)) 
#define GPIO_GPFSEL1__FSEL10_SET(x, value) SET_BITS((x), (2), (3), (value))
#define GPIO_GPFSEL1__FSEL10_CLR(x)        CLR_BITS((x), (2), (3))

/*GPIO Pin 20th onwards*/
#define GPIO_GPFSEL2__FSEL29_GET(x)        GET_BITS((x), (29), (3)) 
#define GPIO_GPFSEL2__FSEL29_SET(x, value) SET_BITS((x), (29), (3), (value))
#define GPIO_GPFSEL2__FSEL29_CLR(x)        CLR_BITS((x), (29), (3))

#define GPIO_GPFSEL2__FSEL28_GET(x)        GET_BITS((x), (26), (3)) 
#define GPIO_GPFSEL2__FSEL28_SET(x, value) SET_BITS((x), (26), (3), (value))
#define GPIO_GPFSEL2__FSEL28_CLR(x)        CLR_BITS((x), (26), (3))

#define GPIO_GPFSEL2__FSEL27_GET(x)        GET_BITS((x), (23), (3)) 
#define GPIO_GPFSEL2__FSEL27_SET(x, value) SET_BITS((x), (23), (3), (value))
#define GPIO_GPFSEL2__FSEL27_CLR(x)        CLR_BITS((x), (23), (3))

#define GPIO_GPFSEL2__FSEL26_GET(x)        GET_BITS((x), (20), (3)) 
#define GPIO_GPFSEL2__FSEL26_SET(x, value) SET_BITS((x), (20), (3), (value))
#define GPIO_GPFSEL2__FSEL26_CLR(x)        CLR_BITS((x), (20), (3))

#define GPIO_GPFSEL2__FSEL25_GET(x)        GET_BITS((x), (17), (3)) 
#define GPIO_GPFSEL2__FSEL25_SET(x, value) SET_BITS((x), (17), (3), (value))
#define GPIO_GPFSEL2__FSEL25_CLR(x)        CLR_BITS((x), (17), (3))

#define GPIO_GPFSEL2__FSEL24_GET(x)        GET_BITS((x), (14), (3)) 
#define GPIO_GPFSEL2__FSEL24_SET(x, value) SET_BITS((x), (14), (3), (value))
#define GPIO_GPFSEL2__FSEL24_CLR(x)        CLR_BITS((x), (14), (3))

#define GPIO_GPFSEL2__FSEL23_GET(x)        GET_BITS((x), (11), (3)) 
#define GPIO_GPFSEL2__FSEL23_SET(x, value) SET_BITS((x), (11), (3), (value))
#define GPIO_GPFSEL2__FSEL23_CLR(x)        CLR_BITS((x), (11), (3))

#define GPIO_GPFSEL2__FSEL22_GET(x)        GET_BITS((x), (8), (3)) 
#define GPIO_GPFSEL2__FSEL22_SET(x, value) SET_BITS((x), (8), (3), (value))
#define GPIO_GPFSEL2__FSEL22_CLR(x)        CLR_BITS((x), (8), (3))

#define GPIO_GPFSEL2__FSEL21_GET(x)        GET_BITS((x), (5), (3)) 
#define GPIO_GPFSEL2__FSEL21_SET(x, value) SET_BITS((x), (5), (3), (value))
#define GPIO_GPFSEL2__FSEL21_CLR(x)        CLR_BITS((x), (5), (3))

#define GPIO_GPFSEL2__FSEL20_GET(x)        GET_BITS((x), (2), (3)) 
#define GPIO_GPFSEL2__FSEL20_SET(x, value) SET_BITS((x), (2), (3), (value))
#define GPIO_GPFSEL2__FSEL20_CLR(x)        CLR_BITS((x), (2), (3))

/*GPIO Pin 30th onwards*/
#define GPIO_GPFSEL3__FSEL39_GET(x)        GET_BITS((x), (29), (3)) 
#define GPIO_GPFSEL3__FSEL39_SET(x, value) SET_BITS((x), (29), (3), (value))
#define GPIO_GPFSEL3__FSEL39_CLR(x)        CLR_BITS((x), (29), (3))

#define GPIO_GPFSEL3__FSEL38_GET(x)        GET_BITS((x), (26), (3)) 
#define GPIO_GPFSEL3__FSEL38_SET(x, value) SET_BITS((x), (26), (3), (value))
#define GPIO_GPFSEL3__FSEL38_CLR(x)        CLR_BITS((x), (26), (3))

#define GPIO_GPFSEL3__FSEL37_GET(x)        GET_BITS((x), (23), (3)) 
#define GPIO_GPFSEL3__FSEL37_SET(x, value) SET_BITS((x), (23), (3), (value))
#define GPIO_GPFSEL3__FSEL37_CLR(x)        CLR_BITS((x), (23), (3))

#define GPIO_GPFSEL3__FSEL36_GET(x)        GET_BITS((x), (20), (3)) 
#define GPIO_GPFSEL3__FSEL36_SET(x, value) SET_BITS((x), (20), (3), (value))
#define GPIO_GPFSEL3__FSEL36_CLR(x)        CLR_BITS((x), (20), (3))

#define GPIO_GPFSEL3__FSEL35_GET(x)        GET_BITS((x), (17), (3)) 
#define GPIO_GPFSEL3__FSEL35_SET(x, value) SET_BITS((x), (17), (3), (value))
#define GPIO_GPFSEL3__FSEL35_CLR(x)        CLR_BITS((x), (17), (3))

#define GPIO_GPFSEL3__FSEL34_GET(x)        GET_BITS((x), (14), (3)) 
#define GPIO_GPFSEL3__FSEL34_SET(x, value) SET_BITS((x), (14), (3), (value))
#define GPIO_GPFSEL3__FSEL34_CLR(x)        CLR_BITS((x), (14), (3))

#define GPIO_GPFSEL3__FSEL33_GET(x)        GET_BITS((x), (11), (3)) 
#define GPIO_GPFSEL3__FSEL33_SET(x, value) SET_BITS((x), (11), (3), (value))
#define GPIO_GPFSEL3__FSEL33_CLR(x)        CLR_BITS((x), (11), (3))

#define GPIO_GPFSEL3__FSEL32_GET(x)        GET_BITS((x), (8), (3)) 
#define GPIO_GPFSEL3__FSEL32_SET(x, value) SET_BITS((x), (8), (3), (value))
#define GPIO_GPFSEL3__FSEL32_CLR(x)        CLR_BITS((x), (8), (3))

#define GPIO_GPFSEL3__FSEL31_GET(x)        GET_BITS((x), (5), (3)) 
#define GPIO_GPFSEL3__FSEL31_SET(x, value) SET_BITS((x), (5), (3), (value))
#define GPIO_GPFSEL3__FSEL31_CLR(x)        CLR_BITS((x), (5), (3))

#define GPIO_GPFSEL3__FSEL30_GET(x)        GET_BITS((x), (2), (3)) 
#define GPIO_GPFSEL3__FSEL30_SET(x, value) SET_BITS((x), (2), (3), (value))
#define GPIO_GPFSEL3__FSEL30_CLR(x)        CLR_BITS((x), (2), (3))

/*GPIO Pin 40th onwards*/
#define GPIO_GPFSEL4__FSEL49_GET(x)        GET_BITS((x), (29), (3)) 
#define GPIO_GPFSEL4__FSEL49_SET(x, value) SET_BITS((x), (29), (3), (value))
#define GPIO_GPFSEL4__FSEL49_CLR(x)        CLR_BITS((x), (29), (3))

#define GPIO_GPFSEL4__FSEL48_GET(x)        GET_BITS((x), (26), (3)) 
#define GPIO_GPFSEL4__FSEL48_SET(x, value) SET_BITS((x), (26), (3), (value))
#define GPIO_GPFSEL4__FSEL48_CLR(x)        CLR_BITS((x), (26), (3))

#define GPIO_GPFSEL4__FSEL47_GET(x)        GET_BITS((x), (23), (3)) 
#define GPIO_GPFSEL4__FSEL47_SET(x, value) SET_BITS((x), (23), (3), (value))
#define GPIO_GPFSEL4__FSEL47_CLR(x)        CLR_BITS((x), (23), (3))

#define GPIO_GPFSEL4__FSEL46_GET(x)        GET_BITS((x), (20), (3)) 
#define GPIO_GPFSEL4__FSEL46_SET(x, value) SET_BITS((x), (20), (3), (value))
#define GPIO_GPFSEL4__FSEL46_CLR(x)        CLR_BITS((x), (20), (3))

#define GPIO_GPFSEL4__FSEL45_GET(x)        GET_BITS((x), (17), (3)) 
#define GPIO_GPFSEL4__FSEL45_SET(x, value) SET_BITS((x), (17), (3), (value))
#define GPIO_GPFSEL4__FSEL45_CLR(x)        CLR_BITS((x), (17), (3))

#define GPIO_GPFSEL4__FSEL44_GET(x)        GET_BITS((x), (14), (3)) 
#define GPIO_GPFSEL4__FSEL44_SET(x, value) SET_BITS((x), (14), (3), (value))
#define GPIO_GPFSEL4__FSEL44_CLR(x)        CLR_BITS((x), (14), (3))

#define GPIO_GPFSEL4__FSEL43_GET(x)        GET_BITS((x), (11), (3)) 
#define GPIO_GPFSEL4__FSEL43_SET(x, value) SET_BITS((x), (11), (3), (value))
#define GPIO_GPFSEL4__FSEL43_CLR(x)        CLR_BITS((x), (11), (3))

#define GPIO_GPFSEL4__FSEL42_GET(x)        GET_BITS((x), (8), (3)) 
#define GPIO_GPFSEL4__FSEL42_SET(x, value) SET_BITS((x), (8), (3), (value))
#define GPIO_GPFSEL4__FSEL42_CLR(x)        CLR_BITS((x), (8), (3))

#define GPIO_GPFSEL4__FSEL41_GET(x)        GET_BITS((x), (5), (3)) 
#define GPIO_GPFSEL4__FSEL41_SET(x, value) SET_BITS((x), (5), (3), (value))
#define GPIO_GPFSEL4__FSEL41_CLR(x)        CLR_BITS((x), (5), (3))

#define GPIO_GPFSEL4__FSEL40_GET(x)        GET_BITS((x), (2), (3)) 
#define GPIO_GPFSEL4__FSEL40_SET(x, value) SET_BITS((x), (2), (3), (value))
#define GPIO_GPFSEL4__FSEL40_CLR(x)        CLR_BITS((x), (2), (3))

/*GPIO Pin 50th onwards*/
#define GPIO_GPFSEL5__FSEL59_GET(x)        GET_BITS((x), (29), (3)) 
#define GPIO_GPFSEL5__FSEL59_SET(x, value) SET_BITS((x), (29), (3), (value))
#define GPIO_GPFSEL5__FSEL59_CLR(x)        CLR_BITS((x), (29), (3))

#define GPIO_GPFSEL5__FSEL58_GET(x)        GET_BITS((x), (26), (3)) 
#define GPIO_GPFSEL5__FSEL58_SET(x, value) SET_BITS((x), (26), (3), (value))
#define GPIO_GPFSEL5__FSEL58_CLR(x)        CLR_BITS((x), (26), (3))

#define GPIO_GPFSEL5__FSEL57_GET(x)        GET_BITS((x), (23), (3)) 
#define GPIO_GPFSEL5__FSEL57_SET(x, value) SET_BITS((x), (23), (3), (value))
#define GPIO_GPFSEL5__FSEL57_CLR(x)        CLR_BITS((x), (23), (3))

#define GPIO_GPFSEL5__FSEL56_GET(x)        GET_BITS((x), (20), (3)) 
#define GPIO_GPFSEL5__FSEL56_SET(x, value) SET_BITS((x), (20), (3), (value))
#define GPIO_GPFSEL5__FSEL56_CLR(x)        CLR_BITS((x), (20), (3))

#define GPIO_GPFSEL5__FSEL55_GET(x)        GET_BITS((x), (17), (3)) 
#define GPIO_GPFSEL5__FSEL55_SET(x, value) SET_BITS((x), (17), (3), (value))
#define GPIO_GPFSEL5__FSEL55_CLR(x)        CLR_BITS((x), (17), (3))

#define GPIO_GPFSEL5__FSEL54_GET(x)        GET_BITS((x), (14), (3)) 
#define GPIO_GPFSEL5__FSEL54_SET(x, value) SET_BITS((x), (14), (3), (value))
#define GPIO_GPFSEL5__FSEL54_CLR(x)        CLR_BITS((x), (14), (3))

#define GPIO_GPFSEL5__FSEL53_GET(x)        GET_BITS((x), (11), (3)) 
#define GPIO_GPFSEL5__FSEL53_SET(x, value) SET_BITS((x), (11), (3), (value))
#define GPIO_GPFSEL5__FSEL53_CLR(x)        CLR_BITS((x), (11), (3))

#define GPIO_GPFSEL5__FSEL52_GET(x)        GET_BITS((x), (8), (3)) 
#define GPIO_GPFSEL5__FSEL52_SET(x, value) SET_BITS((x), (8), (3), (value))
#define GPIO_GPFSEL5__FSEL52_CLR(x)        CLR_BITS((x), (8), (3))

#define GPIO_GPFSEL5__FSEL51_GET(x)        GET_BITS((x), (5), (3)) 
#define GPIO_GPFSEL5__FSEL51_SET(x, value) SET_BITS((x), (5), (3), (value))
#define GPIO_GPFSEL5__FSEL51_CLR(x)        CLR_BITS((x), (5), (3))

#define GPIO_GPFSEL5__FSEL50_GET(x)        GET_BITS((x), (2), (3)) 
#define GPIO_GPFSEL5__FSEL50_SET(x, value) SET_BITS((x), (2), (3), (value))
#define GPIO_GPFSEL5__FSEL50_CLR(x)        CLR_BITS((x), (2), (3))

/*Reserved named as GPFSEL6*/
#define GPFSEL6               (0x18 >> SHIFT)

/*Setting GPIO as OUTPUT GPIO 0-31*/
#define GPIO_GPSET0__GPIO0_OUT_GET(x)        GET_BITS((x), (0), (1)) 
#define GPIO_GPSET0__GPIO0_OUT_SET(x)        SET_BITS((x), (0), (1), (1))
#define GPIO_GPSET0__GPIO0_OUT_CLR(x)        CLR_BITS((x), (0), (1))

#define GPIO_GPSET0__GPIO1_OUT_GET(x)        GET_BITS((x), (1), (1)) 
#define GPIO_GPSET0__GPIO1_OUT_SET(x)        SET_BITS((x), (1), (1), (1))
#define GPIO_GPSET0__GPIO1_OUT_CLR(x)        CLR_BITS((x), (1), (1))

#define GPIO_GPSET0__GPIO2_OUT_GET(x)        GET_BITS((x), (2), (1)) 
#define GPIO_GPSET0__GPIO2_OUT_SET(x)        SET_BITS((x), (2), (1), (1))
#define GPIO_GPSET0__GPIO2_OUT_CLR(x)        CLR_BITS((x), (2), (1))

#define GPIO_GPSET0__GPIO3_OUT_GET(x)        GET_BITS((x), (3), (1)) 
#define GPIO_GPSET0__GPIO3_OUT_SET(x)        SET_BITS((x), (3), (1), (1))
#define GPIO_GPSET0__GPIO3_OUT_CLR(x)        CLR_BITS((x), (3), (1))

#define GPIO_GPSET0__GPIO4_OUT_GET(x)        GET_BITS((x), (4), (1)) 
#define GPIO_GPSET0__GPIO4_OUT_SET(x)        SET_BITS((x), (4), (1), (1))
#define GPIO_GPSET0__GPIO4_OUT_CLR(x)        CLR_BITS((x), (4), (1))

#define GPIO_GPSET0__GPIO5_OUT_GET(x)        GET_BITS((x), (5), (1)) 
#define GPIO_GPSET0__GPIO5_OUT_SET(x)        SET_BITS((x), (5), (1), (1))
#define GPIO_GPSET0__GPIO5_OUT_CLR(x)        CLR_BITS((x), (5), (1))

#define GPIO_GPSET0__GPIO6_OUT_GET(x)        GET_BITS((x), (6), (1)) 
#define GPIO_GPSET0__GPIO6_OUT_SET(x)        SET_BITS((x), (6), (1), (1))
#define GPIO_GPSET0__GPIO6_OUT_CLR(x)        CLR_BITS((x), (6), (1))

#define GPIO_GPSET0__GPIO7_OUT_GET(x)        GET_BITS((x), (7), (1)) 
#define GPIO_GPSET0__GPIO7_OUT_SET(x)        SET_BITS((x), (7), (1), (1))
#define GPIO_GPSET0__GPIO7_OUT_CLR(x)        CLR_BITS((x), (7), (1))

#define GPIO_GPSET0__GPIO8_OUT_GET(x)        GET_BITS((x), (8), (1)) 
#define GPIO_GPSET0__GPIO8_OUT_SET(x)        SET_BITS((x), (8), (1), (1))
#define GPIO_GPSET0__GPIO8_OUT_CLR(x)        CLR_BITS((x), (8), (1))

#define GPIO_GPSET0__GPIO9_OUT_GET(x)        GET_BITS((x), (9), (1)) 
#define GPIO_GPSET0__GPIO9_OUT_SET(x)        SET_BITS((x), (9), (1), (1))
#define GPIO_GPSET0__GPIO9_OUT_CLR(x)        CLR_BITS((x), (9), (1))

#define GPIO_GPSET0__GPIO10_OUT_GET(x)        GET_BITS((x), (10), (1)) 
#define GPIO_GPSET0__GPIO10_OUT_SET(x)        SET_BITS((x), (10), (1), (1))
#define GPIO_GPSET0__GPIO10_OUT_CLR(x)        CLR_BITS((x), (10), (1))

#define GPIO_GPSET0__GPIO11_OUT_GET(x)        GET_BITS((x), (11), (1)) 
#define GPIO_GPSET0__GPIO11_OUT_SET(x)        SET_BITS((x), (11), (1), (1))
#define GPIO_GPSET0__GPIO11_OUT_CLR(x)        CLR_BITS((x), (11), (1))

#define GPIO_GPSET0__GPIO12_OUT_GET(x)        GET_BITS((x), (12), (1)) 
#define GPIO_GPSET0__GPIO12_OUT_SET(x)        SET_BITS((x), (12), (1), (1))
#define GPIO_GPSET0__GPIO12_OUT_CLR(x)        CLR_BITS((x), (12), (1))

#define GPIO_GPSET0__GPIO13_OUT_GET(x)        GET_BITS((x), (13), (1)) 
#define GPIO_GPSET0__GPIO13_OUT_SET(x)        SET_BITS((x), (13), (1), (1))
#define GPIO_GPSET0__GPIO13_OUT_CLR(x)        CLR_BITS((x), (13), (1))

#define GPIO_GPSET0__GPIO14_OUT_GET(x)        GET_BITS((x), (14), (1)) 
#define GPIO_GPSET0__GPIO14_OUT_SET(x)        SET_BITS((x), (14, (1), (1))
#define GPIO_GPSET0__GPIO14_OUT_CLR(x)        CLR_BITS((x), (14), (1))

#define GPIO_GPSET0__GPIO15_OUT_GET(x)        GET_BITS((x), (15), (1)) 
#define GPIO_GPSET0__GPIO15_OUT_SET(x)        SET_BITS((x), (15), (1), (1))
#define GPIO_GPSET0__GPIO15_OUT_CLR(x)        CLR_BITS((x), (15), (1))

#define GPIO_GPSET0__GPIO16_OUT_GET(x)        GET_BITS((x), (16), (1)) 
#define GPIO_GPSET0__GPIO16_OUT_SET(x)        SET_BITS((x), (16), (1), (1))
#define GPIO_GPSET0__GPIO16_OUT_CLR(x)        CLR_BITS((x), (16), (1))

#define GPIO_GPSET0__GPIO17_OUT_GET(x)        GET_BITS((x), (17), (1)) 
#define GPIO_GPSET0__GPIO17_OUT_SET(x)        SET_BITS((x), (17), (1), (1))
#define GPIO_GPSET0__GPIO17_OUT_CLR(x)        CLR_BITS((x), (17), (1))

#define GPIO_GPSET0__GPIO18_OUT_GET(x)        GET_BITS((x), (18), (1)) 
#define GPIO_GPSET0__GPIO18_OUT_SET(x)        SET_BITS((x), (18), (1), (1))
#define GPIO_GPSET0__GPIO18_OUT_CLR(x)        CLR_BITS((x), (18), (1))

#define GPIO_GPSET0__GPIO19_OUT_GET(x)        GET_BITS((x), (19), (1)) 
#define GPIO_GPSET0__GPIO19_OUT_SET(x)        SET_BITS((x), (19), (1), (1))
#define GPIO_GPSET0__GPIO19_OUT_CLR(x)        CLR_BITS((x), (19), (1))

#define GPIO_GPSET0__GPIO20_OUT_GET(x)        GET_BITS((x), (20), (1)) 
#define GPIO_GPSET0__GPIO20_OUT_SET(x)        SET_BITS((x), (20), (1), (1))
#define GPIO_GPSET0__GPIO20_OUT_CLR(x)        CLR_BITS((x), (20), (1))

#define GPIO_GPSET0__GPIO21_OUT_GET(x)        GET_BITS((x), (21), (1)) 
#define GPIO_GPSET0__GPIO21_OUT_SET(x)        SET_BITS((x), (21), (1), (1))
#define GPIO_GPSET0__GPIO21_OUT_CLR(x)        CLR_BITS((x), (21), (1))

#define GPIO_GPSET0__GPIO22_OUT_GET(x)        GET_BITS((x), (22), (1)) 
#define GPIO_GPSET0__GPIO22_OUT_SET(x)        SET_BITS((x), (22), (1), (1))
#define GPIO_GPSET0__GPIO22_OUT_CLR(x)        CLR_BITS((x), (22), (1))

#define GPIO_GPSET0__GPIO23_OUT_GET(x)        GET_BITS((x), (23), (1)) 
#define GPIO_GPSET0__GPIO23_OUT_SET(x)        SET_BITS((x), (23), (1), (1))
#define GPIO_GPSET0__GPIO23_OUT_CLR(x)        CLR_BITS((x), (23), (1))

#define GPIO_GPSET0__GPIO24_OUT_GET(x)        GET_BITS((x), (24), (1)) 
#define GPIO_GPSET0__GPIO24_OUT_SET(x)        SET_BITS((x), (24), (1), (1))
#define GPIO_GPSET0__GPIO24_OUT_CLR(x)        CLR_BITS((x), (24), (1))

#define GPIO_GPSET0__GPIO25_OUT_GET(x)        GET_BITS((x), (25), (1)) 
#define GPIO_GPSET0__GPIO25_OUT_SET(x)        SET_BITS((x), (25), (1), (1))
#define GPIO_GPSET0__GPIO25_OUT_CLR(x)        CLR_BITS((x), (25), (1))

#define GPIO_GPSET0__GPIO26_OUT_GET(x)        GET_BITS((x), (26), (1)) 
#define GPIO_GPSET0__GPIO26_OUT_SET(x)        SET_BITS((x), (26), (1), (1))
#define GPIO_GPSET0__GPIO26_OUT_CLR(x)        CLR_BITS((x), (26), (1))

#define GPIO_GPSET0__GPIO27_OUT_GET(x)        GET_BITS((x), (27), (1)) 
#define GPIO_GPSET0__GPIO27_OUT_SET(x)        SET_BITS((x), (27), (1), (1))
#define GPIO_GPSET0__GPIO27_OUT_CLR(x)        CLR_BITS((x), (27), (1))

#define GPIO_GPSET0__GPIO28_OUT_GET(x)        GET_BITS((x), (28), (1)) 
#define GPIO_GPSET0__GPIO28_OUT_SET(x)        SET_BITS((x), (28), (1), (1))
#define GPIO_GPSET0__GPIO28_OUT_CLR(x)        CLR_BITS((x), (28), (1))

#define GPIO_GPSET0__GPIO29_OUT_GET(x)        GET_BITS((x), (29), (1)) 
#define GPIO_GPSET0__GPIO29_OUT_SET(x)        SET_BITS((x), (29), (1), (1))
#define GPIO_GPSET0__GPIO29_OUT_CLR(x)        CLR_BITS((x), (29), (1))

#define GPIO_GPSET0__GPIO30_OUT_GET(x)        GET_BITS((x), (30), (1)) 
#define GPIO_GPSET0__GPIO30_OUT_SET(x)        SET_BITS((x), (30), (1), (1))
#define GPIO_GPSET0__GPIO30_OUT_CLR(x)        CLR_BITS((x), (30), (1))

#define GPIO_GPSET0__GPIO31_OUT_GET(x)        GET_BITS((x), (31), (1)) 
#define GPIO_GPSET0__GPIO31_OUT_SET(x)        SET_BITS((x), (31), (1), (1))
#define GPIO_GPSET0__GPIO31_OUT_CLR(x)        CLR_BITS((x), (31), (1))

/*Setting GPIO as OUTPUT for GPIO 32-53*/
#define GPIO_GPSET1__GPIO32_OUT_GET(x)        GET_BITS((x), (0), (1)) 
#define GPIO_GPSET1__GPIO32_OUT_SET(x)        SET_BITS((x), (0), (1), (1))
#define GPIO_GPSET1__GPIO32_OUT_CLR(x)        CLR_BITS((x), (0), (1))

#define GPIO_GPSET1__GPIO33_OUT_GET(x)        GET_BITS((x), (1), (1)) 
#define GPIO_GPSET1__GPIO33_OUT_SET(x)        SET_BITS((x), (1), (1), (1))
#define GPIO_GPSET1__GPIO33_OUT_CLR(x)        CLR_BITS((x), (1), (1))

#define GPIO_GPSET1__GPIO34_OUT_GET(x)        GET_BITS((x), (2), (1)) 
#define GPIO_GPSET1__GPIO34_OUT_SET(x)        SET_BITS((x), (2), (1), (1))
#define GPIO_GPSET1__GPIO34_OUT_CLR(x)        CLR_BITS((x), (2), (1))

#define GPIO_GPSET1__GPIO35_OUT_GET(x)        GET_BITS((x), (3), (1)) 
#define GPIO_GPSET1__GPIO35_OUT_SET(x)        SET_BITS((x), (3), (1), (1))
#define GPIO_GPSET1__GPIO35_OUT_CLR(x)        CLR_BITS((x), (3), (1))

#define GPIO_GPSET1__GPIO36_OUT_GET(x)        GET_BITS((x), (4), (1)) 
#define GPIO_GPSET1__GPIO36_OUT_SET(x)        SET_BITS((x), (4), (1), (1))
#define GPIO_GPSET1__GPIO36_OUT_CLR(x)        CLR_BITS((x), (4), (1))

#define GPIO_GPSET1__GPIO37_OUT_GET(x)        GET_BITS((x), (5), (1)) 
#define GPIO_GPSET1__GPIO37_OUT_SET(x)        SET_BITS((x), (5), (1), (1))
#define GPIO_GPSET1__GPIO37_OUT_CLR(x)        CLR_BITS((x), (5), (1))

#define GPIO_GPSET1__GPIO38_OUT_GET(x)        GET_BITS((x), (6), (1)) 
#define GPIO_GPSET1__GPIO38_OUT_SET(x)        SET_BITS((x), (6), (1), (1))
#define GPIO_GPSET1__GPIO38_OUT_CLR(x)        CLR_BITS((x), (6), (1))

#define GPIO_GPSET1__GPIO39_OUT_GET(x)        GET_BITS((x), (7), (1)) 
#define GPIO_GPSET1__GPIO39_OUT_SET(x)        SET_BITS((x), (7), (1), (1))
#define GPIO_GPSET1__GPIO39_OUT_CLR(x)        CLR_BITS((x), (7), (1))

#define GPIO_GPSET1__GPIO40_OUT_GET(x)        GET_BITS((x), (8), (1)) 
#define GPIO_GPSET1__GPIO40_OUT_SET(x)        SET_BITS((x), (8), (1), (1))
#define GPIO_GPSET1__GPIO40_OUT_CLR(x)        CLR_BITS((x), (8), (1))

#define GPIO_GPSET1__GPIO41_OUT_GET(x)        GET_BITS((x), (9), (1)) 
#define GPIO_GPSET1__GPIO41_OUT_SET(x)        SET_BITS((x), (9), (1), (1))
#define GPIO_GPSET1__GPIO41_OUT_CLR(x)        CLR_BITS((x), (9), (1))

#define GPIO_GPSET1__GPIO42_OUT_GET(x)        GET_BITS((x), (10), (1)) 
#define GPIO_GPSET1__GPIO42_OUT_SET(x)        SET_BITS((x), (10), (1), (1))
#define GPIO_GPSET1__GPIO42_OUT_CLR(x)        CLR_BITS((x), (10), (1))

#define GPIO_GPSET1__GPIO43_OUT_GET(x)        GET_BITS((x), (11), (1)) 
#define GPIO_GPSET1__GPIO43_OUT_SET(x)        SET_BITS((x), (11), (1), (1))
#define GPIO_GPSET1__GPIO43_OUT_CLR(x)        CLR_BITS((x), (11), (1))

#define GPIO_GPSET1__GPIO44_OUT_GET(x)        GET_BITS((x), (12), (1)) 
#define GPIO_GPSET1__GPIO44_OUT_SET(x)        SET_BITS((x), (12), (1), (1))
#define GPIO_GPSET1__GPIO44_OUT_CLR(x)        CLR_BITS((x), (12), (1))

#define GPIO_GPSET1__GPIO45_OUT_GET(x)        GET_BITS((x), (13), (1)) 
#define GPIO_GPSET1__GPIO45_OUT_SET(x)        SET_BITS((x), (13), (1), (1))
#define GPIO_GPSET1__GPIO45_OUT_CLR(x)        CLR_BITS((x), (13), (1))

#define GPIO_GPSET1__GPIO46_OUT_GET(x)        GET_BITS((x), (14), (1)) 
#define GPIO_GPSET1__GPIO46_OUT_SET(x)        SET_BITS((x), (14), (1), (1))
#define GPIO_GPSET1__GPIO46_OUT_CLR(x)        CLR_BITS((x), (14), (1))

#define GPIO_GPSET1__GPIO47_OUT_GET(x)        GET_BITS((x), (15), (1)) 
#define GPIO_GPSET1__GPIO47_OUT_SET(x)        SET_BITS((x), (15), (1), (1))
#define GPIO_GPSET1__GPIO47_OUT_CLR(x)        CLR_BITS((x), (15), (1))

#define GPIO_GPSET1__GPIO48_OUT_GET(x)        GET_BITS((x), (16), (1)) 
#define GPIO_GPSET1__GPIO48_OUT_SET(x)        SET_BITS((x), (16), (1), (1))
#define GPIO_GPSET1__GPIO48_OUT_CLR(x)        CLR_BITS((x), (16), (1))

#define GPIO_GPSET1__GPIO49_OUT_GET(x)        GET_BITS((x), (17), (1)) 
#define GPIO_GPSET1__GPIO49_OUT_SET(x)        SET_BITS((x), (17), (1), (1))
#define GPIO_GPSET1__GPIO49_OUT_CLR(x)        CLR_BITS((x), (17), (1))

#define GPIO_GPSET1__GPIO50_OUT_GET(x)        GET_BITS((x), (18), (1)) 
#define GPIO_GPSET1__GPIO50_OUT_SET(x)        SET_BITS((x), (18), (1), (1))
#define GPIO_GPSET1__GPIO50_OUT_CLR(x)        CLR_BITS((x), (18), (1))

#define GPIO_GPSET1__GPIO51_OUT_GET(x)        GET_BITS((x), (19), (1)) 
#define GPIO_GPSET1__GPIO51_OUT_SET(x)        SET_BITS((x), (19), (1), (1))
#define GPIO_GPSET1__GPIO51_OUT_CLR(x)        CLR_BITS((x), (19), (1))

#define GPIO_GPSET1__GPIO52_OUT_GET(x)        GET_BITS((x), (20), (1)) 
#define GPIO_GPSET1__GPIO52_OUT_SET(x)        SET_BITS((x), (20), (1), (1))
#define GPIO_GPSET1__GPIO52_OUT_CLR(x)        CLR_BITS((x), (20), (1))

#define GPIO_GPSET1__GPIO53_OUT_GET(x)        GET_BITS((x), (21), (1)) 
#define GPIO_GPSET1__GPIO53_OUT_SET(x)        SET_BITS((x), (21), (1), (1))
#define GPIO_GPSET1__GPIO53_OUT_CLR(x)        CLR_BITS((x), (21), (1))

#define GPIO_GPCLR0__GPIO0_GET(x)        GET_BITS((x), (0), (1)) 
#define GPIO_GPCLR0__GPIO0_SET(x)        SET_BITS((x), (0), (1), (1))
#define GPIO_GPCLR0__GPIO0_CLR(x)        CLR_BITS((x), (0), (1))

#define GPIO_GPCLR0__GPIO1_GET(x)        GET_BITS((x), (1), (1)) 
#define GPIO_GPCLR0__GPIO1_SET(x)        SET_BITS((x), (1), (1), (1))
#define GPIO_GPCLR0__GPIO1_CLR(x)        CLR_BITS((x), (1), (1))

#define GPIO_GPCLR0__GPIO2_GET(x)        GET_BITS((x), (2), (1)) 
#define GPIO_GPCLR0__GPIO2_SET(x)        SET_BITS((x), (2), (1), (1))
#define GPIO_GPCLR0__GPIO2_CLR(x)        CLR_BITS((x), (2), (1))

#define GPIO_GPCLR0__GPIO3_GET(x)        GET_BITS((x), (3), (1)) 
#define GPIO_GPCLR0__GPIO3_SET(x)        SET_BITS((x), (3), (1), (1))
#define GPIO_GPCLR0__GPIO3_CLR(x)        CLR_BITS((x), (3), (1))

#define GPIO_GPCLR0__GPIO4_GET(x)        GET_BITS((x), (4), (1)) 
#define GPIO_GPCLR0__GPIO4_SET(x)        SET_BITS((x), (4), (1), (1))
#define GPIO_GPCLR0__GPIO4_CLR(x)        CLR_BITS((x), (4), (1))

#define GPIO_GPCLR0__GPIO5_GET(x)        GET_BITS((x), (5), (1)) 
#define GPIO_GPCLR0__GPIO5_SET(x)        SET_BITS((x), (5), (1), (1))
#define GPIO_GPCLR0__GPIO5_CLR(x)        CLR_BITS((x), (5), (1))

#define GPIO_GPCLR0__GPIO6_GET(x)        GET_BITS((x), (6), (1)) 
#define GPIO_GPCLR0__GPIO6_SET(x)        SET_BITS((x), (6), (1), (1))
#define GPIO_GPCLR0__GPIO6_CLR(x)        CLR_BITS((x), (6), (1))

#define GPIO_GPCLR0__GPIO7_GET(x)        GET_BITS((x), (7), (1)) 
#define GPIO_GPCLR0__GPIO7_SET(x)        SET_BITS((x), (7), (1), (1))
#define GPIO_GPCLR0__GPIO7_CLR(x)        CLR_BITS((x), (7), (1))

#define GPIO_GPCLR0__GPIO8_GET(x)        GET_BITS((x), (8), (1)) 
#define GPIO_GPCLR0__GPIO8_SET(x)        SET_BITS((x), (8), (1), (1))
#define GPIO_GPCLR0__GPIO8_CLR(x)        CLR_BITS((x), (8), (1))

#define GPIO_GPCLR0__GPIO9_GET(x)        GET_BITS((x), (9), (1)) 
#define GPIO_GPCLR0__GPIO9_SET(x)        SET_BITS((x), (9), (1), (1))
#define GPIO_GPCLR0__GPIO9_CLR(x)        CLR_BITS((x), (9), (1))

#define GPIO_GPCLR0__GPIO10_GET(x)        GET_BITS((x), (10), (1)) 
#define GPIO_GPCLR0__GPIO10_SET(x)        SET_BITS((x), (10), (1), (1))
#define GPIO_GPCLR0__GPIO10_CLR(x)        CLR_BITS((x), (10), (1))

#define GPIO_GPCLR0__GPIO11_GET(x)        GET_BITS((x), (11), (1)) 
#define GPIO_GPCLR0__GPIO11_SET(x)        SET_BITS((x), (11), (1), (1))
#define GPIO_GPCLR0__GPIO11_CLR(x)        CLR_BITS((x), (11), (1))

#define GPIO_GPCLR0__GPIO12_GET(x)        GET_BITS((x), (12), (1)) 
#define GPIO_GPCLR0__GPIO12_SET(x)        SET_BITS((x), (12), (1), (1))
#define GPIO_GPCLR0__GPIO12_CLR(x)        CLR_BITS((x), (12), (1))

#define GPIO_GPCLR0__GPIO13_GET(x)        GET_BITS((x), (13), (1)) 
#define GPIO_GPCLR0__GPIO13_SET(x)        SET_BITS((x), (13), (1), (1))
#define GPIO_GPCLR0__GPIO13_CLR(x)        CLR_BITS((x), (13), (1))

#define GPIO_GPCLR0__GPIO14_GET(x)        GET_BITS((x), (14), (1)) 
#define GPIO_GPCLR0__GPIO14_SET(x)        SET_BITS((x), (14, (1), (1))
#define GPIO_GPCLR0__GPIO14_CLR(x)        CLR_BITS((x), (14), (1))

#define GPIO_GPCLR0__GPIO15_GET(x)        GET_BITS((x), (15), (1)) 
#define GPIO_GPCLR0__GPIO15_SET(x)        SET_BITS((x), (15), (1), (1))
#define GPIO_GPCLR0__GPIO15_CLR(x)        CLR_BITS((x), (15), (1))

#define GPIO_GPCLR0__GPIO16_GET(x)        GET_BITS((x), (16), (1)) 
#define GPIO_GPCLR0__GPIO16_SET(x)        SET_BITS((x), (16), (1), (1))
#define GPIO_GPCLR0__GPIO16_CLR(x)        CLR_BITS((x), (16), (1))

#define GPIO_GPCLR0__GPIO17_GET(x)        GET_BITS((x), (17), (1)) 
#define GPIO_GPCLR0__GPIO17_SET(x)        SET_BITS((x), (17), (1), (1))
#define GPIO_GPCLR0__GPIO17_CLR(x)        CLR_BITS((x), (17), (1))

#define GPIO_GPCLR0__GPIO18_GET(x)        GET_BITS((x), (18), (1)) 
#define GPIO_GPCLR0__GPIO18_SET(x)        SET_BITS((x), (18), (1), (1))
#define GPIO_GPCLR0__GPIO18_CLR(x)        CLR_BITS((x), (18), (1))

#define GPIO_GPCLR0__GPIO19_GET(x)        GET_BITS((x), (19), (1)) 
#define GPIO_GPCLR0__GPIO19_SET(x)        SET_BITS((x), (19), (1), (1))
#define GPIO_GPCLR0__GPIO19_CLR(x)        CLR_BITS((x), (19), (1))

#define GPIO_GPCLR0__GPIO20_GET(x)        GET_BITS((x), (20), (1)) 
#define GPIO_GPCLR0__GPIO20_SET(x)        SET_BITS((x), (20), (1), (1))
#define GPIO_GPCLR0__GPIO20_CLR(x)        CLR_BITS((x), (20), (1))

#define GPIO_GPCLR0__GPIO21_GET(x)        GET_BITS((x), (21), (1)) 
#define GPIO_GPCLR0__GPIO21_SET(x)        SET_BITS((x), (21), (1), (1))
#define GPIO_GPCLR0__GPIO21_CLR(x)        CLR_BITS((x), (21), (1))

#define GPIO_GPCLR0__GPIO22_GET(x)        GET_BITS((x), (22), (1)) 
#define GPIO_GPCLR0__GPIO22_SET(x)        SET_BITS((x), (22), (1), (1))
#define GPIO_GPCLR0__GPIO22_CLR(x)        CLR_BITS((x), (22), (1))

#define GPIO_GPCLR0__GPIO23_GET(x)        GET_BITS((x), (23), (1)) 
#define GPIO_GPCLR0__GPIO23_SET(x)        SET_BITS((x), (23), (1), (1))
#define GPIO_GPCLR0__GPIO23_CLR(x)        CLR_BITS((x), (23), (1))

#define GPIO_GPCLR0__GPIO24_GET(x)        GET_BITS((x), (24), (1)) 
#define GPIO_GPCLR0__GPIO24_SET(x)        SET_BITS((x), (24), (1), (1))
#define GPIO_GPCLR0__GPIO24_CLR(x)        CLR_BITS((x), (24), (1))

#define GPIO_GPCLR0__GPIO25_GET(x)        GET_BITS((x), (25), (1)) 
#define GPIO_GPCLR0__GPIO25_SET(x)        SET_BITS((x), (25), (1), (1))
#define GPIO_GPCLR0__GPIO25_CLR(x)        CLR_BITS((x), (25), (1))

#define GPIO_GPCLR0__GPIO26_GET(x)        GET_BITS((x), (26), (1)) 
#define GPIO_GPCLR0__GPIO26_SET(x)        SET_BITS((x), (26), (1), (1))
#define GPIO_GPCLR0__GPIO26_CLR(x)        CLR_BITS((x), (26), (1))

#define GPIO_GPCLR0__GPIO27_GET(x)        GET_BITS((x), (27), (1)) 
#define GPIO_GPCLR0__GPIO27_SET(x)        SET_BITS((x), (27), (1), (1))
#define GPIO_GPCLR0__GPIO27_CLR(x)        CLR_BITS((x), (27), (1))

#define GPIO_GPCLR0__GPIO28_GET(x)        GET_BITS((x), (28), (1)) 
#define GPIO_GPCLR0__GPIO28_SET(x)        SET_BITS((x), (28), (1), (1))
#define GPIO_GPCLR0__GPIO28_CLR(x)        CLR_BITS((x), (28), (1))

#define GPIO_GPCLR0__GPIO29_GET(x)        GET_BITS((x), (29), (1)) 
#define GPIO_GPCLR0__GPIO29_SET(x)        SET_BITS((x), (29), (1), (1))
#define GPIO_GPCLR0__GPIO29_CLR(x)        CLR_BITS((x), (29), (1))

#define GPIO_GPCLR0__GPIO30_GET(x)        GET_BITS((x), (30), (1)) 
#define GPIO_GPCLR0__GPIO30_SET(x)        SET_BITS((x), (30), (1), (1))
#define GPIO_GPCLR0__GPIO30_CLR(x)        CLR_BITS((x), (30), (1))

#define GPIO_GPCLR0__GPIO31_GET(x)        GET_BITS((x), (31), (1)) 
#define GPIO_GPCLR0__GPIO31_SET(x)        SET_BITS((x), (31), (1), (1))
#define GPIO_GPCLR0__GPIO31_CLR(x)        CLR_BITS((x), (31), (1))

#define GPIO_GPCLR1__GPIO32_GET(x)        GET_BITS((x), (0), (1)) 
#define GPIO_GPSET1__GPIO32_SET(x)        SET_BITS((x), (0), (1), (1))
#define GPIO_GPSET1__GPIO32_CLR(x)        CLR_BITS((x), (0), (1))

#define GPIO_GPSET1__GPIO33_GET(x)        GET_BITS((x), (1), (1)) 
#define GPIO_GPSET1__GPIO33_SET(x)        SET_BITS((x), (1), (1), (1))
#define GPIO_GPSET1__GPIO33_CLR(x)        CLR_BITS((x), (1), (1))

#define GPIO_GPSET1__GPIO34_GET(x)        GET_BITS((x), (2), (1)) 
#define GPIO_GPSET1__GPIO34_SET(x)        SET_BITS((x), (2), (1), (1))
#define GPIO_GPSET1__GPIO34_CLR(x)        CLR_BITS((x), (2), (1))

#define GPIO_GPSET1__GPIO35_GET(x)        GET_BITS((x), (3), (1)) 
#define GPIO_GPSET1__GPIO35_SET(x)        SET_BITS((x), (3), (1), (1))
#define GPIO_GPSET1__GPIO35_CLR(x)        CLR_BITS((x), (3), (1))

#define GPIO_GPSET1__GPIO36_GET(x)        GET_BITS((x), (4), (1)) 
#define GPIO_GPSET1__GPIO36_SET(x)        SET_BITS((x), (4), (1), (1))
#define GPIO_GPSET1__GPIO36_CLR(x)        CLR_BITS((x), (4), (1))

#define GPIO_GPSET1__GPIO37_GET(x)        GET_BITS((x), (5), (1)) 
#define GPIO_GPSET1__GPIO37_SET(x)        SET_BITS((x), (5), (1), (1))
#define GPIO_GPSET1__GPIO37_CLR(x)        CLR_BITS((x), (5), (1))

#define GPIO_GPSET1__GPIO38_GET(x)        GET_BITS((x), (6), (1)) 
#define GPIO_GPSET1__GPIO38_SET(x)        SET_BITS((x), (6), (1), (1))
#define GPIO_GPSET1__GPIO38_CLR(x)        CLR_BITS((x), (6), (1))

#define GPIO_GPSET1__GPIO39_GET(x)        GET_BITS((x), (7), (1)) 
#define GPIO_GPSET1__GPIO39_SET(x)        SET_BITS((x), (7), (1), (1))
#define GPIO_GPSET1__GPIO39_CLR(x)        CLR_BITS((x), (7), (1))

#define GPIO_GPSET1__GPIO40_GET(x)        GET_BITS((x), (8), (1)) 
#define GPIO_GPSET1__GPIO40_SET(x)        SET_BITS((x), (8), (1), (1))
#define GPIO_GPSET1__GPIO40_CLR(x)        CLR_BITS((x), (8), (1))

#define GPIO_GPSET1__GPIO41_GET(x)        GET_BITS((x), (9), (1)) 
#define GPIO_GPSET1__GPIO41_SET(x)        SET_BITS((x), (9), (1), (1))
#define GPIO_GPSET1__GPIO41_CLR(x)        CLR_BITS((x), (9), (1))

#define GPIO_GPSET1__GPIO42_GET(x)        GET_BITS((x), (10), (1)) 
#define GPIO_GPSET1__GPIO42_SET(x)        SET_BITS((x), (10), (1), (1))
#define GPIO_GPSET1__GPIO42_CLR(x)        CLR_BITS((x), (10), (1))

#define GPIO_GPSET1__GPIO43_GET(x)        GET_BITS((x), (11), (1)) 
#define GPIO_GPSET1__GPIO43_SET(x)        SET_BITS((x), (11), (1), (1))
#define GPIO_GPSET1__GPIO43_CLR(x)        CLR_BITS((x), (11), (1))

#define GPIO_GPSET1__GPIO44_GET(x)        GET_BITS((x), (12), (1)) 
#define GPIO_GPSET1__GPIO44_SET(x)        SET_BITS((x), (12), (1), (1))
#define GPIO_GPSET1__GPIO44_CLR(x)        CLR_BITS((x), (12), (1))

#define GPIO_GPSET1__GPIO45_GET(x)        GET_BITS((x), (13), (1)) 
#define GPIO_GPSET1__GPIO45_SET(x)        SET_BITS((x), (13), (1), (1))
#define GPIO_GPSET1__GPIO45_CLR(x)        CLR_BITS((x), (13), (1))

#define GPIO_GPSET1__GPIO46_GET(x)        GET_BITS((x), (14), (1)) 
#define GPIO_GPSET1__GPIO46_SET(x)        SET_BITS((x), (14), (1), (1))
#define GPIO_GPSET1__GPIO46_CLR(x)        CLR_BITS((x), (14), (1))

#define GPIO_GPSET1__GPIO47_GET(x)        GET_BITS((x), (15), (1)) 
#define GPIO_GPSET1__GPIO47_SET(x)        SET_BITS((x), (15), (1), (1))
#define GPIO_GPSET1__GPIO47_CLR(x)        CLR_BITS((x), (15), (1))

#define GPIO_GPSET1__GPIO48_GET(x)        GET_BITS((x), (16), (1)) 
#define GPIO_GPSET1__GPIO48_SET(x)        SET_BITS((x), (16), (1), (1))
#define GPIO_GPSET1__GPIO48_CLR(x)        CLR_BITS((x), (16), (1))

#define GPIO_GPSET1__GPIO49_GET(x)        GET_BITS((x), (17), (1)) 
#define GPIO_GPSET1__GPIO49_SET(x)        SET_BITS((x), (17), (1), (1))
#define GPIO_GPSET1__GPIO49_CLR(x)        CLR_BITS((x), (17), (1))

#define GPIO_GPSET1__GPIO50_GET(x)        GET_BITS((x), (18), (1)) 
#define GPIO_GPSET1__GPIO50_SET(x)        SET_BITS((x), (18), (1), (1))
#define GPIO_GPSET1__GPIO50_CLR(x)        CLR_BITS((x), (18), (1))

#define GPIO_GPSET1__GPIO51_GET(x)        GET_BITS((x), (19), (1)) 
#define GPIO_GPSET1__GPIO51_SET(x)        SET_BITS((x), (19), (1), (1))
#define GPIO_GPSET1__GPIO51_CLR(x)        CLR_BITS((x), (19), (1))

#define GPIO_GPSET1__GPIO52_GET(x)        GET_BITS((x), (20), (1)) 
#define GPIO_GPSET1__GPIO52_SET(x)        SET_BITS((x), (20), (1), (1))
#define GPIO_GPSET1__GPIO52_CLR(x)        CLR_BITS((x), (20), (1))

#define GPIO_GPSET1__GPIO53_GET(x)        GET_BITS((x), (21), (1)) 
#define GPIO_GPSET1__GPIO53_SET(x)        SET_BITS((x), (21), (1), (1))
#define GPIO_GPSET1__GPIO53_CLR(x)        CLR_BITS((x), (21), (1))


#define GPIO_GPLEV0__GPIO0_GET(x)        GET_BITS((x), (0), (1)) 
#define GPIO_GPLEV0__GPIO0_SET(x)        SET_BITS((x), (0), (1), (1))
#define GPIO_GPLEV0__GPIO0_CLR(x)        CLR_BITS((x), (0), (1))

#define GPIO_GPLEV0__GPIO1_GET(x)        GET_BITS((x), (1), (1)) 
#define GPIO_GPLEV0__GPIO1_SET(x)        SET_BITS((x), (1), (1), (1))
#define GPIO_GPLEV0__GPIO1_CLR(x)        CLR_BITS((x), (1), (1))

#define GPIO_GPLEV0__GPIO2_GET(x)        GET_BITS((x), (2), (1)) 
#define GPIO_GPLEV0__GPIO2_SET(x)        SET_BITS((x), (2), (1), (1))
#define GPIO_GPLEV0__GPIO2_CLR(x)        CLR_BITS((x), (2), (1))

#define GPIO_GPLEV0__GPIO3_GET(x)        GET_BITS((x), (3), (1)) 
#define GPIO_GPLEV0__GPIO3_SET(x)        SET_BITS((x), (3), (1), (1))
#define GPIO_GPLEV0__GPIO3_CLR(x)        CLR_BITS((x), (3), (1))

#define GPIO_GPLEV0__GPIO4_GET(x)        GET_BITS((x), (4), (1)) 
#define GPIO_GPLEV0__GPIO4_SET(x)        SET_BITS((x), (4), (1), (1))
#define GPIO_GPLEV0__GPIO4_CLR(x)        CLR_BITS((x), (4), (1))

#define GPIO_GPLEV0__GPIO5_GET(x)        GET_BITS((x), (5), (1)) 
#define GPIO_GPLEV0__GPIO5_SET(x)        SET_BITS((x), (5), (1), (1))
#define GPIO_GPLEV0__GPIO5_CLR(x)        CLR_BITS((x), (5), (1))

#define GPIO_GPLEV0__GPIO6_GET(x)        GET_BITS((x), (6), (1)) 
#define GPIO_GPLEV0__GPIO6_SET(x)        SET_BITS((x), (6), (1), (1))
#define GPIO_GPLEV0__GPIO6_CLR(x)        CLR_BITS((x), (6), (1))

#define GPIO_GPLEV0__GPIO7_GET(x)        GET_BITS((x), (7), (1)) 
#define GPIO_GPLEV0__GPIO7_SET(x)        SET_BITS((x), (7), (1), (1))
#define GPIO_GPLEV0__GPIO7_CLR(x)        CLR_BITS((x), (7), (1))

#define GPIO_GPLEV0__GPIO8_GET(x)        GET_BITS((x), (8), (1)) 
#define GPIO_GPLEV0__GPIO8_SET(x)        SET_BITS((x), (8), (1), (1))
#define GPIO_GPLEV0__GPIO8_CLR(x)        CLR_BITS((x), (8), (1))

#define GPIO_GPLEV0__GPIO9_GET(x)        GET_BITS((x), (9), (1)) 
#define GPIO_GPLEV0__GPIO9_SET(x)        SET_BITS((x), (9), (1), (1))
#define GPIO_GPLEV0__GPIO9_CLR(x)        CLR_BITS((x), (9), (1))

#define GPIO_GPLEV0__GPIO10_GET(x)        GET_BITS((x), (10), (1)) 
#define GPIO_GPLEV0__GPIO10_SET(x)        SET_BITS((x), (10), (1), (1))
#define GPIO_GPLEV0__GPIO10_CLR(x)        CLR_BITS((x), (10), (1))

#define GPIO_GPLEV0__GPIO11_GET(x)        GET_BITS((x), (11), (1)) 
#define GPIO_GPLEV0__GPIO11_SET(x)        SET_BITS((x), (11), (1), (1))
#define GPIO_GPLEV0__GPIO11_CLR(x)        CLR_BITS((x), (11), (1))

#define GPIO_GPLEV0__GPIO12_GET(x)        GET_BITS((x), (12), (1)) 
#define GPIO_GPLEV0__GPIO12_SET(x)        SET_BITS((x), (12), (1), (1))
#define GPIO_GPLEV0__GPIO12_CLR(x)        CLR_BITS((x), (12), (1))

#define GPIO_GPLEV0__GPIO13_GET(x)        GET_BITS((x), (13), (1)) 
#define GPIO_GPLEV0__GPIO13_SET(x)        SET_BITS((x), (13), (1), (1))
#define GPIO_GPLEV0__GPIO13_CLR(x)        CLR_BITS((x), (13), (1))

#define GPIO_GPLEV0__GPIO14_GET(x)        GET_BITS((x), (14), (1)) 
#define GPIO_GPLEV0__GPIO14_SET(x)        SET_BITS((x), (14, (1), (1))
#define GPIO_GPLEV0__GPIO14_CLR(x)        CLR_BITS((x), (14), (1))

#define GPIO_GPLEV0__GPIO15_GET(x)        GET_BITS((x), (15), (1)) 
#define GPIO_GPLEV0__GPIO15_SET(x)        SET_BITS((x), (15), (1), (1))
#define GPIO_GPLEV0__GPIO15_CLR(x)        CLR_BITS((x), (15), (1))

#define GPIO_GPLEV0__GPIO16_GET(x)        GET_BITS((x), (16), (1)) 
#define GPIO_GPLEV0__GPIO16_SET(x)        SET_BITS((x), (16), (1), (1))
#define GPIO_GPLEV0__GPIO16_CLR(x)        CLR_BITS((x), (16), (1))

#define GPIO_GPLEV0__GPIO17_GET(x)        GET_BITS((x), (17), (1)) 
#define GPIO_GPLEV0__GPIO17_SET(x)        SET_BITS((x), (17), (1), (1))
#define GPIO_GPLEV0__GPIO17_CLR(x)        CLR_BITS((x), (17), (1))

#define GPIO_GPLEV0__GPIO18_GET(x)        GET_BITS((x), (18), (1)) 
#define GPIO_GPLEV0__GPIO18_SET(x)        SET_BITS((x), (18), (1), (1))
#define GPIO_GPLEV0__GPIO18_CLR(x)        CLR_BITS((x), (18), (1))

#define GPIO_GPLEV0__GPIO19_GET(x)        GET_BITS((x), (19), (1)) 
#define GPIO_GPLEV0__GPIO19_SET(x)        SET_BITS((x), (19), (1), (1))
#define GPIO_GPLEV0__GPIO19_CLR(x)        CLR_BITS((x), (19), (1))

#define GPIO_GPLEV0__GPIO20_GET(x)        GET_BITS((x), (20), (1)) 
#define GPIO_GPLEV0__GPIO20_SET(x)        SET_BITS((x), (20), (1), (1))
#define GPIO_GPLEV0__GPIO20_CLR(x)        CLR_BITS((x), (20), (1))

#define GPIO_GPLEV0__GPIO21_GET(x)        GET_BITS((x), (21), (1)) 
#define GPIO_GPLEV0__GPIO21_SET(x)        SET_BITS((x), (21), (1), (1))
#define GPIO_GPLEV0__GPIO21_CLR(x)        CLR_BITS((x), (21), (1))

#define GPIO_GPLEV0__GPIO22_GET(x)        GET_BITS((x), (22), (1)) 
#define GPIO_GPLEV0__GPIO22_SET(x)        SET_BITS((x), (22), (1), (1))
#define GPIO_GPLEV0__GPIO22_CLR(x)        CLR_BITS((x), (22), (1))

#define GPIO_GPLEV0__GPIO23_GET(x)        GET_BITS((x), (23), (1)) 
#define GPIO_GPLEV0__GPIO23_SET(x)        SET_BITS((x), (23), (1), (1))
#define GPIO_GPLEV0__GPIO23_CLR(x)        CLR_BITS((x), (23), (1))

#define GPIO_GPLEV0__GPIO24_GET(x)        GET_BITS((x), (24), (1)) 
#define GPIO_GPLEV0__GPIO24_SET(x)        SET_BITS((x), (24), (1), (1))
#define GPIO_GPLEV0__GPIO24_CLR(x)        CLR_BITS((x), (24), (1))

#define GPIO_GPLEV0__GPIO25_GET(x)        GET_BITS((x), (25), (1)) 
#define GPIO_GPLEV0__GPIO25_SET(x)        SET_BITS((x), (25), (1), (1))
#define GPIO_GPLEV0__GPIO25_CLR(x)        CLR_BITS((x), (25), (1))

#define GPIO_GPLEV0__GPIO26_GET(x)        GET_BITS((x), (26), (1)) 
#define GPIO_GPLEV0__GPIO26_SET(x)        SET_BITS((x), (26), (1), (1))
#define GPIO_GPLEV0__GPIO26_CLR(x)        CLR_BITS((x), (26), (1))

#define GPIO_GPLEV0__GPIO27_GET(x)        GET_BITS((x), (27), (1)) 
#define GPIO_GPLEV0__GPIO27_SET(x)        SET_BITS((x), (27), (1), (1))
#define GPIO_GPLEV0__GPIO27_CLR(x)        CLR_BITS((x), (27), (1))

#define GPIO_GPLEV0__GPIO28_GET(x)        GET_BITS((x), (28), (1)) 
#define GPIO_GPLEV0__GPIO28_SET(x)        SET_BITS((x), (28), (1), (1))
#define GPIO_GPLEV0__GPIO28_CLR(x)        CLR_BITS((x), (28), (1))

#define GPIO_GPLEV0__GPIO29_GET(x)        GET_BITS((x), (29), (1)) 
#define GPIO_GPLEV0__GPIO29_SET(x)        SET_BITS((x), (29), (1), (1))
#define GPIO_GPLEV0__GPIO29_CLR(x)        CLR_BITS((x), (29), (1))

#define GPIO_GPLEV0__GPIO30_GET(x)        GET_BITS((x), (30), (1)) 
#define GPIO_GPLEV0__GPIO30_SET(x)        SET_BITS((x), (30), (1), (1))
#define GPIO_GPLEV0__GPIO30_CLR(x)        CLR_BITS((x), (30), (1))

#define GPIO_GPLEV0__GPIO31_GET(x)        GET_BITS((x), (31), (1)) 
#define GPIO_GPLEV0__GPIO31_SET(x)        SET_BITS((x), (31), (1), (1))
#define GPIO_GPLEV0__GPIO31_CLR(x)        CLR_BITS((x), (31), (1))

#define GPIO_GPLEV1__GPIO32_GET(x)        GET_BITS((x), (0), (1)) 
#define GPIO_GPLEV1__GPIO32_SET(x)        SET_BITS((x), (0), (1), (1))
#define GPIO_GPLEV1__GPIO32_CLR(x)        CLR_BITS((x), (0), (1))

#define GPIO_GPLEV1__GPIO33_GET(x)        GET_BITS((x), (1), (1)) 
#define GPIO_GPLEV1__GPIO33_SET(x)        SET_BITS((x), (1), (1), (1))
#define GPIO_GPLEV1__GPIO33_CLR(x)        CLR_BITS((x), (1), (1))

#define GPIO_GPLEV1__GPIO34_GET(x)        GET_BITS((x), (2), (1)) 
#define GPIO_GPLEV1__GPIO34_SET(x)        SET_BITS((x), (2), (1), (1))
#define GPIO_GPLEV1__GPIO34_CLR(x)        CLR_BITS((x), (2), (1))

#define GPIO_GPLEV1__GPIO35_GET(x)        GET_BITS((x), (3), (1)) 
#define GPIO_GPLEV1__GPIO35_SET(x)        SET_BITS((x), (3), (1), (1))
#define GPIO_GPLEV1__GPIO35_CLR(x)        CLR_BITS((x), (3), (1))

#define GPIO_GPLEV1__GPIO36_GET(x)        GET_BITS((x), (4), (1)) 
#define GPIO_GPLEV1__GPIO36_SET(x)        SET_BITS((x), (4), (1), (1))
#define GPIO_GPLEV1__GPIO36_CLR(x)        CLR_BITS((x), (4), (1))

#define GPIO_GPLEV1__GPIO37_GET(x)        GET_BITS((x), (5), (1)) 
#define GPIO_GPLEV1__GPIO37_SET(x)        SET_BITS((x), (5), (1), (1))
#define GPIO_GPLEV1__GPIO37_CLR(x)        CLR_BITS((x), (5), (1))

#define GPIO_GPLEV1__GPIO38_GET(x)        GET_BITS((x), (6), (1)) 
#define GPIO_GPLEV1__GPIO38_SET(x)        SET_BITS((x), (6), (1), (1))
#define GPIO_GPLEV1__GPIO38_CLR(x)        CLR_BITS((x), (6), (1))

#define GPIO_GPLEV1__GPIO39_GET(x)        GET_BITS((x), (7), (1)) 
#define GPIO_GPLEV1__GPIO39_SET(x)        SET_BITS((x), (7), (1), (1))
#define GPIO_GPLEV1__GPIO39_CLR(x)        CLR_BITS((x), (7), (1))

#define GPIO_GPLEV1__GPIO40_GET(x)        GET_BITS((x), (8), (1)) 
#define GPIO_GPLEV1__GPIO40_SET(x)        SET_BITS((x), (8), (1), (1))
#define GPIO_GPLEV1__GPIO40_CLR(x)        CLR_BITS((x), (8), (1))

#define GPIO_GPLEV1__GPIO41_GET(x)        GET_BITS((x), (9), (1)) 
#define GPIO_GPLEV1__GPIO41_SET(x)        SET_BITS((x), (9), (1), (1))
#define GPIO_GPLEV1__GPIO41_CLR(x)        CLR_BITS((x), (9), (1))

#define GPIO_GPLEV1__GPIO42_GET(x)        GET_BITS((x), (10), (1)) 
#define GPIO_GPLEV1__GPIO42_SET(x)        SET_BITS((x), (10), (1), (1))
#define GPIO_GPLEV1__GPIO42_CLR(x)        CLR_BITS((x), (10), (1))

#define GPIO_GPLEV1__GPIO43_GET(x)        GET_BITS((x), (11), (1)) 
#define GPIO_GPLEV1__GPIO43_SET(x)        SET_BITS((x), (11), (1), (1))
#define GPIO_GPLEV1__GPIO43_CLR(x)        CLR_BITS((x), (11), (1))

#define GPIO_GPLEV1__GPIO44_GET(x)        GET_BITS((x), (12), (1)) 
#define GPIO_GPLEV1__GPIO44_SET(x)        SET_BITS((x), (12), (1), (1))
#define GPIO_GPLEV1__GPIO44_CLR(x)        CLR_BITS((x), (12), (1))

#define GPIO_GPLEV1__GPIO45_GET(x)        GET_BITS((x), (13), (1)) 
#define GPIO_GPLEV1__GPIO45_SET(x)        SET_BITS((x), (13), (1), (1))
#define GPIO_GPLEV1__GPIO45_CLR(x)        CLR_BITS((x), (13), (1))

#define GPIO_GPLEV1__GPIO46_GET(x)        GET_BITS((x), (14), (1)) 
#define GPIO_GPLEV1__GPIO46_SET(x)        SET_BITS((x), (14), (1), (1))
#define GPIO_GPLEV1__GPIO46_CLR(x)        CLR_BITS((x), (14), (1))

#define GPIO_GPLEV1__GPIO47_GET(x)        GET_BITS((x), (15), (1)) 
#define GPIO_GPLEV1__GPIO47_SET(x)        SET_BITS((x), (15), (1), (1))
#define GPIO_GPLEV1__GPIO47_CLR(x)        CLR_BITS((x), (15), (1))

#define GPIO_GPLEV1__GPIO48_GET(x)        GET_BITS((x), (16), (1)) 
#define GPIO_GPLEV1__GPIO48_SET(x)        SET_BITS((x), (16), (1), (1))
#define GPIO_GPLEV1__GPIO48_CLR(x)        CLR_BITS((x), (16), (1))

#define GPIO_GPLEV1__GPIO49_GET(x)        GET_BITS((x), (17), (1)) 
#define GPIO_GPLEV1__GPIO49_SET(x)        SET_BITS((x), (17), (1), (1))
#define GPIO_GPLEV1__GPIO49_CLR(x)        CLR_BITS((x), (17), (1))

#define GPIO_GPLEV1__GPIO50_GET(x)        GET_BITS((x), (18), (1)) 
#define GPIO_GPLEV1__GPIO50_SET(x)        SET_BITS((x), (18), (1), (1))
#define GPIO_GPLEV1__GPIO50_CLR(x)        CLR_BITS((x), (18), (1))

#define GPIO_GPLEV1__GPIO51_GET(x)        GET_BITS((x), (19), (1)) 
#define GPIO_GPLEV1__GPIO51_SET(x)        SET_BITS((x), (19), (1), (1))
#define GPIO_GPLEV1__GPIO51_CLR(x)        CLR_BITS((x), (19), (1))

#define GPIO_GPLEV1__GPIO52_GET(x)        GET_BITS((x), (20), (1)) 
#define GPIO_GPLEV1__GPIO52_SET(x)        SET_BITS((x), (20), (1), (1))
#define GPIO_GPLEV1__GPIO52_CLR(x)        CLR_BITS((x), (20), (1))

#define GPIO_GPLEV1__GPIO53_GET(x)        GET_BITS((x), (21), (1)) 
#define GPIO_GPLEV1__GPIO53_SET(x)        SET_BITS((x), (21), (1), (1))
#define GPIO_GPLEV1__GPIO53_CLR(x)        CLR_BITS((x), (21), (1))


/* @brief:
 *   Function Prototype
 */

void gpio_init(void);

void gpio_close(void);

void gpio_write(unsigned int offset, unsigned int value);

unsigned int gpio_read(unsigned int offset);

void gpio_set_FSELn(unsigned int gpio_no, unsigned int value);

void gpio_clr_FSELn(unsigned int gpio_no);

void gpio_set_SETn(unsigned int gpio_no);

void gpio_clr_SETn(unsigned int gpio_no);

void gpio_set_CLRn(unsigned int gpio_no);

void gpio_clr_CLRn(unsigned int gpio_no);

void gpio_set_LEVn(unsigned int gpio_no);

void gpio_clr_LEVn(unsigned int gpio_no);

void gpio_set_EDSn(unsigned int gpio_no);

void gpio_clear_EDSn(unsigned int gpio_no);

void gpio_set_RENn(unsigned int gpio_no);

void gpio_clear_RENn(unsigned int gpio_no);

void gpio_set_FENn(unsigned int gpio_no);

void gpio_clear_FENn(unsigned int gpio_no);

void gpio_set_HENn(unsigned int gpio_no);

void gpio_clear_HENn(unsigned int gpio_no);

void gpio_set_LENn(unsigned int gpio_no);

void gpio_clear_LENn(unsigned int gpio_no);

void gpio_set_ARENn(unsigned int gpio_no);

void gpio_clear_ARENn(unsigned int gpio_no);

void gpio_set_AFENn(unsigned int gpio_no);

void gpio_clear_AFENn(unsigned int gpio_no);

void gpio_set_PUD(unsigned int value);

void gpio_set_PUDCLKn(unsigned int gpio_no);

void gpio_clear_PUDCLKn(unsigned int gpio_no);
#endif /*GPIO_H__*/
