#ifndef __IVT_C__
#define __IVT_C__

#include "common.h"
#include "rpi.h"
#include "ivt.h"
#include "irq.h"

/* Updates contents of 'vector' to contain LDR pc, [pc, #offset] */
/* instruction to cause long branch to address in `location'. */
/* Function return value is original contents of 'vector'. */
unsigned Install_Handler(unsigned int location, unsigned int *vector) {
  unsigned int vec;
  unsigned int oldvec;

  vec = (location - (*vector - 0x8)) | LDR;
  oldvec = *vector;
  *vector = vec;
  printk(KERN_INFO "Install Handler oldvec is 0x%X\n", oldvec);
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
  unsigned int ivt_vec = 0x00000018;
  void (*pIRQHandler)(void) = IRQHandler;

  ret_addr = rpi_read((unsigned int)RPI_IVT_BASE, IVT_IRQ);
  printk(KERN_INFO "IVT_IRQ Value is 0x%X Handler address is 0x%X\n", ret_addr, (unsigned int)pIRQHandler);

  ret_addr = rpi_read((unsigned int)RPI_IVT_BASE, IVT_FIQ);
  printk(KERN_INFO "IVT_FIQ Value is 0x%X Handler address is 0x%X\n", ret_addr, (unsigned int)pIRQHandler);

  ret_addr = Install_Handler((unsigned int)pIRQHandler, &ivt_vec);
  printk(KERN_INFO "Value of ivt_vec is 0x%X\n", ivt_vec);
  rpi_write((unsigned int)RPI_IVT_BASE, IVT_IRQ, ivt_vec);

  ret_addr = rpi_read((unsigned int)RPI_IVT_BASE, IVT_IRQ);
  printk(KERN_INFO "After Update IVT_IRQ Value is 0x%X\n", ret_addr);
  return(ret_addr);
}/*ivt_main*/


/*
 * @brief: For every c file, Linux Kernel requires the License
 *         description, if not provided then it prevents loading
 * @dated: 23-Jul-2018
 */

MODULE_VERSION("2.1");
MODULE_AUTHOR("Mohammed Naushad Ahmed");
MODULE_DESCRIPTION("Raspberry Pi3B Peripheral");
MODULE_LICENSE("GPL");

#endif /* __IVT_C__ */
