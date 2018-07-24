#ifndef __RPI_H__
#define __RPI_H__

/* @brief: 
    The ARM-side physical address where peripherals are mapped. This is 0x20000000 
    on the Pi Zero, Pi Zero W, and the first generation of the Raspberry Pi and Compute Module, 
    and 0x3f000000 on the Pi 2, Pi 3 and Compute Module 3
 */

/*
 * http://embedded-xinu.readthedocs.io/en/latest/arm/rpi/BCM2835-Interrupt-Controller.html
 */
typedef enum {
  /*GPIO Base Address*/
  RPI_GPIO_BASE  = 0x7E200000,
  /*PL011 UART - UART0*/
  RPI_UART0_BASE = 0x7E201000,
  /*This is Mini UART*/
  RPI_UART1_BASE = 0x7E215000,
  /*This is the only SPI*/
  RPI_SPI0_BASE  = 0x7E204000,
  /*This is Mini SPI1 & Mini SPI2*/
  RPI_SPI1_BASE  = RPI_UART1_BASE,
  RPI_SPI2_BASE  = RPI_UART1_BASE,

  RPI_I2C0_BASE  = 0x7E205000,
  RPI_I2C1_BASE  = 0x7E804000,
  /*I2C2 is reserver for HDMI*/

  RPI_DMA_CH0_BASE  = 0x7E007000, 
  RPI_DMA_CH1_BASE  = RPI_DMA_CH0_BASE + 0x100, 
  RPI_DMA_CH2_BASE  = RPI_DMA_CH0_BASE + 0x200, 
  RPI_DMA_CH3_BASE  = RPI_DMA_CH0_BASE + 0x300, 
  RPI_DMA_CH4_BASE  = RPI_DMA_CH0_BASE + 0x400, 
  RPI_DMA_CH5_BASE  = RPI_DMA_CH0_BASE + 0x500, 
  RPI_DMA_CH6_BASE  = RPI_DMA_CH0_BASE + 0x600, 
  RPI_DMA_CH7_BASE  = RPI_DMA_CH0_BASE + 0x700, 
  RPI_DMA_CH8_BASE  = RPI_DMA_CH0_BASE + 0x800, 
  RPI_DMA_CH9_BASE  = RPI_DMA_CH0_BASE + 0x900, 
  RPI_DMA_CH10_BASE = RPI_DMA_CH0_BASE + 0xA00, 
  RPI_DMA_CH11_BASE = RPI_DMA_CH0_BASE + 0xB00, 
  RPI_DMA_CH12_BASE = RPI_DMA_CH0_BASE + 0xC00, 
  RPI_DMA_CH13_BASE = RPI_DMA_CH0_BASE + 0xD00, 
  RPI_DMA_CH14_BASE = RPI_DMA_CH0_BASE + 0xE00, 

  /*External Mas Media Controller*/
  RPI_EMMC_BASE = 0x7E300000, 

  /*Clock Manager*/
  RPI_CM_BASE   = 0x7E101000,

  /*ARM Interrupt*/
  RPI_IRQ_BASE = 0x7E00B000,

  /*The only PCM Module*/
  RPI_PCM_BASE = 0x7E203000,
 
  /*This is the only SPI SLAVE/BSC*/
  RPI_SPI_S_BASE  = 0x7E214000,

  /*System Timer*/
  RPI_SYS_TIMER_BASE = 0x7E003000,

  /*Timer*/
  RPI_TIMER_BASE = 0x7E00B000,

  /*Interrupt Vector Offset*/
  RPI_IVT_BASE = 0xFFFF0000
}rpi_driver_offset_t;

void rpi_write(unsigned int base_addr, 
               unsigned int offset, 
               unsigned int value);

unsigned int rpi_read(unsigned int base_addr, 
                      unsigned int offset);

#endif /* __RPI_H__ */
