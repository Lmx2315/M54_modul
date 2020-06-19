#ifndef DMA_PORT_CH_REG_FIELDS_HPP
#define DMA_PORT_CH_REG_FIELDS_HPP

//this file was automatically generated, don't edit this file

#define	MASK_DMA_PORT_CH_REG_FIELDS_H_FIELD(max_,min_)	((max_ -min_)==31 ? 0xFFFFFFFF : ((1<<(max_-min_+1))-1) )
#define	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,max_,min_)		(((a)&MASK_DMA_PORT_CH_REG_FIELDS_H_FIELD(max_,min_))<<min_)
#define	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,max_,min_)	(((a)>>min_)&MASK_DMA_PORT_CH_REG_FIELDS_H_FIELD(max_,min_))
#define	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,max_,min_)	(((reg)&(~(MASK_DMA_PORT_CH_REG_FIELDS_H_FIELD(max_,min_)<<min_)))|DMA_PORT_CH_REG_FIELDS_H_FIELD(f,max_,min_))

#define	OFFSET_DMA_PORT_CH_CSR_RUN             	0
#define	DMA_PORT_CH_CSR_RUN(a)                 	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,0,0)
#define	GET_DMA_PORT_CH_CSR_RUN(a)             	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,0,0)
#define	SET_DMA_PORT_CH_CSR_RUN(reg,f)         	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,0,0)

#define	OFFSET_DMA_PORT_CH_CSR_RSRV0           	1
#define	DMA_PORT_CH_CSR_RSRV0(a)               	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,1,1)
#define	GET_DMA_PORT_CH_CSR_RSRV0(a)           	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,1,1)
#define	SET_DMA_PORT_CH_CSR_RSRV0(reg,f)       	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,1,1)

#define	OFFSET_DMA_PORT_CH_CSR_WN              	2
#define	DMA_PORT_CH_CSR_WN(a)                  	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,5,2)
#define	GET_DMA_PORT_CH_CSR_WN(a)              	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,5,2)
#define	SET_DMA_PORT_CH_CSR_WN(reg,f)          	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,5,2)

#define	OFFSET_DMA_PORT_CH_CSR_IPD             	6
#define	DMA_PORT_CH_CSR_IPD(a)                 	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,6,6)
#define	GET_DMA_PORT_CH_CSR_IPD(a)             	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,6,6)
#define	SET_DMA_PORT_CH_CSR_IPD(reg,f)         	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,6,6)

#define	OFFSET_DMA_PORT_CH_CSR_RSRV1           	7
#define	DMA_PORT_CH_CSR_RSRV1(a)               	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,11,7)
#define	GET_DMA_PORT_CH_CSR_RSRV1(a)           	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,11,7)
#define	SET_DMA_PORT_CH_CSR_RSRV1(reg,f)       	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,11,7)

#define	OFFSET_DMA_PORT_CH_CSR_CHEN            	12
#define	DMA_PORT_CH_CSR_CHEN(a)                	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,12,12)
#define	GET_DMA_PORT_CH_CSR_CHEN(a)            	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,12,12)
#define	SET_DMA_PORT_CH_CSR_CHEN(reg,f)        	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,12,12)

#define	OFFSET_DMA_PORT_CH_CSR_IM              	13
#define	DMA_PORT_CH_CSR_IM(a)                  	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,13,13)
#define	GET_DMA_PORT_CH_CSR_IM(a)              	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,13,13)
#define	SET_DMA_PORT_CH_CSR_IM(reg,f)          	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,13,13)

#define	OFFSET_DMA_PORT_CH_CSR_END             	14
#define	DMA_PORT_CH_CSR_END(a)                 	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,14,14)
#define	GET_DMA_PORT_CH_CSR_END(a)             	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,14,14)
#define	SET_DMA_PORT_CH_CSR_END(reg,f)         	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,14,14)

#define	OFFSET_DMA_PORT_CH_CSR_DONE            	15
#define	DMA_PORT_CH_CSR_DONE(a)                	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,15,15)
#define	GET_DMA_PORT_CH_CSR_DONE(a)            	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,15,15)
#define	SET_DMA_PORT_CH_CSR_DONE(reg,f)        	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,15,15)

#define	OFFSET_DMA_PORT_CH_CSR_WCX             	16
#define	DMA_PORT_CH_CSR_WCX(a)                 	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,31,16)
#define	GET_DMA_PORT_CH_CSR_WCX(a)             	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,31,16)
#define	SET_DMA_PORT_CH_CSR_WCX(reg,f)         	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,31,16)

#define	OFFSET_DMA_PORT_CH_CP_START_CHAIN      	0
#define	DMA_PORT_CH_CP_START_CHAIN(a)          	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,0,0)
#define	GET_DMA_PORT_CH_CP_START_CHAIN(a)      	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,0,0)
#define	SET_DMA_PORT_CH_CP_START_CHAIN(reg,f)  	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,0,0)

#define	OFFSET_DMA_PORT_CH_CP_ADDR_SHIFFTED    	1
#define	DMA_PORT_CH_CP_ADDR_SHIFFTED(a)        	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,31,1)
#define	GET_DMA_PORT_CH_CP_ADDR_SHIFFTED(a)    	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,31,1)
#define	SET_DMA_PORT_CH_CP_ADDR_SHIFFTED(reg,f)	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,31,1)

#define	OFFSET_DMA_PORT_CH_IR_IR               	0
#define	DMA_PORT_CH_IR_IR(a)                   	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_DMA_PORT_CH_IR_IR(a)               	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_DMA_PORT_CH_IR_IR(reg,f)           	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_DMA_PORT_CH_RUN_RUN             	0
#define	DMA_PORT_CH_RUN_RUN(a)                 	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,0,0)
#define	GET_DMA_PORT_CH_RUN_RUN(a)             	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,0,0)
#define	SET_DMA_PORT_CH_RUN_RUN(reg,f)         	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,0,0)

#define	OFFSET_DMA_PORT_CH_RUN_RSRV1           	1
#define	DMA_PORT_CH_RUN_RSRV1(a)               	DMA_PORT_CH_REG_FIELDS_H_FIELD(a,31,1)
#define	GET_DMA_PORT_CH_RUN_RSRV1(a)           	GET_DMA_PORT_CH_REG_FIELDS_H_FIELD(a,31,1)
#define	SET_DMA_PORT_CH_RUN_RSRV1(reg,f)       	SET_DMA_PORT_CH_REG_FIELDS_H_FIELD(reg,f,31,1)

#endif

