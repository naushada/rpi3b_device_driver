#ifndef __IRQ_H__
#define __IRQ_H__

typedef struct {
  void (*irq_cb)(void *arg);
  void *arg;
  unsigned int irq_no;

}irq_ctx_t;

#define IRQ_IRQ_BASIC_PENDING  ((0x200) >> SHIFT)
#define IRQ_IRQ_PENDING1       ((0x204) >> SHIFT)
#define IRQ_IRQ_PENDING2       ((0x208) >> SHIFT)
#define IRQ_FIQ_CONTROL        ((0x20C) >> SHIFT)
#define IRQ_ENABLE_IRQ1        ((0x210) >> SHIFT)
#define IRQ_ENABLE_IRQ2        ((0x214) >> SHIFT)
#define IRQ_ENABLE_BASIC_IRQ   ((0x218) >> SHIFT)
#define IRQ_DISABLE_IRQ1       ((0x21C) >> SHIFT)
#define IRQ_DISABLE_IRQ2       ((0x220) >> SHIFT)
#define IRQ_DISABLE_BASIC_IRQ  ((0x224) >> SHIFT)

#define IRQ_IRQ_BASIC_PENDING__GPU_IRQ62_GET(x)           GET_BITS((x), (20), (1)) 
#define IRQ_IRQ_BASIC_PENDING__GPU_IRQ57_GET(x)           GET_BITS((x), (19), (1)) 
#define IRQ_IRQ_BASIC_PENDING__GPU_IRQ56_GET(x)           GET_BITS((x), (18), (1)) 
#define IRQ_IRQ_BASIC_PENDING__GPU_IRQ55_GET(x)           GET_BITS((x), (17), (1)) 
#define IRQ_IRQ_BASIC_PENDING__GPU_IRQ54_GET(x)           GET_BITS((x), (16), (1)) 
#define IRQ_IRQ_BASIC_PENDING__GPU_IRQ53_GET(x)           GET_BITS((x), (15), (1)) 
#define IRQ_IRQ_BASIC_PENDING__GPU_IRQ19_GET(x)           GET_BITS((x), (14), (1)) 
#define IRQ_IRQ_BASIC_PENDING__GPU_IRQ18_GET(x)           GET_BITS((x), (13), (1)) 
#define IRQ_IRQ_BASIC_PENDING__GPU_IRQ10_GET(x)           GET_BITS((x), (12), (1)) 
#define IRQ_IRQ_BASIC_PENDING__GPU_IRQ9_GET(x)            GET_BITS((x), (11), (1)) 

#define IRQ_IRQ_BASIC_PENDING__PENDING2_GET(x)            GET_BITS((x), (9), (1)) 
#define IRQ_IRQ_BASIC_PENDING__PENDING1_GET(x)            GET_BITS((x), (8), (1)) 

#define IRQ_IRQ_BASIC_PENDING__MAILBOX_GET(x)             GET_BITS((x), (1), (1)) 
#define IRQ_IRQ_BASIC_PENDING__TIMER_GET(x)               GET_BITS((x), (0), (1)) 

/* Interrupt 0-31 IRQ bitmap
 * IRQ29 - meaning 29th bit is set is for Aux Int
 */
#define IRQ_IRQ_PENDING1__IRQ_GET(x, pos, bits)     GET_BITS((x), (pos), (bits)) 
/* Interrupt 32-63 IRQ bitmap
 * IRQ43 - i2c_spi_slv_int (bit = 43-32 = 11th bit is set)
 * IRQ45 - pwa0 (13th bit)
 * IRQ46 - pwa1 (14th bit)
 * IRQ48 - smi
 * IRQ49-IRQ52 -gpio_int[0 - 3] 
 * IRQ53 - i2c_int
 * IRQ54 - spi_int
 * IRQ55 - pcm_int
 * IRQ57 - uart_int
 */
#define IRQ_IRQ_PENDING2__IRQ_GET(x, pos, bits)     GET_BITS((x), (pos), (bits)) 

/*IRQs from IRQ0 - IRQ31 will be enabled by setting resprctive bit*/
#define IRQ_ENABLE_IRQ1__ENABLE_IRQ_GET(x)         GET_BITS((x), (31), (32)) 
#define IRQ_ENABLE_IRQ1__ENABLE_IRQ_SET(x, pos)    SET_BITS((x), (pos), (1), (1))

/*IRQs from IRQ32 - IRQ63 will be enabled by setting resprctive bit*/
#define IRQ_ENABLE_IRQ2__ENABLE_IRQ_GET(x)         GET_BITS((x), (31), (32)) 
#define IRQ_ENABLE_IRQ2__ENABLE_IRQ_SET(x, pos)    SET_BITS((x), (pos), (1), (1))

/*Basic IRQ controlls the IRQ1 & IRQ2*/
#define IRQ_ENABLE_BASIC_IRQ__ENABLE_IRQ_GET(x)         GET_BITS((x), (31), (32)) 
#define IRQ_ENABLE_BASIC_IRQ__ENABLE_IRQ_SET(x, value)  SET_BITS((x), (31), (32), (value))
#define IRQ_ENABLE_BASIC_IRQ__ENABLE_IRQ_CLR(x)         CLR_BITS((x), (31), (32))

/*IRQs from IRQ0 - IRQ31 will be disabled by setting resprctive bit*/
#define IRQ_DISABLE_IRQ1__DISABLE_IRQ_GET(x)         GET_BITS((x), (31), (32)) 
#define IRQ_DISABLE_IRQ1__DISABLE_IRQ_SET(x, value)  SET_BITS((x), (31), (32), (value))
#define IRQ_DISABLE_IRQ1__DISABLE_IRQ_CLR(x)         CLR_BITS((x), (31), (32))

/*IRQs from IRQ32 - IRQ63 will be disabled by setting resprctive bit*/
#define IRQ_DISABLE_IRQ2__DISABLE_IRQ_GET(x)         GET_BITS((x), (31), (32)) 
#define IRQ_DISABLE_IRQ2__DISABLE_IRQ_SET(x, value)  SET_BITS((x), (31), (32), (value))
#define IRQ_DISABLE_IRQ2__DISABLE_IRQ_CLR(x)         CLR_BITS((x), (31), (32))

/*Basic IRQ controlls the IRQ1 & IRQ2*/
#define IRQ_DISABLE_BASIC_IRQ__DISABLE_IRQ_GET(x)         GET_BITS((x), (31), (32)) 
#define IRQ_DISABLE_BASIC_IRQ__DISABLE_IRQ_SET(x, value)  SET_BITS((x), (31), (32), (value))
#define IRQ_DISABLE_BASIC_IRQ__DISABLE_IRQ_CLR(x)         CLR_BITS((x), (31), (32))



void irq_register(unsigned int irq_no, 
                  void (*irq_cb)(void *arg), 
                  void *arg);

void irq_process(void);

unsigned int irq_main(void);

#endif /* __IRQ_H__ */
