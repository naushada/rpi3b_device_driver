#ifndef __IRQ_C__
#define __IRQ_C__

#include "common.h"
#include "rpi.h"
#include "irq.h"

static  irq_ctx_t g_ctx[64];

void irq_register(unsigned int irq_no, 
                  void (*irq_cb)(void *arg), 
                  void *arg) {

  irq_ctx_t *ctx_ptr = g_ctx;
  unsigned int x = 0;

  /*irq_no % 64*/
  ctx_ptr[irq_no & 63].irq_cb = irq_cb;
  ctx_ptr[irq_no & 63].arg    = arg;
  ctx_ptr[irq_no & 63].irq_no = irq_no;
 
  /*Enable the respective IRQ*/ 
  if(irq_no > 32) {

    x = rpi_read(RPI_IRQ_BASE, IRQ_ENABLE_IRQ2);
    x = SET_BITS(x, (irq_no - 32), 1, 1); 
    rpi_write(RPI_IRQ_BASE, IRQ_ENABLE_IRQ2, x);
    /*For debugging Purposes*/
    x = rpi_read(RPI_IRQ_BASE, IRQ_ENABLE_IRQ2);
    printk(KERN_INFO "After Enableing IRQ2_ENABLE value is 0x%X\n", x);

  } else {

    x = rpi_read(RPI_IRQ_BASE, IRQ_ENABLE_IRQ1);
    printk(KERN_INFO "IRQ1_ENABLE value is 0x%X\n", x);
    x = SET_BITS(x, irq_no, 1, 1); 
    rpi_write(RPI_IRQ_BASE, IRQ_ENABLE_IRQ1, x);

    /*For debugging Purposes*/
    x = rpi_read(RPI_IRQ_BASE, IRQ_ENABLE_IRQ1);
    printk(KERN_INFO "After Enableing IRQ1_ENABLE value is 0x%X\n", x);

  }

}/*irq_register*/

void irq_process(void) {

  unsigned int idx = 0;
  unsigned int x = 0;
  unsigned int y = 0;
  irq_ctx_t *ctx_ptr = g_ctx;

  x = rpi_read(RPI_IRQ_BASE, IRQ_IRQ_BASIC_PENDING);
  
  if(GET(IRQ_IRQ_BASIC_PENDING, PENDING1, x)) {
    /*One or more bits set in pending register 1*/
    y = rpi_read(RPI_IRQ_BASE, IRQ_IRQ_PENDING1);

    for(idx = 0; idx < 32; idx++) {

     if(GET_ex(IRQ_IRQ_PENDING1, IRQ, y, idx, 1)) {
       /*Interrupt source has been identified*/
       if(ctx_ptr[idx].irq_cb) {
         printk("\nRegistered call back invoked1\n");
         ctx_ptr[idx].irq_cb(ctx_ptr[idx].arg);
       }
     }
    }
  } 

  if(GET(IRQ_IRQ_BASIC_PENDING, PENDING2, x)) {
    /*One or more bits set in pending register 2*/
    y = rpi_read(RPI_IRQ_BASE, IRQ_IRQ_PENDING2);

    for(idx = 0; idx < 32; idx++) {
     if(GET_ex(IRQ_IRQ_PENDING2, IRQ, y, idx, 1)) {
       /*Interrupt source has been identified*/
       if(ctx_ptr[idx + 32].irq_cb) {
         printk("\nRegistered call back invoked2\n");
         ctx_ptr[idx + 32].irq_cb(ctx_ptr[idx + 32].arg);
       }
     }
    }
  }

}/*irq_process*/


MODULE_VERSION("2.1");
MODULE_AUTHOR("Mohammed Naushad Ahmed");
MODULE_DESCRIPTION("Raspberry Pi3B Peripheral");
MODULE_LICENSE("GPL");

#endif /* __IRQ_C__ */
