#ifndef __RPI_C__
#define __RPI_C__

#include "common.h"
#include "rpi.h"

void rpi_write(unsigned int base_addr, 
               unsigned int offset, 
               unsigned int value) {

  volatile unsigned int *addr;
  addr  = (volatile unsigned int *)(base_addr + offset);
  *addr = value;
}/*rpi_write*/

unsigned int rpi_read(unsigned int base_addr, 
                      unsigned int offset) {

  volatile unsigned int *addr;
  addr = (volatile unsigned int *)(base_addr + offset);
  return(*addr);
}/*rpi_read*/

/*
 * @brief: For every c file, Linux Kernel requires the License
 *         description, if not provided then it prevents loading
 * @dated: 23-Jul-2018
 */

MODULE_VERSION("2.1");
MODULE_AUTHOR("Mohammed Naushad Ahmed");
MODULE_DESCRIPTION("Raspberry Pi3B Peripheral");
MODULE_LICENSE("GPL");

#endif /* __RPI_C__ */
