#ifndef __GPIO_C__
#define __GPIO_C__


#include "common.h"
#include "rpi.h"
#include "gpio.h"

void gpio_write(unsigned int offset, 
                unsigned int value) {

  rpi_write((unsigned int)RPI_GPIO_BASE, 
            offset, 
            value);
}/*gpio_write*/


unsigned int gpio_read(unsigned int offset) {

  return(rpi_read((unsigned int)RPI_GPIO_BASE,
                   offset));
}/*gpio_read*/

void gpio_set_FSELn(unsigned int gpio_no, 
                    unsigned int value) {

  unsigned int x    = 0;
  unsigned int pos  = 0;
  unsigned int bits = 3;

  pos = ((gpio_no % 10) * 3) + 2;
  x = gpio_read((gpio_no/10));
  x = SET_BITS(x, pos, bits, value);
  printk(KERN_INFO "Value is 0x%X", x);
  gpio_write((gpio_no/10), x);
}/*gpio_set_FSELn*/

void gpio_clr_FSELn(unsigned int gpio_no) {

  unsigned int x    = 0;
  unsigned int pos  = 0;
  unsigned int bits = 3;

  pos = ((gpio_no % 10) * 3) + 2;
  x = gpio_read((gpio_no/10));
  x = CLR_BITS(x, pos, bits);
  gpio_write((gpio_no/10), x);
}/*gpio_clr_FSELn*/

void gpio_set_SETn(unsigned int gpio_no) {

  unsigned int x     = 0;
  unsigned int pos   = 0;
  unsigned int bits  = 1;
  unsigned int value = 1;

  if(gpio_no > 32) {
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = SET_BITS(x, pos, bits, value);
    gpio_write(GPIO_GPSET1, x);
 
  } else {
    x = SET_BITS(x, gpio_no, bits, value);
    gpio_write(GPIO_GPSET0, x);
  }
}/*gpio_set_SETn*/

void gpio_set_CLRn(unsigned int gpio_no) {

  unsigned int x     = 0;
  unsigned int value = 1;
  unsigned int pos   = 0;
  unsigned int bits  = 1;

  if(gpio_no > 32) {
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = SET_BITS(x, pos, bits, value);
    gpio_write(GPIO_GPCLR1, x);

  } else {
    x = SET_BITS(x, gpio_no, bits, value);
    gpio_write(GPIO_GPCLR0, x);
  }
}/*gpio_set_CLRn*/

void gpio_set_LEVn(unsigned int gpio_no) {

  unsigned int x     = 0;
  unsigned int value = 1;
  unsigned int pos   = 0;
  unsigned int bits  = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPLEV1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = SET_BITS(x, pos, bits, value);
    gpio_write(GPIO_GPLEV1, x);

  } else {
    x = gpio_read(GPIO_GPLEV0);
    x = SET_BITS(x, gpio_no, bits, value);
    gpio_write(GPIO_GPLEV0, x);
  }
}/*gpio_set_LEVn*/

void gpio_clear_LEVn(unsigned int gpio_no) {

  unsigned int x    = 0;
  unsigned int pos  = 0;
  unsigned int bits = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPLEV1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = CLR_BITS(x, pos, bits);
    gpio_write(GPIO_GPLEV1, x);

  } else {
    x = gpio_read(GPIO_GPLEV0);
    x = CLR_BITS(x, gpio_no, bits);
    gpio_write(GPIO_GPLEV0, x);
  }
}/*gpio_clear_LEVn*/

void gpio_set_EDSn(unsigned int gpio_no) {

  unsigned int x     = 0;
  unsigned int value = 1;
  unsigned int pos   = 0;
  unsigned int bits  = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPEDS1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = SET_BITS(x, pos, bits, value);
    gpio_write(GPIO_GPEDS1, x);

  } else {
    x = gpio_read(GPIO_GPEDS0);
    x = SET_BITS(x, gpio_no, bits, value);
    gpio_write(GPIO_GPEDS0, x);
  }
}/*gpio_set_EDSn*/

void gpio_clear_EDSn(unsigned int gpio_no) {

  unsigned int x    = 0;
  unsigned int pos  = 0;
  unsigned int bits = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPEDS1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = CLR_BITS(x, pos, bits);
    gpio_write(GPIO_GPEDS1, x);

  } else {
    x = gpio_read(GPIO_GPEDS0);
    x = CLR_BITS(x, gpio_no, bits);
    gpio_write(GPIO_GPEDS0, x);
  }
}/*gpio_clear_EDSn*/

void gpio_set_RENn(unsigned int gpio_no) {

  unsigned int x     = 0;
  unsigned int value = 1;
  unsigned int pos   = 0;
  unsigned int bits  = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPREN1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = SET_BITS(x, pos, bits, value);
    gpio_write(GPIO_GPREN1, x);

  } else {
    x = gpio_read(GPIO_GPREN0);
    x = SET_BITS(x, gpio_no, bits, value);
    gpio_write(GPIO_GPREN0, x);
  }
}/*gpio_set_RENn*/

void gpio_clear_RENn(unsigned int gpio_no) {

  unsigned int x    = 0;
  unsigned int pos  = 0;
  unsigned int bits = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPREN1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = CLR_BITS(x, pos, bits);
    gpio_write(GPIO_GPREN1, x);

  } else {
    x = gpio_read(GPIO_GPREN0);
    x = CLR_BITS(x, gpio_no, bits);
    gpio_write(GPIO_GPREN0, x);
  }
}/*gpio_clear_RENn*/

void gpio_set_FENn(unsigned int gpio_no) {

  unsigned int x     = 0;
  unsigned int value = 1;
  unsigned int pos   = 0;
  unsigned int bits  = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPFEN1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = SET_BITS(x, pos, bits, value);
    gpio_write(GPIO_GPFEN1, x);

  } else {
    x = gpio_read(GPIO_GPFEN0);
    x = SET_BITS(x, gpio_no, bits, value);
    gpio_write(GPIO_GPFEN0, x);
  }
}/*gpio_set_FENn*/

void gpio_clear_FENn(unsigned int gpio_no) {

  unsigned int x    = 0;
  unsigned int pos  = 0;
  unsigned int bits = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPFEN1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = CLR_BITS(x, pos, bits);
    gpio_write(GPIO_GPFEN1, x);

  } else {
    x = gpio_read(GPIO_GPFEN0);
    x = CLR_BITS(x, gpio_no, bits);
    gpio_write(GPIO_GPFEN0, x);
  }
}/*gpio_clear_FENn*/

void gpio_set_HENn(unsigned int gpio_no) {

  unsigned int x     = 0;
  unsigned int value = 1;
  unsigned int pos   = 0;
  unsigned int bits  = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPHEN1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = SET_BITS(x, pos, bits, value);
    gpio_write(GPIO_GPHEN1, x);

  } else {
    x = gpio_read(GPIO_GPHEN0);
    x = SET_BITS(x, gpio_no, bits, value);
    gpio_write(GPIO_GPHEN0, x);
  }
}/*gpio_set_HENn*/

void gpio_clear_HENn(unsigned int gpio_no) {

  unsigned int x    = 0;
  unsigned int pos  = 0;
  unsigned int bits = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPHEN1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = CLR_BITS(x, pos, bits);
    gpio_write(GPIO_GPHEN1, x);

  } else {
    x = gpio_read(GPIO_GPHEN0);
    x = CLR_BITS(x, gpio_no, bits);
    gpio_write(GPIO_GPHEN0, x);
  }
}/*gpio_clear_HENn*/

void gpio_set_LENn(unsigned int gpio_no) {

  unsigned int x     = 0;
  unsigned int value = 1;
  unsigned int pos   = 0;
  unsigned int bits  = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPLEN1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = SET_BITS(x, pos, bits, value);
    gpio_write(GPIO_GPLEN1, x);

  } else {
    x = gpio_read(GPIO_GPLEN0);
    x = SET_BITS(x, gpio_no, bits, value);
    gpio_write(GPIO_GPLEN0, x);
  }
}/*gpio_set_LENn*/

void gpio_clear_LENn(unsigned int gpio_no) {

  unsigned int x    = 0;
  unsigned int pos  = 0;
  unsigned int bits = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPLEN1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = CLR_BITS(x, pos, bits);
    gpio_write(GPIO_GPLEN1, x);

  } else {
    x = gpio_read(GPIO_GPLEN0);
    x = CLR_BITS(x, gpio_no, bits);
    gpio_write(GPIO_GPLEN0, x);
  }
}/*gpio_clear_LENn*/

void gpio_set_ARENn(unsigned int gpio_no) {

  unsigned int x     = 0;
  unsigned int value = 1;
  unsigned int pos   = 0;
  unsigned int bits  = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPAREN1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = SET_BITS(x, pos, bits, value);
    gpio_write(GPIO_GPAREN1, x);

  } else {
    x = gpio_read(GPIO_GPAREN0);
    x = SET_BITS(x, gpio_no, bits, value);
    gpio_write(GPIO_GPAREN0, x);
  }
}/*gpio_set_ARENn*/

void gpio_clear_ARENn(unsigned int gpio_no) {

  unsigned int x    = 0;
  unsigned int pos  = 0;
  unsigned int bits = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPAREN1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = CLR_BITS(x, pos, bits);
    gpio_write(GPIO_GPAREN1, x);

  } else {
    x = gpio_read(GPIO_GPAREN0);
    x = CLR_BITS(x, gpio_no, bits);
    gpio_write(GPIO_GPAREN0, x);
  }
}/*gpio_clear_ARENn*/

void gpio_set_AFENn(unsigned int gpio_no) {

  unsigned int x     = 0;
  unsigned int value = 1;
  unsigned int pos   = 0;
  unsigned int bits  = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPAFEN1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = SET_BITS(x, pos, bits, value);
    gpio_write(GPIO_GPAFEN1, x);

  } else {
    x = gpio_read(GPIO_GPAFEN0);
    x = SET_BITS(x, gpio_no, bits, value);
    gpio_write(GPIO_GPAFEN0, x);
  }
}/*gpio_set_AFENn*/

void gpio_clear_AFENn(unsigned int gpio_no) {

  unsigned int x    = 0;
  unsigned int pos  = 0;
  unsigned int bits = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPAFEN1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = CLR_BITS(x, pos, bits);
    gpio_write(GPIO_GPAFEN1, x);

  } else {
    x = gpio_read(GPIO_GPAFEN0);
    x = CLR_BITS(x, gpio_no, bits);
    gpio_write(GPIO_GPAFEN0, x);
  }
}/*gpio_clear_AFENn*/

void gpio_set_PUD(unsigned int value) {

  unsigned int x    = 0;
  unsigned int pos  = 1;
  unsigned int bits = 2;

  /*2 bits right from bit position 1 towards 0*/
  x = SET_BITS(x, pos, bits, value);
  gpio_write(GPIO_GPPUD, x);
}/*gpio_set_PUD*/

void gpio_set_PUDCLKn(unsigned int gpio_no) {

  unsigned int x     = 0;
  unsigned int value = 1;
  unsigned int pos   = 0;
  unsigned int bits  = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPPUDCLK1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = SET_BITS(x, pos, bits, value);
    gpio_write(GPIO_GPPUDCLK1, x);

  } else {
    x = gpio_read(GPIO_GPPUDCLK0);
    x = SET_BITS(x, gpio_no, bits, value);
    gpio_write(GPIO_GPPUDCLK0, x);
  }
}/*gpio_set_PUDCLKn*/

void gpio_clear_PUDCLKn(unsigned int gpio_no) {

  unsigned int x    = 0;
  unsigned int pos  = 0;
  unsigned int bits = 1;

  if(gpio_no > 32) {
    x = gpio_read(GPIO_GPPUDCLK1);
    /*Modulo 32*/
    pos = gpio_no & 31;
    x = CLR_BITS(x, pos, bits);
    gpio_write(GPIO_GPPUDCLK1, x);

  } else {
    x = gpio_read(GPIO_GPPUDCLK0);
    x = CLR_BITS(x, gpio_no, bits);
    gpio_write(GPIO_GPPUDCLK0, x);
  }
}/*gpio_clear_PUDCLKn*/

/*
 * @brief: For every c file, Linux Kernel requires the License
 *         description, if not provided then it prevents loading
 * @dated: 23-Jul-2018
 */

MODULE_VERSION("2.1");
MODULE_AUTHOR("Mohammed Naushad Ahmed");
MODULE_DESCRIPTION("Raspberry Pi3 Peripheral");
MODULE_LICENSE("GPL");

#endif /*__GPIO_C__*/
