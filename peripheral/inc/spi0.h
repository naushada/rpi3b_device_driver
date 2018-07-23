#ifndef __SPI0_H__
#define __SPI0_H__

#define SHIFTS 2
/*API Mastr Register's Offset*/
#define SPI0M_CS   ((0x00) >> (SHIFTS))
#define SPI0M_FIFO ((0x04) >> (SHIFTS))
#define SPI0M_CLK  ((0x08) >> (SHIFTS))
#define SPI0M_DLEN ((0x0C) >> (SHIFTS))
#define SPI0M_LTOH ((0x10) >> (SHIFTS))
#define SPI0M_DC   ((0x14) >> (SHIFTS))

/*Register's Field*/
#define SPI0M_CS__LEN_LONG_GET(x)        GET_BITS((x), (25), (1)) 
#define SPI0M_CS__LEN_LONG_SET(x, value) SET_BITS((x), (25), (1), (value))
#define SPI0M_CS__LEN_LONG_CLR(x)        CLR_BITS((x), (25), (1))

#define SPI0M_CS__DMA_LEN_GET(x)         GET_BITS((x), (24), (1))
#define SPI0M_CS__DMA_LEN_SET(x, value)  SET_BITS((x), (24), (1), (value))
#define SPI0M_CS__DMA_LEN_CLR(x)         CLR_BITS((x), (24), (1))


/*Chip Select Polarity*/
#define SPI0M_CS__CSPOL2_GET(x)        GET_BITS((x), (32), (1))
#define SPI0M_CS__CSPOL2_SET(x, value) SET_BITS((x), (23), (1), (value))
#define SPI0M_CS__CSPOL2_CLR(x)        CLR_BITS((x), (23), (1))

/*Chip Select Polarity*/
#define SPI0M_CS__CSPOL1_GET(x)        GET_BITS((x), (22), (1))
#define SPI0M_CS__CSPOL1_SET(x, value) SET_BITS((x), (22), (1), (value))
#define SPI0M_CS__CSPOL1_CLR(x)        GLC_BITS((x), (22), (1))

/*Chip Select Polarity*/
#define SPI0M_CS__CSPOL0_GET(x)        GET_BITS((x), (21), (1))
#define SPI0M_CS__CSPOL0_SET(x, value) SET_BITS((x), (21), (1), (value))
#define SPI0M_CS__CSPOL0_CLR(x)        CLR_BITS((x), (21), (1))

/*RXF-FIFO Full*/
#define SPI0M_CS__RXF_GET(x)        GET_BITS((x), (20), (1))
#define SPI0M_CS__RXF_SET(x, value) SET_BITS((x), (20), (1), (value))
#define SPI0M_CS__RXF_CLR(x)        CLR_BITS((x), (20), (1))

/*RXR-RX FIFO Ready - Needs to read from RX-FIFO*/
#define SPI0M_CS__RXR_GET(x)        GET_BITS((x), (19), (1))
#define SPI0M_CS__RXR_SET(x, value) SET_BITS((x), (19), (1), (value))
#define SPI0M_CS__RXR_CLR(x)        CLR_BITS((x), (19), (1))

/*TXD- TX FIFO can accept Data*/
#define SPI0M_CS__TXD_GET(x)        GET_BITS((x), (18), (1))
#define SPI0M_CS__TXD_SET(x, value) SET_BITS((x), (18), (1), (value))
#define SPI0M_CS__TXD_CLR(x)        CLR_BITS((x), (18), (1))

/*RXD- RX FIFO contains Data*/
#define SPI0M_CS__RXD_GET(x)        GET_BITS((x), (17), (1))
#define SPI0M_CS__RXD_SET(x, value) SET_BITS((x), (17), (1), (value))
#define SPI0M_CS__RXD_CLR(x)        CLR_BITS((x), (17), (1))

/*RXD- RX FIFO contains Data*/
#define SPI0M_CS__RXD_GET(x)        GET_BITS((x), (17), (1))
#define SPI0M_CS__RXD_SET(x, value) SET_BITS((x), (17), (1), (value))
#define SPI0M_CS__RXD_CLR(x)        CLR_BITS((x), (17), (1))

/*DONE- Done transfer Done*/
#define SPI0M_CS__DONE_GET(x)        GET_BITS((x), (16), (1))
#define SPI0M_CS__DONE_SET(x, value) SET_BITS((x), (16), (1), (value))
#define SPI0M_CS__DONE_CLR(x)        CLR_BITS((x), (16), (1))

/*LEN - LEN LoSSI enable */
#define SPI0M_CS__LEN_GET(x)        GET_BITS((x), (13), (1))
#define SPI0M_CS__LEN_SET(x, value) SET_BITS((x), (13), (1), (value))
#define SPI0M_CS__LEN_CLR(x)        CLR_BITS((x), (13), (1))

/*REN - REN Read Enable */
#define SPI0M_CS__REN_GET(x)        GET_BITS((x), (12), (1))
#define SPI0M_CS__REN_SET(x, value) SET_BITS((x), (12), (1), (value))
#define SPI0M_CS__REN_CLR(x)        CLR_BITS((x), (12), (1))

/*ADCS - ADCS Automatically Deassert Chip Select */
#define SPI0M_CS__ADCS_GET(x)        GET_BITS((x), (11), (1))
#define SPI0M_CS__ADCS_SET(x, value) SET_BITS((x), (11), (1), (value))
#define SPI0M_CS__ADCS_CLR(x)        CLR_BITS((x), (11), (1))

/*INTR - INTR Interrupt on RXR */
#define SPI0M_CS__INTR_GET(x)        GET_BITS((x), (10), (1))
#define SPI0M_CS__INTR_SET(x, value) SET_BITS((x), (10), (1), (value))
#define SPI0M_CS__INTR_CLR(x)        CLR_BITS((x), (10), (1))

/*INTD - INTD Interrupt on Done */
#define SPI0M_CS__INTD_GET(x)        GET_BITS((x), (9), (1))
#define SPI0M_CS__INTD_SET(x, value) SET_BITS((x), (9), (1), (value))
#define SPI0M_CS__INTD_CLR(x)        CLR_BITS((x), (9), (1))

/*DMAEN - DMAEN DMA Enable */
#define SPI0M_CS__DMAEN_GET(x)        GET_BITS((x), (8), (1))
#define SPI0M_CS__DMAEN_SET(x, value) SET_BITS((x), (8), (1), (value))
#define SPI0M_CS__DMAEN_CLR(x)        CLR_BITS((x), (8), (1))

/*TA - Transfer Active */
#define SPI0M_CS__TA_GET(x)        GET_BITS((x), (7), (1))
#define SPI0M_CS__TA_SET(x, value) SET_BITS((x), (7), (1), (value))
#define SPI0M_CS__TA_CLR(x)        CLR_BITS((x), (7), (1))

/*CSPOL - Chip Select Polarity */
#define SPI0M_CS__CSPOL_GET(x)        GET_BITS((x), (6), (1))
#define SPI0M_CS__CSPOL_SET(x, value) SET_BITS((x), (6), (1), (value))
#define SPI0M_CS__CSPOL_CLR(x)        CLR_BITS((x), (6), (1))

/*CLEAR - CLEAR FIFO Clear */
#define SPI0M_CS__CLEAR_GET(x)        GET_BITS((x), (5), (2))
#define SPI0M_CS__CLEAR_SET(x, value) SET_BITS((x), (5), (2), (value))
#define SPI0M_CS__CLEAR_CLR(x)        CLR_BITS((x), (5), (2))

/*CPOL - Clock Polarity*/
#define SPI0M_CS__CPOL_GET(x)        GET_BITS((x), (3), (1))
#define SPI0M_CS__CPOL_SET(x, value) SET_BITS((x), (3), (1), (value))
#define SPI0M_CS__CPOL_CLR(x)        CLR_BITS((x), (3), (1))

/*CPHA - Clock Phase*/
#define SPI0M_CS__CPHA_GET(x)        GET_BITS((x), (2), (1))
#define SPI0M_CS__CPHA_SET(x, value) SET_BITS((x), (2), (1), (value))
#define SPI0M_CS__CPHA_CLR(x)        CLR_BITS((x), (2), (1))

/*CS - Chip Select*/
#define SPI0M_CS__CS_GET(x)        GET_BITS((x), (1), (2))
#define SPI0M_CS__CS_SET(x, value) SET_BITS((x), (1), (2), (value))
#define SPI0M_CS__CS_CLR(x)        CLR_BITS((x), (1), (2))

/*DATA - DMA Mode (DMAEN set)*/
#define SPI0M_FIFO__DATA_GET(x)        GET_BITS((x), (31), (32))
#define SPI0M_FIFO__DATA_SET(x, value) SET_BITS((x), (31), (32), (value))
#define SPI0M_FIFO__DATA_CLR(x)        CLR_BITS((x), (31), (32))

/*CDIV - Clock Divider*/
#define SPI0M_CLK__CDIV_GET(x)        GET_BITS((x), (14), (15))
#define SPI0M_CLK__CDIV_SET(x, value) SET_BITS((x), (14), (15), (value))
#define SPI0M_CLK__CDIV_CLR(x)        CLR_BITS((x), (14), (15))

/*DLEN - Data Length*/
#define SPI0M_DLEN__LEN_GET(x)        GET_BITS((x), (14), (15))
#define SPI0M_DLEN__LEN_SET(x, value) SET_BITS((x), (14), (15), (value))
#define SPI0M_DLEN__LEN_CLR(x)        CLR_BITS((x), (14), (15))

/*TOH - This register allows the LoSSI output hold delay to be set*/
#define SPI0M_LTOH__TOH_GET(x)        GET_BITS((x), (3), (4))
#define SPI0M_LTOH__TOH_SET(x, value) SET_BITS((x), (3), (4), (value))
#define SPI0M_LTOH__TOH_CLR(x)        CLR_BITS((x), (3), (4))

/*RPANIC - DMA Read Panic Threshold*/
#define SPI0M_DC__RPANIC_GET(x)        GET_BITS((x), (30), (7))
#define SPI0M_DC__RPANIC_SET(x, value) SET_BITS((x), (30), (7), (value))
#define SPI0M_DC__RPANIC_CLR(x)        CLR_BITS((x), (30), (7))

/*RDREC - DMA Read Request Threshold.*/
#define SPI0M_DC__RDREC_GET(x)        GET_BITS((x), (22), (7))
#define SPI0M_DC__RDREC_SET(x, value) SET_BITS((x), (22), (7), (value))
#define SPI0M_DC__RDREC_CLR(x)        CLR_BITS((x), (22), (7))

/*TPANIC - DMA Write Panic Threshold.*/
#define SPI0M_DC__TPANIC_GET(x)        GET_BITS((x), (14), (7))
#define SPI0M_DC__TPANIC_SET(x, value) SET_BITS((x), (14), (7), (value))
#define SPI0M_DC__TPANIC_CLR(x)        CLR_BITS((x), (14), (7))

/*TDREQ - DMA Write Request Threshold.*/
#define SPI0M_DC__TDREQ_GET(x)        GET_BITS((x), (6), (7))
#define SPI0M_DC__TDREQ_SET(x, value) SET_BITS((x), (6), (7), (value))
#define SPI0M_DC__TSREQ_CLR(x)        CLR_BITS((x), (6), (7))

#endif /* __SPI0_H__ */
