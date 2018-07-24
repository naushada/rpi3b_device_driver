#ifndef __UART0_C__
#define __UART0_C__


#include "common.h"
#include "rpi.h"
#include "uart.h"
#include "gpio.h"

unsigned int uart0_read_REG(unsigned int offset) {
  return(rpi_read(RPI_UART0_BASE, offset));
}/*uart0_read_REG*/

void uart0_program_REG(unsigned int offset, 
                       unsigned int value) {

  rpi_write(RPI_UART0_BASE, offset, value);
}/*uart0_program_REG*/

/* @brief:
    //integral_part = (48000000 / (baudrate * 16.0));
    //fractional_part =  ((baud_value - int_part) * 64) + 0.5;
    //Note: Kernel Module doesn't accept Floating Point operation

    1)//(3000000 / (16 * 115200) = 1.627 ==> IBRD=1
      //(0.627*64)+0.5 = 40 ==> FBRD=40
      //int 1 frac 40
    2)//(3000000 / (16 * 9600)) = 19.2 ==> IBRD=19
      //(0.53125 * 64 + 0.5) = 34.5 ==>FBRD=34.5
      UART_CLK is 48MHz, look for the Kernel command line argument by dmesg tailf
    3)//(48000000 / (16 * 9600)) = 312.5 = IBRD=312
      //(0.5 * 64 + 0.5) = 32
    4)//(48000000 / (16 * 115200) = 26.0416
      //(0.0416 * 64 + 0.5) = 3
 */
void uart0_set_baudrate(unsigned int baudrate) {
  unsigned int x = 0;
  /*Integer Part*/
  unsigned short int_part = 0x00;
  /*Fractional Part*/
  unsigned short fractional_part = 0x00;
  /*For 4.8 MHz*/
  int_part = 312;
  /*Four digits after decimal*/
  fractional_part =  32;

  /*Program Integral Part*/
  x = SET(UART0_IBRD, IBRD, x, int_part);
  printk("\nBefore Value of IBRD is 0x%X\n", x);
  uart0_program_REG(UART0_IBRD, x);
  printk("\nValue of IBRD is 0x%X\n", uart0_read_REG(UART0_IBRD));
  /*Program Fractional Part*/
  x = SET(UART0_FBRD, FBRD, x, fractional_part);
  printk("\nBefore Value of FBRD is 0x%X\n", x);
  uart0_program_REG(UART0_FBRD, x);
  printk("\nAfter Value of FBRD is 0x%X\n", uart0_read_REG(UART0_FBRD));
}/*uart0_set_baudrate*/


void uart0_disable(void) {
  unsigned int data = 0x00;

  data = uart0_read_REG(UART0_CR);
  data = CLR(UART0_CR, UARTEN, data);
  uart0_program_REG(UART0_CR, data);
}/*uart0_disable*/

void uart0_enable(void) {
  unsigned int value = 0x01;
  unsigned int data = 0x00;

  data = uart0_read_REG(UART0_CR);
  data = SET(UART0_CR, UARTEN, data, value);
  uart0_program_REG(UART0_CR, data);
}/*uart0_enable*/

void uart0_enable_tx(void) {
  unsigned int value = 0x00;
  unsigned int data = 0x01;

  data = uart0_read_REG(UART0_CR);
  data = SET(UART0_CR, TXE, data, value);
  uart0_program_REG(UART0_CR, data);
}/*uart0_enable_tx*/

void uart0_enable_rx(void) {
  unsigned int value = 0x01;
  unsigned int data = 0x00;

  data = uart0_read_REG(UART0_CR);
  data = SET(UART0_CR, RXE, data, value);
  uart0_program_REG(UART0_CR, data);
}/*uart0_enable_rx*/

void uart0_disable_tx(void) {
  unsigned int data = 0x00;

  data = uart0_read_REG(UART0_CR);
  data = CLR(UART0_CR, TXE, data);
  uart0_program_REG(UART0_CR, data);
}/*uart0_disable_tx*/

void uart0_disable_rx(void) {
  unsigned int data = 0x00;

  data = uart0_read_REG(UART0_CR);
  data = CLR(UART0_CR, RXE, data);
  uart0_program_REG(UART0_CR, data);
}/*uart0_disable_rx*/

void uart0_flush_fifo(void) {
  unsigned int data = 0x00;

  data = uart0_read_REG(UART0_LCRH);
  data = CLR(UART0_LCRH, FEN, data);
  uart0_program_REG(UART0_LCRH, data);
}/*uart0_flush_fifo*/

void uart0_enable_fifo(void) {
  unsigned int data = 0x00;
  unsigned int value = 0x01;

  data = uart0_read_REG(UART0_LCRH);
  data = SET(UART0_LCRH, FEN, data, value);
  uart0_program_REG(UART0_LCRH, data);
}/*uart0_enable_fifo*/

void uart0_send_data(unsigned char value) {
  unsigned int data = 0;

  data = SET(UART0_DR, DATA, data, value);
  uart0_program_REG(UART0_IMSC, data);
}/*uart0_send_data*/

void uart0_enable_rxintr(void) {
  unsigned int data = 0x00;
  unsigned int value = 0x01;

  data = uart0_read_REG(UART0_IMSC);
  data = SET(UART0_IMSC, RXIM, data, value);
  uart0_program_REG(UART0_IMSC, data);
}/*uart0_enable_rxintr*/

void uart0_disable_rxintr(void) {
  unsigned int data = 0x00;

  data = uart0_read_REG(UART0_IMSC);
  data = CLR(UART0_IMSC, RXIM, data);
  uart0_program_REG(UART0_IMSC, data);
}/*uart0_disable_rxintr*/

void uart0_main(void) {
  unsigned int data = 0;

  printk(KERN_INFO "\nBefore::Disable UART0\n");
  /*Disable the UART*/
  uart0_disable();
  printk(KERN_INFO "\nAfter::Disable UART0\n");
  /*GPIO-14 & Function Select as 
    000 = GPIO Pin 14 is an input
    001 = GPIO Pin 14 is an output
    100 = GPIO Pin 14 takes alternate function 0
    101 = GPIO Pin 14 takes alternate function 1
    110 = GPIO Pin 14 takes alternate function 2
    111 = GPIO Pin 14 takes alternate function 3
    011 = GPIO Pin 14 takes alternate function 4
    010 = GPIO Pin 14 takes alternate function 5*/
  gpio_set_FSELn(14/*GPIO14*/, 4/*ALT0*/);
  gpio_set_FSELn(15/*GPIO15*/, 4/*ALT0*/);

  /*Internal Pull/Pulldown on GPIO*/
  /*
   * PUD - GPIO Pin Pull-up/down
     00 = Off – disable pull-up/down
     01 = Enable Pull Down control
     10 = Enable Pull Up control
     11 = Reserved
     Use in conjunction with GPPUDCLK0/1/2
   */
  gpio_set_PUD(0);

  for(data = 0; data < 150; data++) {
    asm volatile("nop");
  }

  gpio_set_PUDCLKn(14);
  gpio_set_PUDCLKn(15);
  
  for(data = 0; data < 150; data++) {
    asm volatile("nop");
  }
  
  gpio_clear_PUDCLKn(14);
  gpio_clear_PUDCLKn(15);

    uart0_set_baudrate(9600);
  printk("\nSetting Baudrate\n");
  /*8Bits word, no Parity and no stop bits*/
  data = uart0_read_REG(UART0_LCRH);
  data |= SET(UART0_LCRH, WLEN, data, 0x03);
  uart0_program_REG(UART0_LCRH, data);

  uart0_enable_fifo();
  uart0_enable_tx();
  uart0_enable_rx();
  /*Enable RX-Interrupt*/
  uart0_enable_rxintr();
  printk("\nRx-Interrupt\n");
  uart0_enable();
  printk("\nEnable UART\n");
}/*uart0_main*/

/*
 * @brief: For every c file, Linux Kernel requires the License
 *         description, if not provided then it prevents loading
 * @dated: 23-Jul-2018
 */
MODULE_VERSION("2.1");
MODULE_AUTHOR("Mohammed Naushad Ahmed");
MODULE_DESCRIPTION("Raspberry Pi3B Peripheral");
MODULE_LICENSE("GPL");

#endif /*__UART0_C__*/
