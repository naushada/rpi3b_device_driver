#ifndef __IVT_H__
#define __IVT_H__

#define IVT_RESET           (0x00 >> SHIFT)
#define IVT_UNDEF           (0x04 >> SHIFT)
#define IVT_SWI             (0x08 >> SHIFT)
#define IVT_PRE_FETCH_ABORT (0x0C >> SHIFT)
#define IVT_DATA_ABORT      (0x10 >> SHIFT)
#define IVT_RESERVED        (0x14 >> SHIFT)
#define IVT_IRQ             (0x18 >> SHIFT)
#define IVT_FIQ             (0x1C >> SHIFT)

/*B AL <address>*/
#define BAL   0xEA000000
/*LDR AL pc,<immediate address>*/
#define LDR   0xE59FF000

unsigned Install_Handler(unsigned int location, 
                         unsigned int *vector);

void IRQHandler(void);

void enable_IRQ(void);

void disable_IRQ(void);

unsigned int ivt_main(void);

#endif /* __IVT_H__ */
