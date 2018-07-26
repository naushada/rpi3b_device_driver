#ifndef __MAIN_C__
#define __MAIN_C__

#include "common.h"
#include "gpio.h"
#include "ivt.h"
#include "irq.h"
#include "uart.h"
#include "cdev.h"

void Fn(void *arg) {
  printk(KERN_INFO "\nCallback is calledFn\n");
}/**/

#if 0
int main(int argc, char *argv[]) {
  unsigned char data_open[] = {0x55, 0xAA, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01};
  unsigned char data_on[] = {0x55, 0xAA, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x12, 0x00, 0x13, 0x01};
  unsigned int idx = 0;

  /*Initialization Part*/
  gpio_init();
  uart0_init();

  irq_init();
  //ivt_init();

  /*Processing*/
  fprintf(stderr, "\nEnable IRQ\n");
  //enable_IRQ();
  fprintf(stderr, "\nInstalling IVT\n");
  //ivt_main();
  fprintf(stderr, "\nEnabling Interrupt\n");
  irq_register(57, Fn, NULL);

  uart0_main();


  fprintf(stderr, "\nPress any Key to Open Sensor\n");
  getchar();

  for(idx = 0; idx < 12; idx++) {
   uart0_send_data(data_open[idx]); 
  }

  for(idx = 0; idx < 12; idx++) {
   uart0_send_data(data_on[idx]); 
  }
  fprintf(stderr, "\nWaiting for Char\n");
  getchar();
  printf("Hello World\n");a

  return(0);
}/*main*/

#endif

void main_init_driver(char *path_name) {

}/*main_init_driver*/

static int __init main_init(void)
{
  printk(KERN_INFO "RPI 3B CDEV Init\n");
  /*Initialize the character devices*/
  __cdev_init();

  //ivt_main();
  /*Initialization Part*/
  uart0_main();
  /*Non-zero return means that the module couldn't be loaded.*/
  return 0;    
}

static void __exit main_cleanup(void)
{
  printk(KERN_INFO "Cleaning up module.\n");
  __cdev_destroy();
}

module_init(main_init);
module_exit(main_cleanup);

MODULE_VERSION("2.1");
MODULE_AUTHOR("Mohammed Naushad Ahmed");
MODULE_DESCRIPTION("Raspberry Pi3B Peripheral");
MODULE_LICENSE("GPL");

#endif /* __MAIN_C__ */
