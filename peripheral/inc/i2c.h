#ifndef __I2C_H__
#define __I2C_H__

#define SHIFTS 2
/*I2C0M - I2C0 Master Register's Offset (BSC0)*/
#define I2C0M_C     ((0x00) >> (SHIFTS))
#define I2C0M_D     ((0x04) >> (SHIFTS))
#define I2C0M_DLEN  ((0x08) >> (SHIFTS))
#define I2C0M_A     ((0x0C) >> (SHIFTS))
#define I2C0M_FIFO  ((0x10) >> (SHIFTS))
#define I2C0M_DIV   ((0x14) >> (SHIFTS))
#define I2C0M_DEL   ((0x18) >> (SHIFTS))
#define I2C0M_CLKT  ((0x1C) >> (SHIFTS))

/*I2C1M - I2C1 Master Register's Offset (BSC1)*/
#define I2C1M_C     I2C0M_C
#define I2C1M_D     I2C0M_D
#define I2C1M_DLEN  I2C0M_DLEN
#define I2C1M_A     I2C0M_A
#define I2C1M_FIFO  I2C0M_FIFO
#define I2C1M_DIV   I2C0M_DIV
#define I2C1M_DEL   I2C0M_DEL
#define I2C1M_CLKT  I2C0M_CLKT

/*Register's Field*/
#define I2C0M_C__I2CEN_GET(x)        GET_BITS((x), (15), (1)) 
#define I2C0M_C__I2CEN_SET(x, value) SET_BITS((x), (15), (1), (value))
#define I2C0M_C__I2CEN_CLR(x)        CLR_BITS((x), (15), (1))

#define I2C0M_C__INTR_GET(x)         GET_BITS((x), (10), (1))
#define I2C0M_C__INTR_SET(x, value)  SET_BITS((x), (10), (1), (value))
#define I2C0M_C__INTR_CLR(x)         CLR_BITS((x), (10), (1))

#define I2C0M_C__INTT_GET(x)        GET_BITS((x), (9), (1))
#define I2C0M_C__INTT_SET(x, value) SET_BITS((x), (9), (1), (value))
#define I2C0M_C__INTT_CLR(x)        CLR_BITS((x), (9), (1))

#define I2C0M_C__INTD_GET(x)        GET_BITS((x), (8), (1))
#define I2C0M_C__INTD_SET(x, value) SET_BITS((x), (8), (1), (value))
#define I2C0M_C__INTD_CLR(x)        GLC_BITS((x), (8), (1))

#define I2C0M_C__ST_GET(x)        GET_BITS((x), (7), (1))
#define I2C0M_C__ST_SET(x, value) SET_BITS((x), (7), (1), (value))
#define I2C0M_C__ST_CLR(x)        CLR_BITS((x), (7), (1))

#define I2C0M_C__CLEAR_GET(x)        GET_BITS((x), (5), (2))
#define I2C0M_C__CLEAR_SET(x, value) SET_BITS((x), (5), (2), (value))
#define I2C0M_C__CLEAR_CLR(x)        CLR_BITS((x), (5), (2))

/*READ Read Transfer*/
#define I2C0M_C__READ_GET(x)        GET_BITS((x), (0), (1))
#define I2C0M_C__READ_SET(x, value) SET_BITS((x), (0), (1), (value))
#define I2C0M_C__READ_CLR(x)        CLR_BITS((x), (0), (1))

/*CLKT Clock Stretch Timeout*/
#define I2C0M_S__CLKT_GET(x)        GET_BITS((x), (9), (1))
#define I2C0M_S__CLKT_SET(x, value) SET_BITS((x), (9), (1), (value))
#define I2C0M_S__CLKT_CLR(x)        CLR_BITS((x), (9), (1))

/*ERR ACK Error*/
#define I2C0M_S__ERR_GET(x)        GET_BITS((x), (8), (1))
#define I2C0M_S__ERR_SET(x, value) SET_BITS((x), (8), (1), (value))
#define I2C0M_S__ERR_CLR(x)        CLR_BITS((x), (8), (1))

/*RXF - FIFO Full*/
#define I2C0M_S__RXF_GET(x)        GET_BITS((x), (7), (1))
#define I2C0M_S__RXF_SET(x, value) SET_BITS((x), (7), (1), (value))
#define I2C0M_S__RXF_CLR(x)        CLR_BITS((x), (7), (1))

/*TXE - FIFO Empty*/
#define I2C0M_S__TXE_GET(x)        GET_BITS((x), (6), (1))
#define I2C0M_S__TXE_SET(x, value) SET_BITS((x), (6), (1), (value))
#define I2C0M_S__TXE_CLR(x)        CLR_BITS((x), (6), (1))

/*RXD - FIFO contains Data*/
#define I2C0M_S__RXD_GET(x)        GET_BITS((x), (5), (1))
#define I2C0M_S__RXD_SET(x, value) SET_BITS((x), (5), (1), (value))
#define I2C0M_S__RXD_CLR(x)        CLR_BITS((x), (5), (1))

/*TXD - FIFO can accept Data*/
#define I2C0M_S__TXD_GET(x)        GET_BITS((x), (4), (1))
#define I2C0M_S__TXD_SET(x, value) SET_BITS((x), (4), (1), (value))
#define I2C0M_S__TXD_CLR(x)        CLR_BITS((x), (4), (1))

/*RXR - FIFO needs Reading ( full)*/
#define I2C0M_S__RXR_GET(x)        GET_BITS((x), (3), (1))
#define I2C0M_S__RXR_SET(x, value) SET_BITS((x), (3), (1), (value))
#define I2C0M_S__RXR_CLR(x)        CLR_BITS((x), (3), (1))

/*TXW - FIFO needs Writing ( full)*/
#define I2C0M_S__TXW_GET(x)        GET_BITS((x), (2), (1))
#define I2C0M_S__TXW_SET(x, value) SET_BITS((x), (2), (1), (value))
#define I2C0M_S__TXW_CLR(x)        CLR_BITS((x), (2), (1))

/*DONE Transfer Done*/
#define I2C0M_S__DONE_GET(x)        GET_BITS((x), (1), (1))
#define I2C0M_S__DONE_SET(x, value) SET_BITS((x), (1), (1), (value))
#define I2C0M_S__DONE_CLR(x)        CLR_BITS((x), (1), (1))

/*TA Transfer Active*/
#define I2C0M_S__TA_GET(x)        GET_BITS((x), (0), (1))
#define I2C0M_S__TA_SET(x, value) SET_BITS((x), (0), (1), (value))
#define I2C0M_S__TA_CLR(x)        CLR_BITS((x), (0), (1))

/*DLEN Register*/
#define I2C0M_DLEN__DLEN_GET(x)        GET_BITS((x), (15), (16))
#define I2C0M_DLEN__DLEN_SET(x, value) SET_BITS((x), (15), (16), (value))
#define I2C0M_DLEN__DLEN_CLR(x)        CLR_BITS((x), (15), (16))

/*A Register*/
#define I2C0M_A__ADDR_GET(x)        GET_BITS((x), (6), (7))
#define I2C0M_A__ADDR_SET(x, value) SET_BITS((x), (6), (7), (value))
#define I2C0M_A__ADDR_CLR(x)        CLR_BITS((x), (6), (7))

/*FIFO Register*/
#define I2C0M_FIFO__DATA_GET(x)        GET_BITS((x), (7), (8))
#define I2C0M_FIFO__DATA_SET(x, value) SET_BITS((x), (7), (8), (value))
#define I2C0M_FIFO__DATA_CLR(x)        CLR_BITS((x), (7), (8))

/*DIV Register*/
#define I2C0M_DIV__CDIV_GET(x)        GET_BITS((x), (15), (16))
#define I2C0M_DIV__CDIV_SET(x, value) SET_BITS((x), (15), (16), (value))
#define I2C0M_DIV__CDIV_CLR(x)        CLR_BITS((x), (15), (16))

/*DEL Register*/
#define I2C0M_DEL__FEDL_GET(x)        GET_BITS((x), (31), (16))
#define I2C0M_DEL__FEDL_SET(x, value) SET_BITS((x), (31), (16), (value))
#define I2C0M_DEL__FEDL_CLR(x)        CLR_BITS((x), (31), (16))

#define I2C0M_DEL__REDL_GET(x)        GET_BITS((x), (15), (16))
#define I2C0M_DEL__REDL_SET(x, value) SET_BITS((x), (15), (16), (value))
#define I2C0M_DEL__REDL_CLR(x)        CLR_BITS((x), (15), (16))

/*CLKT Register*/
#define I2C0M_CLKT__TOUT_GET(x)        GET_BITS((x), (15), (16))
#define I2C0M_CLKT__TOUT_SET(x, value) SET_BITS((x), (15), (16), (value))
#define I2C0M_CLKT__TOUT_CLR(x)        CLR_BITS((x), (15), (16))

/*Register's Field I2C1M*/
#define I2C1M_C__I2CEN_GET(x)        I2C0M_C__I2CEN_GET(x)
#define I2C1M_C__I2CEN_SET(x, value) I2C0M_C__I2CEN_SET(x, value)
#define I2C1M_C__I2CEN_CLR(x)        I2C0M_C__I2CEN_CLR(x)

#define I2C1M_C__INTR_GET(x)         I2C0M_C__INTR_GET(x)
#define I2C1M_C__INTR_SET(x, value)  I2C0M_C__INTR_SET(x, value)
#define I2C1M_C__INTR_CLR(x)         I2C0M_C__INTR_CLR(x)

#define I2C1M_C__INTT_GET(x)         I2C0M_C__INTT_GET(x)
#define I2C1M_C__INTT_SET(x, value)  I2C0M_C__INTT_SET(x, value)
#define I2C1M_C__INTT_CLR(x)         I2C0M_C__INTT_CLR(x)

#define I2C1M_C__INTD_GET(x)         I2C0M_C__INTD_GET(x)
#define I2C1M_C__INTD_SET(x, value)  I2C0M_C__INTD_SET(x, value)
#define I2C1M_C__INTD_CLR(x)         I2C0M_C__INTD_CLR(x)

#define I2C1M_C__ST_GET(x)           I2C0M_C__ST_GET(x)
#define I2C1M_C__ST_SET(x, value)    I2C0M_C__ST_SET(x, value)
#define I2C1M_C__ST_CLR(x)           I2C0M_C__ST_CLR(x)

#define I2C1M_C__CLEAR_GET(x)        I2C0M_C__CLEAR_GET(x)
#define I2C1M_C__CLEAR_SET(x, value) I2C0M_C__CLEAR_SET(x, value)
#define I2C1M_C__CLEAR_CLR(x)        I2C0M_C__CLEAR_CLR(x)

/*READ Read Transfer*/
#define I2C1M_C__READ_GET(x)         I2C0M_C__READ_GET(x)
#define I2C1M_C__READ_SET(x, value)  I2C0M_C__READ_SET(x, value)
#define I2C1M_C__READ_CLR(x)         I2C0M_C__READ_CLR(x)

/*CLKT Clock Stretch Timeout*/
#define I2C1M_S__CLKT_GET(x)         I2C0M_S__CLKT_GET(x)
#define I2C1M_S__CLKT_SET(x, value)  I2C0M_S__CLKT_SET(x, value)
#define I2C1M_S__CLKT_CLR(x)         I2C0M_S__CLKT_CLR(x)

/*ERR ACK Error*/
#define I2C1M_S__ERR_GET(x)          I2C0M_S__ERR_GET(x)       
#define I2C1M_S__ERR_SET(x, value)   I2C0M_S__ERR_SET(x, value)
#define I2C1M_S__ERR_CLR(x)          I2C0M_S__ERR_CLR(x)       

/*RXF - FIFO Full*/
#define I2C1M_S__RXF_GET(x)          I2C0M_S__RXF_GET(x)
#define I2C1M_S__RXF_SET(x, value)   I2C0M_S__RXF_SET(x, value)
#define I2C1M_S__RXF_CLR(x)          I2C0M_S__RXF_CLR(x)
                                                             
/*TXE - FIFO Empty*/               
#define I2C1M_S__TXE_GET(x)          I2C0M_S__TXE_GET(x)
#define I2C1M_S__TXE_SET(x, value)   I2C0M_S__TXE_SET(x, value)
#define I2C1M_S__TXE_CLR(x)          I2C0M_S__TXE_CLR(x)
                                                             
/*RXD - FIFO contains Data*/       
#define I2C1M_S__RXD_GET(x)          I2C0M_S__RXD_GET(x)
#define I2C1M_S__RXD_SET(x, value)   I2C0M_S__RXD_SET(x, value)
#define I2C1M_S__RXD_CLR(x)          I2C0M_S__RXD_CLR(x)
                                                             
/*TXD - FIFO can accept Data*/     
#define I2C1M_S__TXD_GET(x)          I2C0M_S__TXD_GET(x)
#define I2C1M_S__TXD_SET(x, value)   I2C0M_S__TXD_SET(x, value)
#define I2C1M_S__TXD_CLR(x)          I2C0M_S__TXD_CLR(x)

/*RXR - FIFO needs Reading ( full)*/
#define I2C1M_S__RXR_GET(x)          I2C0M_S__RXR_GET(x)       
#define I2C1M_S__RXR_SET(x, value)   I2C0M_S__RXR_SET(x, value)
#define I2C1M_S__RXR_CLR(x)          I2C0M_S__RXR_CLR(x)       

/*TXW - FIFO needs Writing ( full)*/
#define I2C1M_S__TXW_GET(x)          I2C0M_S__TXW_GET(x)
#define I2C1M_S__TXW_SET(x, value)   I2C0M_S__TXW_SET(x, value)
#define I2C1M_S__TXW_CLR(x)          I2C0M_S__TXW_CLR(x)

/*DONE Transfer Done*/
#define I2C1M_S__DONE_GET(x)         I2C0M_S__DONE_GET(x)
#define I2C1M_S__DONE_SET(x, value)  I2C0M_S__DONE_SET(x, value)
#define I2C1M_S__DONE_CLR(x)         I2C0M_S__DONE_CLR(x)

/*TA Transfer Active*/
#define I2C1M_S__TA_GET(x)             I2C0M_S__TA_GET(x)
#define I2C1M_S__TA_SET(x, value)      I2C0M_S__TA_SET(x, value)
#define I2C1M_S__TA_CLR(x)             I2C0M_S__TA_CLR(x)

/*DLEN Register*/
#define I2C1M_DLEN__DLEN_GET(x)        I2C0M_DLEN__DLEN_GET(x)
#define I2C1M_DLEN__DLEN_SET(x, value) I2C0M_DLEN__DLEN_SET(x, value)
#define I2C1M_DLEN__DLEN_CLR(x)        I2C0M_DLEN__DLEN_CLR(x)

/*A Register*/
#define I2C1M_A__ADDR_GET(x)           I2C0M_A__ADDR_GET(x)
#define I2C1M_A__ADDR_SET(x, value)    I2C0M_A__ADDR_SET(x, value)
#define I2C1M_A__ADDR_CLR(x)           I2C0M_A__ADDR_CLR(x)

/*FIFO Register*/
#define I2C1M_FIFO__DATA_GET(x)        I2C0M_FIFO__DATA_GET(x)
#define I2C1M_FIFO__DATA_SET(x, value) I2C0M_FIFO__DATA_SET(x, value)
#define I2C1M_FIFO__DATA_CLR(x)        I2C0M_FIFO__DATA_CLR(x)

/*DIV Register*/
#define I2C1M_DIV__CDIV_GET(x)         I2C0M_DIV__CDIV_GET(x)
#define I2C1M_DIV__CDIV_SET(x, value)  I2C0M_DIV__CDIV_SET(x, value)
#define I2C1M_DIV__CDIV_CLR(x)         I2C0M_DIV__CDIV_CLR(x)

/*DEL Register*/
#define I2C1M_DEL__FEDL_GET(x)         I2C0M_DEL__FEDL_GET(x)
#define I2C1M_DEL__FEDL_SET(x, value)  I2C0M_DEL__FEDL_SET(x, value)
#define I2C1M_DEL__FEDL_CLR(x)         I2C0M_DEL__FEDL_CLR(x)

#define I2C1M_DEL__REDL_GET(x)         I2C0M_DEL__REDL_GET(x)
#define I2C1M_DEL__REDL_SET(x, value)  I2C0M_DEL__REDL_SET(x, value)
#define I2C1M_DEL__REDL_CLR(x)         I2C0M_DEL__REDL_CLR(x)

/*CLKT Register*/
#define I2C1M_CLKT__TOUT_GET(x)        I2C0M_CLKT__TOUT_GET(x)
#define I2C1M_CLKT__TOUT_SET(x, value) I2C0M_CLKT__TOUT_SET(x, value)
#define I2C1M_CLKT__TOUT_CLR(x)        I2C0M_CLKT__TOUT_CLR(x)


#endif /* __I2C_H__ */
