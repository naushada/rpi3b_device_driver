#ifndef __IVT_C__
#define __IVT_C__

#include "common.h"
#include "rpi.h"
#include "ivt.h"
#include "irq.h"

/* Updates contents of 'vector' to contain LDR pc, [pc, #offset] */
/* instruction to cause long branch to address in `location'. */
/* Function return value is original contents of 'vector'. */
unsigned Install_Handler(unsigned *location, unsigned int *vector) {
  unsigned int vec;
  unsigned int oldvec;

  vec = (unsigned)location - (((unsigned)vector - 0x8) | 0xe59ff000);
  oldvec = *vector;
  *vector = vec;
  printk("\nInstall Handler\n");
  return(oldvec);
}/*Install_Handler*/

#if 0
void ivt_restore_LR(void) {
  __asm (
      "MSR CPSR, SPSR\n\t"
      "MOV PC, LR\n\t"
    );

}/*ivt_restore_LR*/
#endif

void IRQHandler(void) {
  irq_process();
  //ivt_restore_LR();

}/*IRQHandler*/


/* Enabling and disabling interrupts
Interrupts are enabled or disabled by reading the cpsr flags
and updating bit 7.
These functions work only in a privileged mode, because the
control bits of the cpsr and spsr cannot be changed while in
User mode.
*/
void enable_IRQ(void) {
  __asm (
      "MRS R0, CPSR\n\t"
      "BIC R0, R0, #0x80\n\t"
      "MSR CPSR_c, R0\n\t"
    );
}/**/


void disable_IRQ(void) {
  __asm (
      "MRS R0, CPSR\n\t"
      "ORR R0, R0, #0x80\n\r"
      "MSR CPSR_c, R0\r\n"
    );
}/*disable_IRQ*/


unsigned int ivt_main(void) {
  unsigned int ret_addr; 
  unsigned int ivt_vec = 0x0;
  unsigned pIRQHandler = (unsigned)IRQHandler;

  ret_addr = rpi_read((unsigned int)RPI_IVT_BASE, IVT_IRQ);
  printk(KERN_INFO "IVT_IRQ Value is 0x%X\n", ret_addr);

  ret_addr = Install_Handler(&pIRQHandler, &ivt_vec);
  rpi_write((unsigned int)RPI_IVT_BASE, IVT_IRQ, ivt_vec);

  return(ret_addr);
}/*ivt_main*/


/*
 * @brief: For every c file, Linux Kernel requires the License
 *         description, if not provided then it prevents loading
 * @dated: 23-Jul-2018
 */

MODULE_VERSION("2.1");
MODULE_AUTHOR("Mohammed Naushad Ahmed");
MODULE_DESCRIPTION("Raspberry Pi3 Peripheral");
MODULE_LICENSE("GPL");

#endif /* __IVT_C__ */
