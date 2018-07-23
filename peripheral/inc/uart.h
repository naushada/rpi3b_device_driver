#ifndef __UART_H__
#define __UART_H__

/*UART0 is PL011 UART Register's Address*/
#define UART0_DR      (0x00 >> SHIFT)
#define UART0_RSRECR  (0x04 >> SHIFT)
#define UART0_FR      (0x18 >> SHIFT)
#define UART0_ILPR    (0x20 >> SHIFT)
#define UART0_IBRD    (0x24 >> SHIFT)
#define UART0_FBRD    (0x28 >> SHIFT)
#define UART0_LCRH    (0x2C >> SHIFT)
#define UART0_CR      (0x30 >> SHIFT)
#define UART0_IFLS    (0x34 >> SHIFT)
#define UART0_IMSC    (0x38 >> SHIFT)
#define UART0_RIS     (0x3C >> SHIFT)
#define UART0_MIS     (0x40 >> SHIFT)
#define UART0_ICR     (0x44 >> SHIFT)
#define UART0_DMACR   (0x48 >> SHIFT)
#define UART0_ITCR    (0x80 >> SHIFT)
#define UART0_ITIP    (0x84 >> SHIFT)
#define UART0_ITOP    (0x88 >> SHIFT)
#define UART0_TDR     (0x8C >> SHIFT)

/*DR - Data Register Break up*/
#define UART0_DR__DATA_GET(x)         GET_BITS((x), (7), (8))
#define UART0_DR__DATA_SET(x, value)  SET_BITS((x), (7), (8), (value))
#define UART0_DR__DATA_CLR(x)         CLR_BITS((x), (7), (8))

#define UART0_DR__FE_GET              GET_BITS((x), (8), (1))
#define UART0_DR__FE_SET              SET_BITS((x), (8), (1), (value))
#define UART0_DR__FE_CLR              CLR_BITS((x), (8), (1))

#define UART0_DR__PE_GET(x)           GET_BITS((x), (9), (1))
#define UART0_DR__PE_SET(x, value)    SET_BITS((x), (9), (1), (value)) 
#define UART0_DR__PE_CLR(x)           CLR_BITS((x), (9), (1))

#define UART0_DR__BE_GET(x)           GET_BITS((x), (10), (1))           
#define UART0_DR__BE_SET(x, value)    SET_BITS((x), (10), (1), (value))      
#define UART0_DR__BE_CLR(x)           CLR_BITS((x), (10), (1))

#define UART0_DR__OE_GET(x)           GET_BITS((x), (11), (1))           
#define UART0_DR__OE_SET(x, value)    SET_BITS((x), (11), (1), (value))          
#define UART0_DR__OE_CLR(x)           CLR_BITS((x), (11), (1))

/*RSRECR - Break up*/
#define UART0_RSRECR__FE_GET(x)         GET_BITS((x), (0), (1))                    
#define UART0_RSRECR__FE_SET(x, value)  SET_BITS((x), (0), (1), (value))          
#define UART0_RSRECR__FE_CLR(x)         CLR_BITS((x), (0), (1))

#define UART0_RSRECR__PE_GET(x)         GET_BITS((x), (1), (1))                    
#define UART0_RSRECR__PE_SET(x, value)  SET_BITS((x), (1), (1), (value))          
#define UART0_RSRECR__PE_CLR(x)         CLR_BITS((x), (1), (1))

#define UART0_RSRECR__BE_GET(x)         GET_BITS((x), (2), (1))                    
#define UART0_RSRECR__BE_SET(x, value)  SET_BITS((x), (2), (1), (value))          
#define UART0_RSRECR__BE_CLR(x)         CLR_BITS((x), (2), (1))

#define UART0_RSRECR__OE_GET(x)         GET_BITS((x), (3), (1))                    
#define UART0_RSRECR__OE_SET(x, value)  SET_BITS((x), (3), (1), (value))          
#define UART0_RSRECR__OE_CLR(x)         CLR_BITS((x), (3), (1))

/*FR Register's Break up*/

#define UART0_FR__RI_GET(x)             GET_BITS((x), (8), (1))                     
#define UART0_FR__RI_SET(x, value)      SET_BITS((x), (8), (1), (value))          
#define UART0_FR__RI_CLR(x)             CLR_BITS((x), (8), (1))

#define UART0_FR__TXFE_GET(x)           GET_BITS((x), (7), (1))                    
#define UART0_FR__TXFE_SET(x, value)    SET_BITS((x), (7), (1), (value))          
#define UART0_FR__TXFE_CLR(x)           CLR_BITS((x), (7), (1))

#define UART0_FR__RXFF_GET(x)           GET_BITS((x), (6), (1))                     
#define UART0_FR__RXFF_SET(x, value)    SET_BITS((x), (6), (1), (value))          
#define UART0_FR__RXFF_CLR(x)           CLR_BITS((x), (6), (1))

#define UART0_FR__TXFF_GET(x)           GET_BITS((x), (5), (1))                     
#define UART0_FR__TXFF_SET(x, value)    SET_BITS((x), (5), (1), (value))          
#define UART0_FR__TXFF_CLR(x)           CLR_BITS((x), (5), (1))

#define UART0_FR__RXFE_GET(x)           GET_BITS((x), (4), (1))                     
#define UART0_FR__RXFE_SET(x, value)    SET_BITS((x), (4), (1), (value))          
#define UART0_FR__RXFE_CLR(x)           CLR_BITS((x), (4), (1))

#define UART0_FR__BUSY_GET(x)           GET_BITS((x), (3), (1))                    
#define UART0_FR__BUSY_SET(x, value)    SET_BITS((x), (3), (1), (value))          
#define UART0_FR__BUSY_CLR(x)           CLR_BITS((x), (3), (1))

#define UART0_FR__DCD_GET(x)            GET_BITS((x), (2), (1))                     
#define UART0_FR__DCD_SET(x, value)     SET_BITS((x), (2), (1), (value))          
#define UART0_FR__DCD_CLR(x)            CLR_BITS((x), (2), (1))

#define UART0_FR__DSR_GET(x)            GET_BITS((x), (1), (1))                     
#define UART0_FR__DSR_SET(x, value)     SET_BITS((x), (1), (1), (value))          
#define UART0_FR__DSR_CLR(x)            CLR_BITS((x), (1), (1))

#define UART0_FR__CTS_GET(x)            GET_BITS((x), (0), (1))                     
#define UART0_FR__CTS_SET(x, value)     SET_BITS((x), (0), (1), (value))          
#define UART0_FR__CTS_CLR(x)            CLR_BITS((x), (0), (1))


/*ILPR Register's Break up*/
#define UART0_ILPR__ILPR_GET(x)             GET_BITS((x), (31), (32))                     
#define UART0_ILPR__ILPR_SET(x, value)      SET_BITS((x), (31), (32), (value))          
#define UART0_ILPR__ILPR_CLR(x)             CLR_BITS((x), (31), (32))

/*IBRD Register's Break up*/
#define UART0_IBRD__IBRD_GET(x)             GET_BITS((x), (15), (16))                     
#define UART0_IBRD__IBRD_SET(x, value)      SET_BITS((x), (15), (16), (value))          
#define UART0_IBRD__IBRD_CLR(x)             CLR_BITS((x), (15), (16))

/*FBRD Register's break up*/
#define UART0_FBRD__FBRD_GET(x)             GET_BITS((x), (5), (6))                     
#define UART0_FBRD__FBRD_SET(x, value)      SET_BITS((x), (5), (6), (value))          
#define UART0_FBRD__FBRD_CLR(x)             CLR_BITS((x), (5), (6))


/*LCRH Register's details*/

#define UART0_LCRH__SPS_GET(x)              GET_BITS((x), (7), (1))                      
#define UART0_LCRH__SPS_SET(x, value)       SET_BITS((x), (7), (1), (value))                  
#define UART0_LCRH__SPS_CLR(x)              CLR_BITS((x), (7), (1))

#define UART0_LCRH__WLEN_GET(x)             GET_BITS((x), (6), (2))                      
#define UART0_LCRH__WLEN_SET(x, value)      SET_BITS((x), (6), (2), (value))          
#define UART0_LCRH__WLEN_CLR(x)             CLR_BITS((x), (6), (2))

#define UART0_LCRH__FEN_GET(x)              GET_BITS((x), (4), (1))                     
#define UART0_LCRH__FEN_SET(x, value)       SET_BITS((x), (4), (1), (value))          
#define UART0_LCRH__FEN_CLR(x)              CLR_BITS((x), (4), (1))

#define UART0_LCRH__STP2_GET(x)             GET_BITS((x), (3), (1))                     
#define UART0_LCRH__STP2_SET(x, value)      SET_BITS((x), (3), (1), (value))          
#define UART0_LCRH__STP2_CLR(x)             CLR_BITS((x), (3), (1))

#define UART0_LCRH__EPS_GET(x)              GET_BITS((x), (2), (1))                     
#define UART0_LCRH__EPS_SET(x, value)       SET_BITS((x), (2), (1), (value))          
#define UART0_LCRH__EPS_CLR(x)              CLR_BITS((x), (2), (1))

#define UART0_LCRH__PEN_GET(x)              GET_BITS((x), (1), (1))                      
#define UART0_LCRH__PEN_SET(x, value)       SET_BITS((x), (1), (1), (value))          
#define UART0_LCRH__PEN_CLR(x)              CLR_BITS((x), (1), (1))

#define UART0_LCRH__BRK_GET(x)              GET_BITS((x), (0), (1))                      
#define UART0_LCRH__BRK_SET(x, value)       SET_BITS((x), (0), (1), (value))          
#define UART0_LCRH__BRK_CLR(x)              CLR_BITS((x), (0), (1))

/*CR Register's Break UP*/
#define UART0_CR__CTSEN_GET(x)              GET_BITS((x), (15), (1))                      
#define UART0_CR__CTSEN_SET(x, value)       SET_BITS((x), (15), (1), (value))          
#define UART0_CR__CTSEN_CLR(x)              CLR_BITS((x), (15), (1))

#define UART0_CR__RTSEN_GET(x)              GET_BITS((x), (14), (1))                      
#define UART0_CR__RTSEN_SET(x, value)       SET_BITS((x), (14), (1), (value))          
#define UART0_CR__RTSEN_CLR(x)              CLR_BITS((x), (14), (1))

#define UART0_CR__OUT2_GET(x)               GET_BITS((x), (13), (1))                      
#define UART0_CR__OUT2_SET(x, value)        SET_BITS((x), (13), (1), (value))          
#define UART0_CR__OUT2_CLR(x)               CLR_BITS((x), (13), (1))

#define UART0_CR__OUT1_GET(x)               GET_BITS((x), (12), (1))                      
#define UART0_CR__OUT1_SET(x, value)        SET_BITS((x), (12), (1), (value))          
#define UART0_CR__OUT1_CLR(x)               CLR_BITS((x), (12), (1))

#define UART0_CR__RTS_GET(x)                GET_BITS((x), (11), (1))                      
#define UART0_CR__RTS_SET(x, value)         SET_BITS((x), (11), (1), (value))          
#define UART0_CR__RTS_CLR(x)                CLR_BITS((x), (11), (1))

#define UART0_CR__DTR_GET(x)                GET_BITS((x), (10), (1))                      
#define UART0_CR__DTR_SET(x, value)         SET_BITS((x), (10), (1), (value))          
#define UART0_CR__DTR_CLR(x)                CLR_BITS((x), (10), (1))

#define UART0_CR__RXE_GET(x)                GET_BITS((x), (9), (1))                      
#define UART0_CR__RXE_SET(x, value)         SET_BITS((x), (9), (1), (value))          
#define UART0_CR__RXE_CLR(x)                CLR_BITS((x), (9), (1))

#define UART0_CR__TXE_GET(x)                GET_BITS((x), (8), (1))                      
#define UART0_CR__TXE_SET(x, value)         SET_BITS((x), (8), (1), (value))          
#define UART0_CR__TXE_CLR(x)                CLR_BITS((x), (8), (1))

#define UART0_CR__LBE_GET(x)                GET_BITS((x), (7), (1))                      
#define UART0_CR__LBE_SET(x, value)         SET_BITS((x), (7), (1), (value))          
#define UART0_CR__LBE_CLR(x)                CLR_BITS((x), (7), (1))

#define UART0_CR__SIRLP_GET(x)              GET_BITS((x), (2), (1))                      
#define UART0_CR__SIRLP_SET(x, value)       SET_BITS((x), (2), (1), (value))          
#define UART0_CR__SIRLP_CLR(x)              CLR_BITS((x), (2), (1))

#define UART0_CR__SIREN_GET(x)              GET_BITS((x), (1), (1))                      
#define UART0_CR__SIREN_SET(x, value)       SET_BITS((x), (1), (1), (value))          
#define UART0_CR__SIREN_CLR(x)              CLR_BITS((x), (1), (1))

#define UART0_CR__UARTEN_GET(x)             GET_BITS((x), (0), (1))
#define UART0_CR__UARTEN_SET(x, value)      SET_BITS((x), (0), (1), (value))
#define UART0_CR__UARTEN_CLR(x)             CLR_BITS((x), (0), (1))

/*IFLS Register's break up*/
#define UART0_IFLS__RXIFPSEL_GET(x)         GET_BITS((x), (11), (3))
#define UART0_IFLS__RXIFPSEL_SET(x, value)  SET_BITS((x), (11), (3), (value))
#define UART0_IFLS__RXIFPSEL_CLR(x)         CLR_BITS((x), (11), (3))

#define UART0_IFLS__TXIFPSEL_GET(x)         GET_BITS((x), (8), (3))
#define UART0_IFLS__TXIFPSEL_SET(x, value)  SET_BITS((x), (8), (3), (value))
#define UART0_IFLS__TXIFPSEL_CLR(x)         CLR_BITS((x), (8), (3))

#define UART0_IFLS__RXIFLSEL_GET(x)         GET_BITS((x), (5), (3))
#define UART0_IFLS__RXIFLSEL_ST(x, value)   SET_BITS((x), (5), (3), (value))
#define UART0_IFLS__RXIFLSEL_CLR(x)         CLR_BITS((x), (5), (3))

#define UART0_IFLS__TXIFLSEL_GET(x)         GET_BITS((x), (2), (3))
#define UART0_IFLS__TXIFLSEL_SET(x, value)  SET_BITS((x), (2), (3), (value))
#define UART0_IFLS__TXIFLSEL_CLR(x)         CLR_BITS((x), (2), (3))

/*IMSC Register's break up*/
#define UART0_IMSC__OEIM_GET(x)             GET_BITS((x), (10), (1))
#define UART0_IMSC__OEIM_SET(x, value)      SET_BITS((x), (10), (1), (value))
#define UART0_IMSC__OEIM_CLR(x)             CLR_BITS((x), (10), (1))

#define UART0_IMSC__BEIM_GET(x)             GET_BITS((x), (9), (1))          
#define UART0_IMSC__BEIM_SET(x, value)      SET_BITS((x), (9), (1), (value))  
#define UART0_IMSC__BEIM_CLR(x)             CLR_BITS((x), (9), (1))

#define UART0_IMSC__PEIM_GET(x)             GET_BITS((x), (8), (1))
#define UART0_IMSC__PEIM_SET(x, value)      SET_BITS((x), (8), (1), (value))  
#define UART0_IMSC__PEIM_CLR(x)             CLR_BITS((x), (8), (1))

#define UART0_IMSC__FEIM_GET(x)             GET_BITS((x), (7), (1))
#define UART0_IMSC__FEIM_SET(x, value)      SET_BITS((x), (7), (1), (value))  
#define UART0_IMSC__FEIM_CLR(x)             CLR_BITS((x), (7), (1))

#define UART0_IMSC__RTIM_GET(x)             GET_BITS((x), (6), (1))
#define UART0_IMSC__RTIM_SET(x, value)      SET_BITS((x), (6), (1), (value))  
#define UART0_IMSC__RTIM_CLR(x)             CLR_BITS((x), (6), (1))

#define UART0_IMSC__TXIM_GET(x)             GET_BITS((x), (5), (1))
#define UART0_IMSC__TXIM_SET(x, value)      SET_BITS((x), (5), (1), (value))  
#define UART0_IMSC__TXIM_CLR(x)             CLR_BITS((x), (5), (1))

#define UART0_IMSC__RXIM_GET(x)             GET_BITS((x), (4), (1))          
#define UART0_IMSC__RXIM_SET(x, value)      SET_BITS((x), (4), (1), (value))  
#define UART0_IMSC__RXIM_CLR(x)             CLR_BITS((x), (4), (1))

#define UART0_IMSC__DSRMIM_GET(x)           GET_BITS((x), (3), (1))          
#define UART0_IMSC__DSRMIM_SET(x, value)    SET_BITS((x), (3), (1), (value))  
#define UART0_IMSC__DSRMIM_CLR(x)           CLR_BITS((x), (3), (1))

#define UART0_IMSC__DCDMIM_GET(x)           GET_BITS((x), (2), (1))          
#define UART0_IMSC__DCDMIM_SET(x, value)    SET_BITS((x), (2), (1), (value))  
#define UART0_IMSC__DCDMIM_CLR(x)           CLR_BITS((x), (2), (1))

#define UART0_IMSC__CTSMIM_GET(x)           GET_BITS((x), (1), (1))          
#define UART0_IMSC__CTSMIM_SET(x, value)    SET_BITS((x), (1), (1), (value))   
#define UART0_IMSC__CTSMIM_CLR(x)           CLR_BITS((x), (1), (1))

#define UART0_IMSC__RIMIM_GET(x)            GET_BITS((x), (0), (1))          
#define UART0_IMSC__RIMIM_SET(x, value)     SET_BITS((x), (0), (1), (value))   
#define UART0_IMSC__RIMIM_CLR(x)            CLR_BITS((x), (0), (1))

/*RIS Regisater's break up*/
#define UART0_RIS__OERIS_GET(x)             GET_BITS((x), (10), (1))             
#define UART0_RIS__OERIS_SET(x, value)      SET_BITS((x), (10), (1), (value))   
#define UART0_RIS__OERIS_CLR(x)             CLR_BITS((x), (10), (1))

#define UART0_RIS__BERIS_GET(x)             GET_BITS((x), (9), (1))             
#define UART0_RIS__BERIS_SET(x, value)      SET_BITS((x), (9), (1), (value))   
#define UART0_RIS__BERIS_CLR(x)             CLR_BITS((x), (9), (1))

#define UART0_RIS__PERIS_GET(x)             GET_BITS((x), (8), (1))             
#define UART0_RIS__PERIS_SET(x, value)      SET_BITS((x), (8), (1), (value))   
#define UART0_RIS__PERIS_CLR(x)             CLR_BITS((x), (8), (1))

#define UART0_RIS__FERIS_GET(x)             GET_BITS((x), (7), (1))             
#define UART0_RIS__FERIS_SET(x, value)      SET_BITS((x), (7), (1), (value))   
#define UART0_RIS__FERIS_CLR(x)             CLR_BITS((x), (7), (1))

#define UART0_RIS__RTRIS_GET(x)             GET_BITS((x), (6), (1))             
#define UART0_RIS__RTRIS_SET(x, value)      SET_BITS((x), (6), (1), (value))   
#define UART0_RIS__RTRIS_CLR(x)             CLR_BITS((x), (6), (1))

#define UART0_RIS__TXRIS_GET(x)             GET_BITS((x), (5), (1))             
#define UART0_RIS__TXRIS_SET(x, value)      SET_BITS((x), (5), (1), (value))   
#define UART0_RIS__TXRIS_CLR(x)             CLR_BITS((x), (5), (1))

#define UART0_RIS__RXRIS_GET(x)             GET_BITS((x), (4), (1))             
#define UART0_RIS__RXRIS_SET(x, value)      SET_BITS((x), (4), (1), (value))   
#define UART0_RIS__RXRIS_CLR(x)             CLR_BITS((x), (4), (1))

#define UART0_RIS__DSRRMIS_GET(x)           GET_BITS((x), (3), (1))             
#define UART0_RIS__DSRRMIS_SET(x, value)    SET_BITS((x), (3), (1), (value))   
#define UART0_RIS__DSRRMIS_CLR(x)           CLR_BITS((x), (3), (1))

#define UAR0_RIS__DCDRMIS_GET(x)            GET_BITS((x), (2), (1))          
#define UAR0_RIS__DCDRMIS_SET(x, value)     SET_BITS((x), (2), (1), (value))   
#define UAR0_RIS__DCDRMIS_CLR(x)            CLR_BITS((x), (2), (1))

#define UART0_RIS_CTSRMIS_GET(x)            GET_BITS((x), (1), (1))             
#define UART0_RIS_CTSRMIS_SET(x, value)     SET_BITS((x), (1), (1), (value))   
#define UART0_RIS_CTSRMIS_CLR(x)            CLR_BITS((x), (1), (1))

#define UART0_RIS__RIRMIS_GET(x)            GET_BITS((x), (0), (1))             
#define UART0_RIS__RIRMIS_SET(x, value)     SET_BITS((x), (0), (1), (value))    
#define UART0_RIS__RIRMIS_CLR(x)            CLR_BITS((x), (0), (1))

/*MIS Register's break up*/
#define UART0_MIS__OEMIS_GET(x)             GET_BITS((x), (10), (1))             
#define UART0_MIS__OEMIS_SET(x, value)      SET_BITS((x), (10), (1), (value))    
#define UART0_MIS__OEMIS_CLR(x)             CLR_BITS((x), (10), (1))

#define UART0_MIS__BEMIS_GET(x)             GET_BITS((x), (9), (1))             
#define UART0_MIS__BEMIS_SET(x, value)      SET_BITS((x), (9), (1), (value))    
#define UART0_MIS__BEMIS_CLR(x)             CLR_BITS((x), (9), (1))

#define UART0_MIS__PEMIS_GET(x)             GET_BITS((x), (8), (1))             
#define UART0_MIS__PEMIS_SET(x, value)      SET_BITS((x), (8), (1), (value))    
#define UART0_MIS__PEMIS_CLR(x)             CLR_BITS((x), (8), (1))

#define UART0_MIS__FEMIS_GET(x)             GET_BITS((x), (7), (1))             
#define UART0_MIS__FEMIS_SET(x, value)      SET_BITS((x), (7), (1), (value))    
#define UART0_MIS__FEMIS_CLR(x)             CLR_BITS((x), (7), (1))

#define UART0_MIS__RTMIS_GET(x)             GET_BITS((x), (6), (1))             
#define UART0_MIS__RTMIS_SET(x, value)      SET_BITS((x), (6), (1), (value))    
#define UART0_MIS__RTMIS_CLR(x)             CLR_BITS((x), (6), (1))

#define UART0_MIS__TXMIS_GET(x)             GET_BITS((x), (5), (1))             
#define UART0_MIS__TXMIS_SET(x, value)      SET_BITS((x), (5), (1), (value))    
#define UART0_MIS__TXMIS_CLR(x)             CLR_BITS((x), (5), (1))

#define UART0_MIS__RXMIS_GET(x)             GET_BITS((x), (4), (1))             
#define UART0_MIS__RXMIS_SET(x, value)      SET_BITS((x), (4), (1), (value))    
#define UART0_MIS__RXMIS_CLR(x)             CLR_BITS((x), (4), (1))

#define UART0_MIS__DSRMMIS_GET(x)           GET_BITS((x), (3), (1))             
#define UART0_MIS__DSRMMIS_SET(x, value)    SET_BITS((x), (3), (1), (value))    
#define UART0_MIS__DSRMMIS_CLR(x)           CLR_BITS((x), (3), (1))

#define UART0_MIS__DCDMMIS_GET(x)           GET_BITS((x), (2), (1))             
#define UART0_MIS__DCDMMIS_SET(x, value)    SET_BITS((x), (2), (1), (value))    
#define UART0_MIS__DCDMMIS_CLR(x)           CLR_BITS((x), (2), (1))

#define UART0_MIS__CTSMMIS_GET(x)           GET_BITS((x), (1), (1))             
#define UART0_MIS__CTSMMIS_SET(x, value)    SET_BITS((x), (1), (1), (value))    
#define UART0_MIS__CTSMMIS_CLR(x)           CLR_BITS((x), (1), (1))

#define UART0_MIS__RIMMIS_GET(x)            GET_BITS((x), (0), (1))              
#define UART0_MIS__RIMMIS_SET(x, value)     SET_BITS((x), (0), (1), (value))    
#define UART0_MIS__RIMMIS_CLR(x)            CLR_BITS((x), (0), (1))

/*ICR Register's break up*/
#define UART0_ICR__OEIC_GET(x)              GET_BITS((x), (10), (1))              
#define UART0_ICR__OEIC_SET(x, value)       SET_BITS((x), (10), (1), (value))    
#define UART0_ICR__OEIC_CLR(x)              CLR_BITS((x), (10), (1))

#define UART0_ICR__BEIC_GET(x)              GET_BITS((x), (9), (1))             
#define UART0_ICR__BEIC_SET(x, value)       SET_BITS((x), (9), (1), (value))    
#define UART0_ICR__BEIC_CLR(x)              CLR_BITS((x), (9), (1))

#define UART0_ICR__PEIC_GET(x)              GET_BITS((x), (8), (1))             
#define UART0_ICR__PEIC_SET(x, value)       SET_BITS((x), (8), (1), (value))    
#define UART0_ICR__PEIC_CLR(x)              CLR_BITS((x), (8), (1))

#define UART0_ICR__FEIC_GET(x)              GET_BITS((x), (7), (1))             
#define UART0_ICR__FEIC_SET(x, value)       SET_BITS((x), (7), (1), (value))    
#define UART0_ICR__FEIC_CLR(x)              CLR_BITS((x), (7), (1))

#define UART0_ICR__RTIC_GET(x)              GET_BITS((x), (6), (1))              
#define UART0_ICR__RTIC_SET(x, value)       SET_BITS((x), (6), (1), (value))    
#define UART0_ICR__RTIC_CLR(x)              CLR_BITS((x), (6), (1))

#define UART0_ICR__TXIC_GET(x)              GET_BITS((x), (5), (1))              
#define UART0_ICR__TXIC_SET(x, value)       SET_BITS((x), (5), (1), (value))    
#define UART0_ICR__TXIC_CLR(x)              CLR_BITS((x), (5), (1))

#define UART0_ICR__RXIC_GET(x)              GET_BITS((x), (4), (1))              
#define UART0_ICR__RXIC_SET(x, value)       SET_BITS((x), (4), (1), (value))    
#define UART0_ICR__RXIC_CLR(x)              CLR_BITS((x), (4), (1))

#define UART0_ICR__DSRMIC_GET(x)            GET_BITS((x), (3), (1))              
#define UART0_ICR__DSRMIC_SET(x, value)     SET_BITS((x), (3), (1), (value))    
#define UART0_ICR__DSRMIC_CLR(x)            CLR_BITS((x), (3), (1))

#define UART0_ICR__DCDMIC_GET(x)            GET_BITS((x), (2), (1))              
#define UART0_ICR__DCDMIC_SET(x, value)     SET_BITS((x), (2), (1), (value))    
#define UART0_ICR__DCDMIC_CLR(x)            CLR_BITS((x), (2), (1))

#define UART0_ICR__CTSMIC_GET(x)            GET_BITS((x), (2), (1))              
#define UART0_ICR__CTSMIC_SET(x, value)     SET_BITS((x), (2), (1), (value))    
#define UART0_ICR__CTSMIC_CLR(x)            CLR_BITS((x), (2), (1))

#define UART0_ICR__RIMIC_GET(x)             GET_BITS((x), (0), (1))              
#define UART0_ICR__RIMIC_SET(x, value)      SET_BITS((x), (0), (1), (value))    
#define UART0_ICR__RIMIC_CLR(x)             CLR_BITS((x), (0), (1))

/*ITCR register's break up*/
#define UART0_ITCR__ITCR1_GET(x)            GET_BITS((x), (1), (1))             
#define UART0_ITCR__ITCR1_SET(x, value)     SET_BITS((x), (1), (1), (value))    
#define UART0_ITCR__ITCR1_CLR(x)            CLR_BITS((x), (1), (1))

#define UART0_ITCR__ITCR0_GET(x)            GET_BITS((x), (0), (1))             
#define UART0_ITCR__ITCR0_SET(x, value)     SET_BITS((x), (0), (1), (value))    
#define UART0_ITCR__ITCR0_CLR(x)            CLR_BITS((x), (0), (1))

/*ITIP Register's break up*/
#define UART0_ITIP__ITIP3_GET(x)            GET_BITS((x), (3), (1))             
#define UART0_ITIP__ITIP3_SET(x, value)     SET_BITS((x), (3), (1), (value))    
#define UART0_ITIP__ITIP3_CLR(x)            CLR_BITS((x), (3), (1))

#define UART0_ITIP__ITIP0_GET(x)            GET_BITS((x), (0), (1))              
#define UART0_ITIP__ITIP0_SET(x, value)     SET_BITS((x), (0), (1), (value))    
#define UART0_ITIP__ITIP0_CLR(x)            CLR_BITS((x), (0), (1))


/*ITOP Register's break up*/
#define UART0_ITOP__ITOP11_GET(x)           GET_BITS((x), (11), (1))              
#define UART0_ITOP__ITOP11_SET(x, value)    SET_BITS((x), (11), (1), (value))    
#define UART0_ITOP__ITOP11_CLR(x)           CLR_BITS((x), (11), (1))

#define UART0_ITOP__ITOP10_GET(x)           GET_BITS((x), (10), (1))              
#define UART0_ITOP__ITOP10_SET(x, value)    SET_BITS((x), (10), (1), (value))    
#define UART0_ITOP__ITOP10_CLR(x)           CLR_BITS((x), (10), (1))

#define UART0_ITOP__ITOP9_GET(x)            GET_BITS((x), (9), (1))              
#define UART0_ITOP__ITOP9_SET(x, value)     SET_BITS((x), (9), (1), (value))    
#define UART0_ITOP__ITOP9_CLR(x)            CLR_BITS((x), (9), (1))

#define UART0_ITOP__ITOP8_GET(x)            GET_BITS((x), (8), (1))              
#define UART0_ITOP__ITOP8_SET(x, value)     SET_BITS((x), (8), (1), (value))    
#define UART0_ITOP__ITOP8_CLR(x)            CLR_BITS((x), (8), (1))

#define UART9_ITOP__ITOP7_GET(x)            GET_BITS((x), (7), (1))              
#define UART9_ITOP__ITOP7_SET(x, value)     SET_BITS((x), (7), (1), (value))    
#define UART9_ITOP__ITOP7_CLR(x)            CLR_BITS((x), (7), (1))

#define UART0_ITOP__ITIP6_GET(x)            GET_BITS((x), (6), (1))              
#define UART0_ITOP__ITIP6_SET(x, value)     SET_BITS((x), (6), (1), (value))    
#define UART0_ITOP__ITIP6_CLR(x)            CLR_BITS((x), (6), (1))

#define UART0_ITOP__ITIP3_GET(x)            GET_BITS((x), (3), (1))              
#define UART0_ITOP__ITIP3_SET(x, value)     SET_BITS((x), (3), (1), (value))    
#define UART0_ITOP__ITIP3_CLR(x)            CLR_BITS((x), (3), (1))

#define UART0_ITOP__ITIP0_GET(x)            GET_BITS((x), (0), (1))              
#define UART0_ITOP__ITIP0_SET(x, value)     SET_BITS((x), (0), (1), (value))    
#define UART0_ITOP__ITIP0_CLR(x)            CLR_BITS((x), (0), (1))

/*TDR Register's break up*/
#define UART0_TDR__TDR10_0_GET(x)            GET_BITS((x), (10), (11))             
#define UART0_TDR__TDR10_0_SET(x, value)     SET_BITS((x), (10), (11), (value))    
#define UART0_TDR__TDR10_0_CLR(x)            CLR_BITS((x), (10), (11))

/* @brief: 
 *   Function Prototypes
 */


unsigned int uart0_read_REG(unsigned int offset);

void uart0_program_REG(unsigned int offset, 
                       unsigned int value);

void uart0_set_baudrate(unsigned int baudrate);

void uart0_disable(void);

void uart0_enable(void);

void uart0_enable_tx(void);

void uart0_enable_rx(void);

void uart0_disable_tx(void);

void uart0_disable_rx(void);

void uart0_flush_fifo(void);

void uart0_enable_fifo(void);

void uart0_main(void);

void uart0_send_data(unsigned char value);

#endif /*__UART0_H__*/

