#ifndef GIGASPWR_REG_FIELDS_HPP
#define GIGASPWR_REG_FIELDS_HPP

//this file was automatically generated, don't edit this file

#define	MASK_GIGASPWR_REG_FIELDS_H_FIELD(max_,min_)	((1<<(max_-min_+1))-1)
#define	GIGASPWR_REG_FIELDS_H_FIELD(a,max_,min_)		(((a)&MASK_GIGASPWR_REG_FIELDS_H_FIELD(max_,min_))<<min_)
#define	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,max_,min_)	(((a)>>min_)&MASK_GIGASPWR_REG_FIELDS_H_FIELD(max_,min_))
#define	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,max_,min_)	(((reg)&(~(MASK_GIGASPWR_REG_FIELDS_H_FIELD(max_,min_)<<min_)))|GIGASPWR_REG_FIELDS_H_FIELD(f,max_,min_))

#define	OFFSET_GIGASPWR_ID_SWITCH_ID_SWITCH                                  	0
#define	GIGASPWR_ID_SWITCH_ID_SWITCH(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_ID_SWITCH_ID_SWITCH(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_ID_SWITCH_ID_SWITCH(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_ID_NET_ID_NET                                        	0
#define	GIGASPWR_ID_NET_ID_NET(a)                                            	GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	GET_GIGASPWR_ID_NET_ID_NET(a)                                        	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	SET_GIGASPWR_ID_NET_ID_NET(reg,f)                                    	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,0)

#define	OFFSET_GIGASPWR_MODE_R_MAIN_KOEFF10                                  	0
#define	GIGASPWR_MODE_R_MAIN_KOEFF10(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,7,0)
#define	GET_GIGASPWR_MODE_R_MAIN_KOEFF10(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,7,0)
#define	SET_GIGASPWR_MODE_R_MAIN_KOEFF10(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,7,0)

#define	OFFSET_GIGASPWR_MODE_R_CUR_WIND_LENGTH                               	8
#define	GIGASPWR_MODE_R_CUR_WIND_LENGTH(a)                                   	GIGASPWR_REG_FIELDS_H_FIELD(a,21,8)
#define	GET_GIGASPWR_MODE_R_CUR_WIND_LENGTH(a)                               	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,21,8)
#define	SET_GIGASPWR_MODE_R_CUR_WIND_LENGTH(reg,f)                           	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,21,8)

#define	OFFSET_GIGASPWR_MODE_R_NDEL_DROPPED_PACKETS                          	22
#define	GIGASPWR_MODE_R_NDEL_DROPPED_PACKETS(a)                              	GIGASPWR_REG_FIELDS_H_FIELD(a,22,22)
#define	GET_GIGASPWR_MODE_R_NDEL_DROPPED_PACKETS(a)                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,22,22)
#define	SET_GIGASPWR_MODE_R_NDEL_DROPPED_PACKETS(reg,f)                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,22,22)

#define	OFFSET_GIGASPWR_MODE_R_DMA_ENABLED                                   	23
#define	GIGASPWR_MODE_R_DMA_ENABLED(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,23,23)
#define	GET_GIGASPWR_MODE_R_DMA_ENABLED(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,23,23)
#define	SET_GIGASPWR_MODE_R_DMA_ENABLED(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,23,23)

#define	OFFSET_GIGASPWR_MODE_R_DMA_CLR_FIFO                                  	24
#define	GIGASPWR_MODE_R_DMA_CLR_FIFO(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,24,24)
#define	GET_GIGASPWR_MODE_R_DMA_CLR_FIFO(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,24,24)
#define	SET_GIGASPWR_MODE_R_DMA_CLR_FIFO(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,24,24)

#define	OFFSET_GIGASPWR_MODE_R_GIGASPWR_WE                                   	25
#define	GIGASPWR_MODE_R_GIGASPWR_WE(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,25,25)
#define	GET_GIGASPWR_MODE_R_GIGASPWR_WE(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,25,25)
#define	SET_GIGASPWR_MODE_R_GIGASPWR_WE(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,25,25)

#define	OFFSET_GIGASPWR_MODE_R1_RISC_D_INT_ACK_REGIMES                       	0
#define	GIGASPWR_MODE_R1_RISC_D_INT_ACK_REGIMES(a)                           	GIGASPWR_REG_FIELDS_H_FIELD(a,0,0)
#define	GET_GIGASPWR_MODE_R1_RISC_D_INT_ACK_REGIMES(a)                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,0,0)
#define	SET_GIGASPWR_MODE_R1_RISC_D_INT_ACK_REGIMES(reg,f)                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,0,0)

#define	OFFSET_GIGASPWR_MODE_R1_RISC_INT_CODES                               	1
#define	GIGASPWR_MODE_R1_RISC_INT_CODES(a)                                   	GIGASPWR_REG_FIELDS_H_FIELD(a,3,1)
#define	GET_GIGASPWR_MODE_R1_RISC_INT_CODES(a)                               	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,3,1)
#define	SET_GIGASPWR_MODE_R1_RISC_INT_CODES(reg,f)                           	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,3,1)

#define	OFFSET_GIGASPWR_MODE_R1_RISC_ACK_CODES                               	4
#define	GIGASPWR_MODE_R1_RISC_ACK_CODES(a)                                   	GIGASPWR_REG_FIELDS_H_FIELD(a,6,4)
#define	GET_GIGASPWR_MODE_R1_RISC_ACK_CODES(a)                               	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,4)
#define	SET_GIGASPWR_MODE_R1_RISC_ACK_CODES(reg,f)                           	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,4)

#define	OFFSET_GIGASPWR_STATE_R_GOT_TIME                                     	0
#define	GIGASPWR_STATE_R_GOT_TIME(a)                                         	GIGASPWR_REG_FIELDS_H_FIELD(a,0,0)
#define	GET_GIGASPWR_STATE_R_GOT_TIME(a)                                     	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,0,0)
#define	SET_GIGASPWR_STATE_R_GOT_TIME(reg,f)                                 	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,0,0)

#define	OFFSET_GIGASPWR_STATE_R_GOT_INT                                      	1
#define	GIGASPWR_STATE_R_GOT_INT(a)                                          	GIGASPWR_REG_FIELDS_H_FIELD(a,1,1)
#define	GET_GIGASPWR_STATE_R_GOT_INT(a)                                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,1,1)
#define	SET_GIGASPWR_STATE_R_GOT_INT(reg,f)                                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,1,1)

#define	OFFSET_GIGASPWR_STATE_R_GOT_ACK                                      	2
#define	GIGASPWR_STATE_R_GOT_ACK(a)                                          	GIGASPWR_REG_FIELDS_H_FIELD(a,2,2)
#define	GET_GIGASPWR_STATE_R_GOT_ACK(a)                                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,2,2)
#define	SET_GIGASPWR_STATE_R_GOT_ACK(reg,f)                                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,2,2)

#define	OFFSET_GIGASPWR_STATE_R_GOT_C01_CODE                                 	3
#define	GIGASPWR_STATE_R_GOT_C01_CODE(a)                                     	GIGASPWR_REG_FIELDS_H_FIELD(a,3,3)
#define	GET_GIGASPWR_STATE_R_GOT_C01_CODE(a)                                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,3,3)
#define	SET_GIGASPWR_STATE_R_GOT_C01_CODE(reg,f)                             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,3,3)

#define	OFFSET_GIGASPWR_STATE_R_GOT_C11_CODE                                 	4
#define	GIGASPWR_STATE_R_GOT_C11_CODE(a)                                     	GIGASPWR_REG_FIELDS_H_FIELD(a,4,4)
#define	GET_GIGASPWR_STATE_R_GOT_C11_CODE(a)                                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,4,4)
#define	SET_GIGASPWR_STATE_R_GOT_C11_CODE(reg,f)                             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,4,4)

#define	OFFSET_GIGASPWR_STATE_R_SPW_CONNECTED                                	5
#define	GIGASPWR_STATE_R_SPW_CONNECTED(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,10,5)
#define	GET_GIGASPWR_STATE_R_SPW_CONNECTED(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,10,5)
#define	SET_GIGASPWR_STATE_R_SPW_CONNECTED(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,10,5)

#define	OFFSET_GIGASPWR_STATE_R_SPW_ERRORED                                  	11
#define	GIGASPWR_STATE_R_SPW_ERRORED(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,16,11)
#define	GET_GIGASPWR_STATE_R_SPW_ERRORED(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,16,11)
#define	SET_GIGASPWR_STATE_R_SPW_ERRORED(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,16,11)

#define	OFFSET_GIGASPWR_STATE_R_PORT_CONNECTED                               	17
#define	GIGASPWR_STATE_R_PORT_CONNECTED(a)                                   	GIGASPWR_REG_FIELDS_H_FIELD(a,22,17)
#define	GET_GIGASPWR_STATE_R_PORT_CONNECTED(a)                               	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,22,17)
#define	SET_GIGASPWR_STATE_R_PORT_CONNECTED(reg,f)                           	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,22,17)

#define	OFFSET_GIGASPWR_STATE_R_PORT_ERRORED                                 	23
#define	GIGASPWR_STATE_R_PORT_ERRORED(a)                                     	GIGASPWR_REG_FIELDS_H_FIELD(a,28,23)
#define	GET_GIGASPWR_STATE_R_PORT_ERRORED(a)                                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,28,23)
#define	SET_GIGASPWR_STATE_R_PORT_ERRORED(reg,f)                             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,28,23)

#define	OFFSET_GIGASPWR_STATE_R_INT_RST                                      	29
#define	GIGASPWR_STATE_R_INT_RST (a)                                         	GIGASPWR_REG_FIELDS_H_FIELD(a,29,29)
#define	GET_GIGASPWR_STATE_R_INT_RST (a)                                     	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,29,29)
#define	SET_GIGASPWR_STATE_R_INT_RST (reg,f)                                 	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,29,29)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_CONNECT_MASK                       	0
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_CONNECT_MASK(a)                           	GIGASPWR_REG_FIELDS_H_FIELD(a,0,0)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_CONNECT_MASK(a)                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,0,0)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_CONNECT_MASK(reg,f)                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,0,0)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_DISCONNECT_MASK                    	1
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_DISCONNECT_MASK(a)                        	GIGASPWR_REG_FIELDS_H_FIELD(a,1,1)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_DISCONNECT_MASK(a)                    	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,1,1)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_DISCONNECT_MASK(reg,f)                	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,1,1)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_IA_CODE_GLOBAL_MASK                	2
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_IA_CODE_GLOBAL_MASK(a)                    	GIGASPWR_REG_FIELDS_H_FIELD(a,2,2)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_IA_CODE_GLOBAL_MASK(a)                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,2,2)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_IA_CODE_GLOBAL_MASK(reg,f)            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,2,2)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_TIME_MASK                          	3
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_TIME_MASK(a)                              	GIGASPWR_REG_FIELDS_H_FIELD(a,3,3)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_TIME_MASK(a)                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,3,3)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_TIME_MASK(reg,f)                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,3,3)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_INT_MASK                           	4
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_INT_MASK(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,4,4)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_INT_MASK(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,4,4)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_INT_MASK(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,4,4)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_ACK_MASK                           	5
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_ACK_MASK(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,5,5)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_ACK_MASK(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,5,5)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_ACK_MASK(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,5,5)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_C01_MASK                           	6
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_C01_MASK(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,6,6)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_C01_MASK(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,6)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_C01_MASK(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,6)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_C11_MASK                           	7
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_C11_MASK(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,7,7)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_C11_MASK(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,7,7)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_C11_MASK(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,7,7)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_INT_RST_MASK                       	8
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_INT_RST_MASK(a)                           	GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_INT_RST_MASK(a)                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_INT_RST_MASK(reg,f)                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,8,8)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_ISR_TOUTS_MASK                     	9
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_ISR_TOUTS_MASK(a)                         	GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_ISR_TOUTS_MASK(a)                     	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_ISR_TOUTS_MASK(reg,f)                 	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,9,9)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_TARB_MASK                          	10
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_TARB_MASK(a)                              	GIGASPWR_REG_FIELDS_H_FIELD(a,10,10)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_TARB_MASK(a)                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,10,10)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_TARB_MASK(reg,f)                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,10,10)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_TRES_MASK                          	11
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_TRES_MASK(a)                              	GIGASPWR_REG_FIELDS_H_FIELD(a,11,11)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_TRES_MASK(a)                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,11)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_TRES_MASK(reg,f)                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,11)

#define	OFFSET_GIGASPWR_RISC_IRQ_MASK_IRQ_TSEND_MASK                         	12
#define	GIGASPWR_RISC_IRQ_MASK_IRQ_TSEND_MASK(a)                             	GIGASPWR_REG_FIELDS_H_FIELD(a,12,12)
#define	GET_GIGASPWR_RISC_IRQ_MASK_IRQ_TSEND_MASK(a)                         	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,12,12)
#define	SET_GIGASPWR_RISC_IRQ_MASK_IRQ_TSEND_MASK(reg,f)                     	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,12,12)

#define	OFFSET_GIGASPWR_AUTO_COU_AUTO_COU                                    	0
#define	GIGASPWR_AUTO_COU_AUTO_COU(a)                                        	GIGASPWR_REG_FIELDS_H_FIELD(a,4,0)
#define	GET_GIGASPWR_AUTO_COU_AUTO_COU(a)                                    	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,4,0)
#define	SET_GIGASPWR_AUTO_COU_AUTO_COU(reg,f)                                	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,4,0)

#define	OFFSET_GIGASPWR_AUTO_COU_CONTROL_TIME                                	5
#define	GIGASPWR_AUTO_COU_CONTROL_TIME(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,15,5)
#define	GET_GIGASPWR_AUTO_COU_CONTROL_TIME(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,15,5)
#define	SET_GIGASPWR_AUTO_COU_CONTROL_TIME(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,15,5)

#define	OFFSET_GIGASPWR_AUTO_COU_CONTROL_REGIME                              	16
#define	GIGASPWR_AUTO_COU_CONTROL_REGIME(a)                                  	GIGASPWR_REG_FIELDS_H_FIELD(a,16,16)
#define	GET_GIGASPWR_AUTO_COU_CONTROL_REGIME(a)                              	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,16,16)
#define	SET_GIGASPWR_AUTO_COU_CONTROL_REGIME(reg,f)                          	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,16,16)

#define	OFFSET_GIGASPWR_AUTO_COU_AUTO_COU_FLAGS                              	17
#define	GIGASPWR_AUTO_COU_AUTO_COU_FLAGS(a)                                  	GIGASPWR_REG_FIELDS_H_FIELD(a,22,17)
#define	GET_GIGASPWR_AUTO_COU_AUTO_COU_FLAGS(a)                              	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,22,17)
#define	SET_GIGASPWR_AUTO_COU_AUTO_COU_FLAGS(reg,f)                          	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,22,17)

#define	OFFSET_GIGASPWR_CONTROL_CONNECTION_CONN_HOLD_TOUT                    	0
#define	GIGASPWR_CONTROL_CONNECTION_CONN_HOLD_TOUT(a)                        	GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	GET_GIGASPWR_CONTROL_CONNECTION_CONN_HOLD_TOUT(a)                    	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	SET_GIGASPWR_CONTROL_CONNECTION_CONN_HOLD_TOUT(reg,f)                	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,5,0)

#define	OFFSET_GIGASPWR_CONTROL_CONNECTION_CONN_HOLD_REGIME                  	6
#define	GIGASPWR_CONTROL_CONNECTION_CONN_HOLD_REGIME(a)                      	GIGASPWR_REG_FIELDS_H_FIELD(a,6,6)
#define	GET_GIGASPWR_CONTROL_CONNECTION_CONN_HOLD_REGIME(a)                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,6)
#define	SET_GIGASPWR_CONTROL_CONNECTION_CONN_HOLD_REGIME(reg,f)              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,6)

#define	OFFSET_GIGASPWR_CONTROL_CONNECTION_UNCONNECT_TOUT                    	7
#define	GIGASPWR_CONTROL_CONNECTION_UNCONNECT_TOUT(a)                        	GIGASPWR_REG_FIELDS_H_FIELD(a,17,7)
#define	GET_GIGASPWR_CONTROL_CONNECTION_UNCONNECT_TOUT(a)                    	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,17,7)
#define	SET_GIGASPWR_CONTROL_CONNECTION_UNCONNECT_TOUT(reg,f)                	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,17,7)

#define	OFFSET_GIGASPWR_CONTROL_CONNECTION_UNCONNECT_TOUT_REGIME             	18
#define	GIGASPWR_CONTROL_CONNECTION_UNCONNECT_TOUT_REGIME(a)                 	GIGASPWR_REG_FIELDS_H_FIELD(a,18,18)
#define	GET_GIGASPWR_CONTROL_CONNECTION_UNCONNECT_TOUT_REGIME(a)             	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,18,18)
#define	SET_GIGASPWR_CONTROL_CONNECTION_UNCONNECT_TOUT_REGIME(reg,f)         	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,18,18)

#define	OFFSET_GIGASPWR_CONTROL_CONNECTION_UNCONNECT_TOUT_DEL_P              	19
#define	GIGASPWR_CONTROL_CONNECTION_UNCONNECT_TOUT_DEL_P(a)                  	GIGASPWR_REG_FIELDS_H_FIELD(a,19,19)
#define	GET_GIGASPWR_CONTROL_CONNECTION_UNCONNECT_TOUT_DEL_P(a)              	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,19,19)
#define	SET_GIGASPWR_CONTROL_CONNECTION_UNCONNECT_TOUT_DEL_P(reg,f)          	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,19,19)

#define	OFFSET_GIGASPWR_STATE_CONNECTION_CONN_HOLD_FLAGS                     	0
#define	GIGASPWR_STATE_CONNECTION_CONN_HOLD_FLAGS(a)                         	GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	GET_GIGASPWR_STATE_CONNECTION_CONN_HOLD_FLAGS(a)                     	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	SET_GIGASPWR_STATE_CONNECTION_CONN_HOLD_FLAGS(reg,f)                 	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,5,0)

#define	OFFSET_GIGASPWR_STATE_CONNECTION_UNCONNECT_TOUT_FLAGS                	6
#define	GIGASPWR_STATE_CONNECTION_UNCONNECT_TOUT_FLAGS(a)                    	GIGASPWR_REG_FIELDS_H_FIELD(a,11,6)
#define	GET_GIGASPWR_STATE_CONNECTION_UNCONNECT_TOUT_FLAGS(a)                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,6)
#define	SET_GIGASPWR_STATE_CONNECTION_UNCONNECT_TOUT_FLAGS(reg,f)            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,6)

#define	OFFSET_GIGASPWR_SW_DAT_TOUTS_G_DAT_TOUT                              	0
#define	GIGASPWR_SW_DAT_TOUTS_G_DAT_TOUT(a)                                  	GIGASPWR_REG_FIELDS_H_FIELD(a,15,0)
#define	GET_GIGASPWR_SW_DAT_TOUTS_G_DAT_TOUT(a)                              	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,15,0)
#define	SET_GIGASPWR_SW_DAT_TOUTS_G_DAT_TOUT(reg,f)                          	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,15,0)

#define	OFFSET_GIGASPWR_SW_DAT_TOUTS_ARB_TOUT                                	16
#define	GIGASPWR_SW_DAT_TOUTS_ARB_TOUT(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,25,16)
#define	GET_GIGASPWR_SW_DAT_TOUTS_ARB_TOUT(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,25,16)
#define	SET_GIGASPWR_SW_DAT_TOUTS_ARB_TOUT(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,25,16)

#define	OFFSET_GIGASPWR_SW_DAT_TOUTS_T_MODE                                  	26
#define	GIGASPWR_SW_DAT_TOUTS_T_MODE(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,26,26)
#define	GET_GIGASPWR_SW_DAT_TOUTS_T_MODE(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,26,26)
#define	SET_GIGASPWR_SW_DAT_TOUTS_T_MODE(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,26,26)

#define	OFFSET_GIGASPWR_SW_DAT_TOUTS2_RT_TOUT                                	0
#define	GIGASPWR_SW_DAT_TOUTS2_RT_TOUT(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,7,0)
#define	GET_GIGASPWR_SW_DAT_TOUTS2_RT_TOUT(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,7,0)
#define	SET_GIGASPWR_SW_DAT_TOUTS2_RT_TOUT(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,7,0)

#define	OFFSET_GIGASPWR_SW_DAT_TOUTS2_R_TOUT_VALID                           	8
#define	GIGASPWR_SW_DAT_TOUTS2_R_TOUT_VALID(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	GET_GIGASPWR_SW_DAT_TOUTS2_R_TOUT_VALID(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	SET_GIGASPWR_SW_DAT_TOUTS2_R_TOUT_VALID(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,8,8)

#define	OFFSET_GIGASPWR_SW_DAT_TOUTS2_T_TOUT_VALID                           	9
#define	GIGASPWR_SW_DAT_TOUTS2_T_TOUT_VALID(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	GET_GIGASPWR_SW_DAT_TOUTS2_T_TOUT_VALID(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	SET_GIGASPWR_SW_DAT_TOUTS2_T_TOUT_VALID(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,9,9)

#define	OFFSET_GIGASPWR_SW_DAT_TOUTS3_T_TOUT_FLS                             	0
#define	GIGASPWR_SW_DAT_TOUTS3_T_TOUT_FLS(a)                                 	GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	GET_GIGASPWR_SW_DAT_TOUTS3_T_TOUT_FLS(a)                             	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	SET_GIGASPWR_SW_DAT_TOUTS3_T_TOUT_FLS(reg,f)                         	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,5,0)

#define	OFFSET_GIGASPWR_SW_DAT_TOUTS3_R_TOUT_FLS                             	6
#define	GIGASPWR_SW_DAT_TOUTS3_R_TOUT_FLS(a)                                 	GIGASPWR_REG_FIELDS_H_FIELD(a,11,6)
#define	GET_GIGASPWR_SW_DAT_TOUTS3_R_TOUT_FLS(a)                             	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,6)
#define	SET_GIGASPWR_SW_DAT_TOUTS3_R_TOUT_FLS(reg,f)                         	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,6)

#define	OFFSET_GIGASPWR_SW_DAT_TOUTS3_ARB_TOUT_FLS                           	12
#define	GIGASPWR_SW_DAT_TOUTS3_ARB_TOUT_FLS(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,17,12)
#define	GET_GIGASPWR_SW_DAT_TOUTS3_ARB_TOUT_FLS(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,17,12)
#define	SET_GIGASPWR_SW_DAT_TOUTS3_ARB_TOUT_FLS(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,17,12)

#define	OFFSET_GIGASPWR_SPEC_ARB_SPW_SPEC_ARB                                	0
#define	GIGASPWR_SPEC_ARB_SPW_SPEC_ARB(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	GET_GIGASPWR_SPEC_ARB_SPW_SPEC_ARB(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	SET_GIGASPWR_SPEC_ARB_SPW_SPEC_ARB(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,0)

#define	OFFSET_GIGASPWR_SPEC_ARB_CONF_SPEC_ARB                               	7
#define	GIGASPWR_SPEC_ARB_CONF_SPEC_ARB(a)                                   	GIGASPWR_REG_FIELDS_H_FIELD(a,13,7)
#define	GET_GIGASPWR_SPEC_ARB_CONF_SPEC_ARB(a)                               	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,13,7)
#define	SET_GIGASPWR_SPEC_ARB_CONF_SPEC_ARB(reg,f)                           	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,13,7)

#define	OFFSET_GIGASPWR_CCODE_OUT_CCODE_OUT                                  	0
#define	GIGASPWR_CCODE_OUT_CCODE_OUT(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,7,0)
#define	GET_GIGASPWR_CCODE_OUT_CCODE_OUT(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,7,0)
#define	SET_GIGASPWR_CCODE_OUT_CCODE_OUT(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,7,0)

#define	OFFSET_GIGASPWR_CCODE_OUT_TX_PORTS                                   	8
#define	GIGASPWR_CCODE_OUT_TX_PORTS(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,13,8)
#define	GET_GIGASPWR_CCODE_OUT_TX_PORTS(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,13,8)
#define	SET_GIGASPWR_CCODE_OUT_TX_PORTS(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,13,8)

#define	OFFSET_GIGASPWR_CCODE_OUT_TX_PORTS_FL                                	14
#define	GIGASPWR_CCODE_OUT_TX_PORTS_FL(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,14,14)
#define	GET_GIGASPWR_CCODE_OUT_TX_PORTS_FL(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,14,14)
#define	SET_GIGASPWR_CCODE_OUT_TX_PORTS_FL(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,14,14)

#define	OFFSET_GIGASPWR_CUR_TIME_CUR_TIME                                    	0
#define	GIGASPWR_CUR_TIME_CUR_TIME(a)                                        	GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	GET_GIGASPWR_CUR_TIME_CUR_TIME(a)                                    	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	SET_GIGASPWR_CUR_TIME_CUR_TIME(reg,f)                                	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,5,0)

#define	OFFSET_GIGASPWR_CUR_TIME_TRUE_TIME                                   	6
#define	GIGASPWR_CUR_TIME_TRUE_TIME(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,11,6)
#define	GET_GIGASPWR_CUR_TIME_TRUE_TIME(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,6)
#define	SET_GIGASPWR_CUR_TIME_TRUE_TIME(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,6)

#define	OFFSET_GIGASPWR_ISR_L_ISR_L                                          	0
#define	GIGASPWR_ISR_L_ISR_L(a)                                              	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_ISR_L_ISR_L(a)                                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_ISR_L_ISR_L(reg,f)                                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_ISR_H_ISR_H                                          	0
#define	GIGASPWR_ISR_H_ISR_H(a)                                              	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_ISR_H_ISR_H(a)                                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_ISR_H_ISR_H(reg,f)                                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_INTR_IRQ_MASK_L_INTR_IRQ_MASK_L                      	0
#define	GIGASPWR_INTR_IRQ_MASK_L_INTR_IRQ_MASK_L(a)                          	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_INTR_IRQ_MASK_L_INTR_IRQ_MASK_L(a)                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_INTR_IRQ_MASK_L_INTR_IRQ_MASK_L(reg,f)                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_INTR_IRQ_MASK_H_INTR_IRQ_MASK_H                      	0
#define	GIGASPWR_INTR_IRQ_MASK_H_INTR_IRQ_MASK_H(a)                          	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_INTR_IRQ_MASK_H_INTR_IRQ_MASK_H(a)                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_INTR_IRQ_MASK_H_INTR_IRQ_MASK_H(reg,f)                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_INTA_IRQ_MASK_L_INTA_IRQ_MASK_L                      	0
#define	GIGASPWR_INTA_IRQ_MASK_L_INTA_IRQ_MASK_L(a)                          	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_INTA_IRQ_MASK_L_INTA_IRQ_MASK_L(a)                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_INTA_IRQ_MASK_L_INTA_IRQ_MASK_L(reg,f)                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_INTA_IRQ_MASK_H_INTA_IRQ_MASK_H                      	0
#define	GIGASPWR_INTA_IRQ_MASK_H_INTA_IRQ_MASK_H(a)                          	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_INTA_IRQ_MASK_H_INTA_IRQ_MASK_H(a)                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_INTA_IRQ_MASK_H_INTA_IRQ_MASK_H(reg,f)                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_CCODES_MASK1_TIME_SEND_MASK                          	0
#define	GIGASPWR_CCODES_MASK1_TIME_SEND_MASK(a)                              	GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	GET_GIGASPWR_CCODES_MASK1_TIME_SEND_MASK(a)                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	SET_GIGASPWR_CCODES_MASK1_TIME_SEND_MASK(reg,f)                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,5,0)

#define	OFFSET_GIGASPWR_CCODES_MASK1_TIME_RECEIVE_MASK                       	6
#define	GIGASPWR_CCODES_MASK1_TIME_RECEIVE_MASK(a)                           	GIGASPWR_REG_FIELDS_H_FIELD(a,11,6)
#define	GET_GIGASPWR_CCODES_MASK1_TIME_RECEIVE_MASK(a)                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,6)
#define	SET_GIGASPWR_CCODES_MASK1_TIME_RECEIVE_MASK(reg,f)                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,6)

#define	OFFSET_GIGASPWR_CCODES_MASK1_INT_R_A_SEND_MASK                       	12
#define	GIGASPWR_CCODES_MASK1_INT_R_A_SEND_MASK(a)                           	GIGASPWR_REG_FIELDS_H_FIELD(a,17,12)
#define	GET_GIGASPWR_CCODES_MASK1_INT_R_A_SEND_MASK(a)                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,17,12)
#define	SET_GIGASPWR_CCODES_MASK1_INT_R_A_SEND_MASK(reg,f)                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,17,12)

#define	OFFSET_GIGASPWR_CCODES_MASK1_INT_R_A_RECEIVE_MASK                    	18
#define	GIGASPWR_CCODES_MASK1_INT_R_A_RECEIVE_MASK(a)                        	GIGASPWR_REG_FIELDS_H_FIELD(a,23,18)
#define	GET_GIGASPWR_CCODES_MASK1_INT_R_A_RECEIVE_MASK(a)                    	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,23,18)
#define	SET_GIGASPWR_CCODES_MASK1_INT_R_A_RECEIVE_MASK(reg,f)                	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,23,18)

#define	OFFSET_GIGASPWR_CCODES_MASK2_INTR_SEND_MASK                          	0
#define	GIGASPWR_CCODES_MASK2_INTR_SEND_MASK(a)                              	GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	GET_GIGASPWR_CCODES_MASK2_INTR_SEND_MASK(a)                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	SET_GIGASPWR_CCODES_MASK2_INTR_SEND_MASK(reg,f)                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,5,0)

#define	OFFSET_GIGASPWR_CCODES_MASK2_INTR_RECEIVE_MASK                       	6
#define	GIGASPWR_CCODES_MASK2_INTR_RECEIVE_MASK(a)                           	GIGASPWR_REG_FIELDS_H_FIELD(a,11,6)
#define	GET_GIGASPWR_CCODES_MASK2_INTR_RECEIVE_MASK(a)                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,6)
#define	SET_GIGASPWR_CCODES_MASK2_INTR_RECEIVE_MASK(reg,f)                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,6)

#define	OFFSET_GIGASPWR_CCODES_MASK2_INTA_SEND_MASK                          	12
#define	GIGASPWR_CCODES_MASK2_INTA_SEND_MASK(a)                              	GIGASPWR_REG_FIELDS_H_FIELD(a,17,12)
#define	GET_GIGASPWR_CCODES_MASK2_INTA_SEND_MASK(a)                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,17,12)
#define	SET_GIGASPWR_CCODES_MASK2_INTA_SEND_MASK(reg,f)                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,17,12)

#define	OFFSET_GIGASPWR_CCODES_MASK2_INTA_RECEIVE_MASK                       	18
#define	GIGASPWR_CCODES_MASK2_INTA_RECEIVE_MASK(a)                           	GIGASPWR_REG_FIELDS_H_FIELD(a,23,18)
#define	GET_GIGASPWR_CCODES_MASK2_INTA_RECEIVE_MASK(a)                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,23,18)
#define	SET_GIGASPWR_CCODES_MASK2_INTA_RECEIVE_MASK(reg,f)                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,23,18)

#define	OFFSET_GIGASPWR_CCODES_MASK2_ADD_RECEIVE_MASK                        	24
#define	GIGASPWR_CCODES_MASK2_ADD_RECEIVE_MASK(a)                            	GIGASPWR_REG_FIELDS_H_FIELD(a,29,24)
#define	GET_GIGASPWR_CCODES_MASK2_ADD_RECEIVE_MASK(a)                        	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,29,24)
#define	SET_GIGASPWR_CCODES_MASK2_ADD_RECEIVE_MASK(reg,f)                    	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,29,24)

#define	OFFSET_GIGASPWR_DIST_INTS_TOUTS1_GLOB_COU_VAL                        	0
#define	GIGASPWR_DIST_INTS_TOUTS1_GLOB_COU_VAL(a)                            	GIGASPWR_REG_FIELDS_H_FIELD(a,15,0)
#define	GET_GIGASPWR_DIST_INTS_TOUTS1_GLOB_COU_VAL(a)                        	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,15,0)
#define	SET_GIGASPWR_DIST_INTS_TOUTS1_GLOB_COU_VAL(reg,f)                    	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,15,0)

#define	OFFSET_GIGASPWR_DIST_INTS_TOUTS1_LOC_COU_VAL_SW                      	16
#define	GIGASPWR_DIST_INTS_TOUTS1_LOC_COU_VAL_SW(a)                          	GIGASPWR_REG_FIELDS_H_FIELD(a,19,16)
#define	GET_GIGASPWR_DIST_INTS_TOUTS1_LOC_COU_VAL_SW(a)                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,19,16)
#define	SET_GIGASPWR_DIST_INTS_TOUTS1_LOC_COU_VAL_SW(reg,f)                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,19,16)

#define	OFFSET_GIGASPWR_DIST_INTS_TOUTS1_LOC_COU_VAL_T1                      	20
#define	GIGASPWR_DIST_INTS_TOUTS1_LOC_COU_VAL_T1(a)                          	GIGASPWR_REG_FIELDS_H_FIELD(a,23,20)
#define	GET_GIGASPWR_DIST_INTS_TOUTS1_LOC_COU_VAL_T1(a)                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,23,20)
#define	SET_GIGASPWR_DIST_INTS_TOUTS1_LOC_COU_VAL_T1(reg,f)                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,23,20)

#define	OFFSET_GIGASPWR_DIST_INTS_TOUTS1_LOC_COU_VAL_T2                      	24
#define	GIGASPWR_DIST_INTS_TOUTS1_LOC_COU_VAL_T2(a)                          	GIGASPWR_REG_FIELDS_H_FIELD(a,27,24)
#define	GET_GIGASPWR_DIST_INTS_TOUTS1_LOC_COU_VAL_T2(a)                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,27,24)
#define	SET_GIGASPWR_DIST_INTS_TOUTS1_LOC_COU_VAL_T2(reg,f)                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,27,24)

#define	OFFSET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_SW_NACK                 	0
#define	GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_SW_NACK(a)                     	GIGASPWR_REG_FIELDS_H_FIELD(a,3,0)
#define	GET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_SW_NACK(a)                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,3,0)
#define	SET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_SW_NACK(reg,f)             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,3,0)

#define	OFFSET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_T1_NACK                 	4
#define	GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_T1_NACK(a)                     	GIGASPWR_REG_FIELDS_H_FIELD(a,7,4)
#define	GET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_T1_NACK(a)                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,7,4)
#define	SET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_T1_NACK(reg,f)             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,7,4)

#define	OFFSET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_TG                      	8
#define	GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_TG(a)                          	GIGASPWR_REG_FIELDS_H_FIELD(a,11,8)
#define	GET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_TG(a)                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,8)
#define	SET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_TG(reg,f)                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,8)

#define	OFFSET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_TH                      	12
#define	GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_TH(a)                          	GIGASPWR_REG_FIELDS_H_FIELD(a,15,12)
#define	GET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_TH(a)                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,15,12)
#define	SET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_TH(reg,f)                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,15,12)

#define	OFFSET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_ISR_CH_ACK              	16
#define	GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_ISR_CH_ACK(a)                  	GIGASPWR_REG_FIELDS_H_FIELD(a,19,16)
#define	GET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_ISR_CH_ACK(a)              	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,19,16)
#define	SET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_ISR_CH_ACK(reg,f)          	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,19,16)

#define	OFFSET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_ISR_CH_NACK             	20
#define	GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_ISR_CH_NACK(a)                 	GIGASPWR_REG_FIELDS_H_FIELD(a,23,20)
#define	GET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_ISR_CH_NACK(a)             	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,23,20)
#define	SET_GIGASPWR_DIST_INTS_TOUTS2_LOC_COU_VAL_ISR_CH_NACK(reg,f)         	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,23,20)

#define	OFFSET_GIGASPWR_ACK_NON_ACK_REGIME_ACK_NON_ACK_REGIME                	0
#define	GIGASPWR_ACK_NON_ACK_REGIME_ACK_NON_ACK_REGIME(a)                    	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_ACK_NON_ACK_REGIME_ACK_NON_ACK_REGIME(a)                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_ACK_NON_ACK_REGIME_ACK_NON_ACK_REGIME(reg,f)            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_CCODES_SPEC_REGIME_CODE_TYPE                         	0
#define	GIGASPWR_CCODES_SPEC_REGIME_CODE_TYPE(a)                             	GIGASPWR_REG_FIELDS_H_FIELD(a,1,0)
#define	GET_GIGASPWR_CCODES_SPEC_REGIME_CODE_TYPE(a)                         	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,1,0)
#define	SET_GIGASPWR_CCODES_SPEC_REGIME_CODE_TYPE(reg,f)                     	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,1,0)

#define	OFFSET_GIGASPWR_CCODES_SPEC_REGIME_CODE_HL                           	2
#define	GIGASPWR_CCODES_SPEC_REGIME_CODE_HL(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,2,2)
#define	GET_GIGASPWR_CCODES_SPEC_REGIME_CODE_HL(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,2,2)
#define	SET_GIGASPWR_CCODES_SPEC_REGIME_CODE_HL(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,2,2)

#define	OFFSET_GIGASPWR_CCODES_SPEC_REGIME_CODE_NUM                          	3
#define	GIGASPWR_CCODES_SPEC_REGIME_CODE_NUM(a)                              	GIGASPWR_REG_FIELDS_H_FIELD(a,8,3)
#define	GET_GIGASPWR_CCODES_SPEC_REGIME_CODE_NUM(a)                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,8,3)
#define	SET_GIGASPWR_CCODES_SPEC_REGIME_CODE_NUM(reg,f)                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,8,3)

#define	OFFSET_GIGASPWR_CCODES_SPEC_REGIME_LAST_PORT                         	9
#define	GIGASPWR_CCODES_SPEC_REGIME_LAST_PORT(a)                             	GIGASPWR_REG_FIELDS_H_FIELD(a,13,9)
#define	GET_GIGASPWR_CCODES_SPEC_REGIME_LAST_PORT(a)                         	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,13,9)
#define	SET_GIGASPWR_CCODES_SPEC_REGIME_LAST_PORT(reg,f)                     	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,13,9)

#define	OFFSET_GIGASPWR_SPEC_ISR_REGIME_SPEC_ISR_REGIME                      	0
#define	GIGASPWR_SPEC_ISR_REGIME_SPEC_ISR_REGIME(a)                          	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_SPEC_ISR_REGIME_SPEC_ISR_REGIME(a)                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_SPEC_ISR_REGIME_SPEC_ISR_REGIME(reg,f)                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_INTER_HANDLER_TERM_FUNCT_INTER_HANDLER_TERM_FUNCT    	0
#define	GIGASPWR_INTER_HANDLER_TERM_FUNCT_INTER_HANDLER_TERM_FUNCT(a)        	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_INTER_HANDLER_TERM_FUNCT_INTER_HANDLER_TERM_FUNCT(a)    	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_INTER_HANDLER_TERM_FUNCT_INTER_HANDLER_TERM_FUNCT(reg,f)	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_ISR_SOURCE_TERM_FUNCT_ISR_SOURCE_TERM_FUNCT          	0
#define	GIGASPWR_ISR_SOURCE_TERM_FUNCT_ISR_SOURCE_TERM_FUNCT(a)              	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_ISR_SOURCE_TERM_FUNCT_ISR_SOURCE_TERM_FUNCT(a)          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_ISR_SOURCE_TERM_FUNCT_ISR_SOURCE_TERM_FUNCT(reg,f)      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_ISR_TOUTS_FLS_L_ISR_TOUTS_FLS_L                      	0
#define	GIGASPWR_ISR_TOUTS_FLS_L_ISR_TOUTS_FLS_L(a)                          	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_ISR_TOUTS_FLS_L_ISR_TOUTS_FLS_L(a)                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_ISR_TOUTS_FLS_L_ISR_TOUTS_FLS_L(reg,f)                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_ISR_TOUTS_FLS_H_ISR_TOUTS_FLS_H                      	0
#define	GIGASPWR_ISR_TOUTS_FLS_H_ISR_TOUTS_FLS_H(a)                          	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_ISR_TOUTS_FLS_H_ISR_TOUTS_FLS_H(a)                      	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_ISR_TOUTS_FLS_H_ISR_TOUTS_FLS_H(reg,f)                  	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_ISR_1101_ISR_1101                                    	0
#define	GIGASPWR_ISR_1101_ISR_1101(a)                                        	GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	GET_GIGASPWR_ISR_1101_ISR_1101(a)                                    	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,0)
#define	SET_GIGASPWR_ISR_1101_ISR_1101(reg,f)                                	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,0)

#define	OFFSET_GIGASPWR_EXTERNAL_RESET_PARAMETERS_INT_RES_GLOB_COU           	0
#define	GIGASPWR_EXTERNAL_RESET_PARAMETERS_INT_RES_GLOB_COU(a)               	GIGASPWR_REG_FIELDS_H_FIELD(a,15,0)
#define	GET_GIGASPWR_EXTERNAL_RESET_PARAMETERS_INT_RES_GLOB_COU(a)           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,15,0)
#define	SET_GIGASPWR_EXTERNAL_RESET_PARAMETERS_INT_RES_GLOB_COU(reg,f)       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,15,0)

#define	OFFSET_GIGASPWR_EXTERNAL_RESET_PARAMETERS_INT_RES_LOC_COU            	16
#define	GIGASPWR_EXTERNAL_RESET_PARAMETERS_INT_RES_LOC_COU(a)                	GIGASPWR_REG_FIELDS_H_FIELD(a,21,16)
#define	GET_GIGASPWR_EXTERNAL_RESET_PARAMETERS_INT_RES_LOC_COU(a)            	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,21,16)
#define	SET_GIGASPWR_EXTERNAL_RESET_PARAMETERS_INT_RES_LOC_COU(reg,f)        	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,21,16)

#define	OFFSET_GIGASPWR_EXTERNAL_RESET_PARAMETERS_RST_AFTER_COU              	22
#define	GIGASPWR_EXTERNAL_RESET_PARAMETERS_RST_AFTER_COU(a)                  	GIGASPWR_REG_FIELDS_H_FIELD(a,30,22)
#define	GET_GIGASPWR_EXTERNAL_RESET_PARAMETERS_RST_AFTER_COU(a)              	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,30,22)
#define	SET_GIGASPWR_EXTERNAL_RESET_PARAMETERS_RST_AFTER_COU(reg,f)          	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,30,22)

#define	OFFSET_GIGASPWR_EXTERNAL_RESET_PARAMETERS_INT_RES_MODE               	31
#define	GIGASPWR_EXTERNAL_RESET_PARAMETERS_INT_RES_MODE(a)                   	GIGASPWR_REG_FIELDS_H_FIELD(a,31,31)
#define	GET_GIGASPWR_EXTERNAL_RESET_PARAMETERS_INT_RES_MODE(a)               	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,31)
#define	SET_GIGASPWR_EXTERNAL_RESET_PARAMETERS_INT_RES_MODE(reg,f)           	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,31)

#define	OFFSET_GIGASPWR_SPW_STATUS_DC_ERR                                    	0
#define	GIGASPWR_SPW_STATUS_DC_ERR(a)                                        	GIGASPWR_REG_FIELDS_H_FIELD(a,0,0)
#define	GET_GIGASPWR_SPW_STATUS_DC_ERR(a)                                    	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,0,0)
#define	SET_GIGASPWR_SPW_STATUS_DC_ERR(reg,f)                                	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,0,0)

#define	OFFSET_GIGASPWR_SPW_STATUS_P_ERR                                     	1
#define	GIGASPWR_SPW_STATUS_P_ERR(a)                                         	GIGASPWR_REG_FIELDS_H_FIELD(a,1,1)
#define	GET_GIGASPWR_SPW_STATUS_P_ERR(a)                                     	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,1,1)
#define	SET_GIGASPWR_SPW_STATUS_P_ERR(reg,f)                                 	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,1,1)

#define	OFFSET_GIGASPWR_SPW_STATUS_ESC_ERR                                   	2
#define	GIGASPWR_SPW_STATUS_ESC_ERR(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,2,2)
#define	GET_GIGASPWR_SPW_STATUS_ESC_ERR(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,2,2)
#define	SET_GIGASPWR_SPW_STATUS_ESC_ERR(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,2,2)

#define	OFFSET_GIGASPWR_SPW_STATUS_CREDIT_ERR                                	3
#define	GIGASPWR_SPW_STATUS_CREDIT_ERR(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,3,3)
#define	GET_GIGASPWR_SPW_STATUS_CREDIT_ERR(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,3,3)
#define	SET_GIGASPWR_SPW_STATUS_CREDIT_ERR(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,3,3)

#define	OFFSET_GIGASPWR_SPW_STATUS_BDS_STATE                                 	4
#define	GIGASPWR_SPW_STATUS_BDS_STATE(a)                                     	GIGASPWR_REG_FIELDS_H_FIELD(a,6,4)
#define	GET_GIGASPWR_SPW_STATUS_BDS_STATE(a)                                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,4)
#define	SET_GIGASPWR_SPW_STATUS_BDS_STATE(reg,f)                             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,4)

#define	OFFSET_GIGASPWR_SPW_STATUS_BUF_FULL                                  	7
#define	GIGASPWR_SPW_STATUS_BUF_FULL(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,7,7)
#define	GET_GIGASPWR_SPW_STATUS_BUF_FULL(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,7,7)
#define	SET_GIGASPWR_SPW_STATUS_BUF_FULL(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,7,7)

#define	OFFSET_GIGASPWR_SPW_STATUS_BUF_EMPTY                                 	8
#define	GIGASPWR_SPW_STATUS_BUF_EMPTY(a)                                     	GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	GET_GIGASPWR_SPW_STATUS_BUF_EMPTY(a)                                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	SET_GIGASPWR_SPW_STATUS_BUF_EMPTY(reg,f)                             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,8,8)

#define	OFFSET_GIGASPWR_SPW_STATUS_DISC_D_SPW                                	9
#define	GIGASPWR_SPW_STATUS_DISC_D_SPW(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	GET_GIGASPWR_SPW_STATUS_DISC_D_SPW(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	SET_GIGASPWR_SPW_STATUS_DISC_D_SPW(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,9,9)

#define	OFFSET_GIGASPWR_SPW_STATUS_DISC_S_SPW                                	10
#define	GIGASPWR_SPW_STATUS_DISC_S_SPW(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,10,10)
#define	GET_GIGASPWR_SPW_STATUS_DISC_S_SPW(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,10,10)
#define	SET_GIGASPWR_SPW_STATUS_DISC_S_SPW(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,10,10)

#define	OFFSET_GIGASPWR_SPW_STATUS_LVDS_D_IN                                 	11
#define	GIGASPWR_SPW_STATUS_LVDS_D_IN(a)                                     	GIGASPWR_REG_FIELDS_H_FIELD(a,11,11)
#define	GET_GIGASPWR_SPW_STATUS_LVDS_D_IN(a)                                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,11)
#define	SET_GIGASPWR_SPW_STATUS_LVDS_D_IN(reg,f)                             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,11)

#define	OFFSET_GIGASPWR_SPW_STATUS_LVDS_S_IN                                 	12
#define	GIGASPWR_SPW_STATUS_LVDS_S_IN(a)                                     	GIGASPWR_REG_FIELDS_H_FIELD(a,12,12)
#define	GET_GIGASPWR_SPW_STATUS_LVDS_S_IN(a)                                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,12,12)
#define	SET_GIGASPWR_SPW_STATUS_LVDS_S_IN(reg,f)                             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,12,12)

#define	OFFSET_GIGASPWR_SPW_STATUS_ARB_TOUT_ADDR                             	13
#define	GIGASPWR_SPW_STATUS_ARB_TOUT_ADDR(a)                                 	GIGASPWR_REG_FIELDS_H_FIELD(a,20,13)
#define	GET_GIGASPWR_SPW_STATUS_ARB_TOUT_ADDR(a)                             	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,20,13)
#define	SET_GIGASPWR_SPW_STATUS_ARB_TOUT_ADDR(reg,f)                         	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,20,13)

#define	OFFSET_GIGASPWR_SPW_MODE_LINKDISABLED                                	0
#define	GIGASPWR_SPW_MODE_LINKDISABLED(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,0,0)
#define	GET_GIGASPWR_SPW_MODE_LINKDISABLED(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,0,0)
#define	SET_GIGASPWR_SPW_MODE_LINKDISABLED(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,0,0)

#define	OFFSET_GIGASPWR_SPW_MODE_AUTOSTART                                   	1
#define	GIGASPWR_SPW_MODE_AUTOSTART(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,1,1)
#define	GET_GIGASPWR_SPW_MODE_AUTOSTART(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,1,1)
#define	SET_GIGASPWR_SPW_MODE_AUTOSTART(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,1,1)

#define	OFFSET_GIGASPWR_SPW_MODE_LINKSTART                                   	2
#define	GIGASPWR_SPW_MODE_LINKSTART(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,2,2)
#define	GET_GIGASPWR_SPW_MODE_LINKSTART(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,2,2)
#define	SET_GIGASPWR_SPW_MODE_LINKSTART(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,2,2)

#define	OFFSET_GIGASPWR_SPW_MODE_BDS_RESET                                   	3
#define	GIGASPWR_SPW_MODE_BDS_RESET(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,3,3)
#define	GET_GIGASPWR_SPW_MODE_BDS_RESET(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,3,3)
#define	SET_GIGASPWR_SPW_MODE_BDS_RESET(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,3,3)

#define	OFFSET_GIGASPWR_SPW_MODE_CODEC_LOOPBACK                              	4
#define	GIGASPWR_SPW_MODE_CODEC_LOOPBACK(a)                                  	GIGASPWR_REG_FIELDS_H_FIELD(a,4,4)
#define	GET_GIGASPWR_SPW_MODE_CODEC_LOOPBACK(a)                              	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,4,4)
#define	SET_GIGASPWR_SPW_MODE_CODEC_LOOPBACK(reg,f)                          	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,4,4)

#define	OFFSET_GIGASPWR_SPW_MODE_LVDS_LOOPBACK                               	5
#define	GIGASPWR_SPW_MODE_LVDS_LOOPBACK(a)                                   	GIGASPWR_REG_FIELDS_H_FIELD(a,5,5)
#define	GET_GIGASPWR_SPW_MODE_LVDS_LOOPBACK(a)                               	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,5,5)
#define	SET_GIGASPWR_SPW_MODE_LVDS_LOOPBACK(reg,f)                           	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,5,5)

#define	OFFSET_GIGASPWR_SPW_MODE_RX_SINGLE                                   	6
#define	GIGASPWR_SPW_MODE_RX_SINGLE(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,6,6)
#define	GET_GIGASPWR_SPW_MODE_RX_SINGLE(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,6)
#define	SET_GIGASPWR_SPW_MODE_RX_SINGLE(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,6)

#define	OFFSET_GIGASPWR_SPW_MODE_TX_SINGLE                                   	7
#define	GIGASPWR_SPW_MODE_TX_SINGLE(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,7,7)
#define	GET_GIGASPWR_SPW_MODE_TX_SINGLE(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,7,7)
#define	SET_GIGASPWR_SPW_MODE_TX_SINGLE(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,7,7)

#define	OFFSET_GIGASPWR_SPW_MODE_FIELDNAME9                                  	8
#define	GIGASPWR_SPW_MODE_FIELDNAME9(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	GET_GIGASPWR_SPW_MODE_FIELDNAME9(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	SET_GIGASPWR_SPW_MODE_FIELDNAME9(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,8,8)

#define	OFFSET_GIGASPWR_SPW_MODE_AUTO_SPEED_MODE                             	9
#define	GIGASPWR_SPW_MODE_AUTO_SPEED_MODE(a)                                 	GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	GET_GIGASPWR_SPW_MODE_AUTO_SPEED_MODE(a)                             	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	SET_GIGASPWR_SPW_MODE_AUTO_SPEED_MODE(reg,f)                         	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,9,9)

#define	OFFSET_GIGASPWR_SPW_MODE_KOEFF_10_LOCAL                              	10
#define	GIGASPWR_SPW_MODE_KOEFF_10_LOCAL(a)                                  	GIGASPWR_REG_FIELDS_H_FIELD(a,18,10)
#define	GET_GIGASPWR_SPW_MODE_KOEFF_10_LOCAL(a)                              	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,18,10)
#define	SET_GIGASPWR_SPW_MODE_KOEFF_10_LOCAL(reg,f)                          	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,18,10)

#define	OFFSET_GIGASPWR_SPW_MODE_D_INT_ACK_REGIMES                           	19
#define	GIGASPWR_SPW_MODE_D_INT_ACK_REGIMES(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,19,19)
#define	GET_GIGASPWR_SPW_MODE_D_INT_ACK_REGIMES(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,19,19)
#define	SET_GIGASPWR_SPW_MODE_D_INT_ACK_REGIMES(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,19,19)

#define	OFFSET_GIGASPWR_SPW_MODE_INT_CODES                                   	20
#define	GIGASPWR_SPW_MODE_INT_CODES(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,22,20)
#define	GET_GIGASPWR_SPW_MODE_INT_CODES(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,22,20)
#define	SET_GIGASPWR_SPW_MODE_INT_CODES(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,22,20)

#define	OFFSET_GIGASPWR_SPW_MODE_ACK_CODES                                   	23
#define	GIGASPWR_SPW_MODE_ACK_CODES(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,25,23)
#define	GET_GIGASPWR_SPW_MODE_ACK_CODES(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,25,23)
#define	SET_GIGASPWR_SPW_MODE_ACK_CODES(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,25,23)

#define	OFFSET_GIGASPWR_SPW_MODE_LVDS_CONTROL                                	26
#define	GIGASPWR_SPW_MODE_LVDS_CONTROL(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,26,26)
#define	GET_GIGASPWR_SPW_MODE_LVDS_CONTROL(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,26,26)
#define	SET_GIGASPWR_SPW_MODE_LVDS_CONTROL(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,26,26)

#define	OFFSET_GIGASPWR_SPW_MODE_LVDS_D_OUT                                  	27
#define	GIGASPWR_SPW_MODE_LVDS_D_OUT(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,27,27)
#define	GET_GIGASPWR_SPW_MODE_LVDS_D_OUT(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,27,27)
#define	SET_GIGASPWR_SPW_MODE_LVDS_D_OUT(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,27,27)

#define	OFFSET_GIGASPWR_SPW_MODE_LVDS_S_OUT                                  	28
#define	GIGASPWR_SPW_MODE_LVDS_S_OUT(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,28,28)
#define	GET_GIGASPWR_SPW_MODE_LVDS_S_OUT(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,28,28)
#define	SET_GIGASPWR_SPW_MODE_LVDS_S_OUT(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,28,28)

#define	OFFSET_GIGASPWR_SPW_TX_SPEED_TX_SPEED                                	0
#define	GIGASPWR_SPW_TX_SPEED_TX_SPEED(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,9,0)
#define	GET_GIGASPWR_SPW_TX_SPEED_TX_SPEED(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,9,0)
#define	SET_GIGASPWR_SPW_TX_SPEED_TX_SPEED(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,9,0)

#define	OFFSET_GIGASPWR_SPW_TX_SPEED_TX_SPEED10                              	10
#define	GIGASPWR_SPW_TX_SPEED_TX_SPEED10(a)                                  	GIGASPWR_REG_FIELDS_H_FIELD(a,19,10)
#define	GET_GIGASPWR_SPW_TX_SPEED_TX_SPEED10(a)                              	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,19,10)
#define	SET_GIGASPWR_SPW_TX_SPEED_TX_SPEED10(reg,f)                          	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,19,10)

#define	OFFSET_GIGASPWR_GIGA_SPW_TX_SPEED_KOEFF_COMMA                        	0
#define	GIGASPWR_GIGA_SPW_TX_SPEED_KOEFF_COMMA(a)                            	GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	GET_GIGASPWR_GIGA_SPW_TX_SPEED_KOEFF_COMMA(a)                        	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,5,0)
#define	SET_GIGASPWR_GIGA_SPW_TX_SPEED_KOEFF_COMMA(reg,f)                    	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,5,0)

#define	OFFSET_GIGASPWR_GIGA_SPW_TX_SPEED_DISCONNECT_COUNTER                 	6
#define	GIGASPWR_GIGA_SPW_TX_SPEED_DISCONNECT_COUNTER(a)                     	GIGASPWR_REG_FIELDS_H_FIELD(a,9,6)
#define	GET_GIGASPWR_GIGA_SPW_TX_SPEED_DISCONNECT_COUNTER(a)                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,9,6)
#define	SET_GIGASPWR_GIGA_SPW_TX_SPEED_DISCONNECT_COUNTER(reg,f)             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,9,6)

#define	OFFSET_GIGASPWR_GIGA_SPW_TX_SPEED_PWDN_TX                            	10
#define	GIGASPWR_GIGA_SPW_TX_SPEED_PWDN_TX(a)                                	GIGASPWR_REG_FIELDS_H_FIELD(a,10,10)
#define	GET_GIGASPWR_GIGA_SPW_TX_SPEED_PWDN_TX(a)                            	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,10,10)
#define	SET_GIGASPWR_GIGA_SPW_TX_SPEED_PWDN_TX(reg,f)                        	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,10,10)

#define	OFFSET_GIGASPWR_GIGA_SPW_TX_SPEED_PWDN_RX                            	11
#define	GIGASPWR_GIGA_SPW_TX_SPEED_PWDN_RX(a)                                	GIGASPWR_REG_FIELDS_H_FIELD(a,11,11)
#define	GET_GIGASPWR_GIGA_SPW_TX_SPEED_PWDN_RX(a)                            	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,11)
#define	SET_GIGASPWR_GIGA_SPW_TX_SPEED_PWDN_RX(reg,f)                        	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,11)

#define	OFFSET_GIGASPWR_GIGA_SPW_TX_SPEED_COMMAEN                            	12
#define	GIGASPWR_GIGA_SPW_TX_SPEED_COMMAEN(a)                                	GIGASPWR_REG_FIELDS_H_FIELD(a,12,12)
#define	GET_GIGASPWR_GIGA_SPW_TX_SPEED_COMMAEN(a)                            	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,12,12)
#define	SET_GIGASPWR_GIGA_SPW_TX_SPEED_COMMAEN(reg,f)                        	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,12,12)

#define	OFFSET_GIGASPWR_GIGA_SPW_TX_SPEED_COMPARE_EN                         	13
#define	GIGASPWR_GIGA_SPW_TX_SPEED_COMPARE_EN(a)                             	GIGASPWR_REG_FIELDS_H_FIELD(a,13,13)
#define	GET_GIGASPWR_GIGA_SPW_TX_SPEED_COMPARE_EN(a)                         	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,13,13)
#define	SET_GIGASPWR_GIGA_SPW_TX_SPEED_COMPARE_EN(reg,f)                     	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,13,13)

#define	OFFSET_GIGASPWR_SPW_RX_SPEED_RX_SPEED                                	0
#define	GIGASPWR_SPW_RX_SPEED_RX_SPEED(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,9,0)
#define	GET_GIGASPWR_SPW_RX_SPEED_RX_SPEED(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,9,0)
#define	SET_GIGASPWR_SPW_RX_SPEED_RX_SPEED(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,9,0)

#define	OFFSET_GIGASPWR_ADG_ADG                                              	0
#define	GIGASPWR_ADG_ADG(a)                                                  	GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	GET_GIGASPWR_ADG_ADG(a)                                              	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	SET_GIGASPWR_ADG_ADG(reg,f)                                          	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,0)

#define	OFFSET_GIGASPWR_GIGA_PMA_STATUS_ALIGN_STATE                          	0
#define	GIGASPWR_GIGA_PMA_STATUS_ALIGN_STATE(a)                              	GIGASPWR_REG_FIELDS_H_FIELD(a,3,0)
#define	GET_GIGASPWR_GIGA_PMA_STATUS_ALIGN_STATE(a)                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,3,0)
#define	SET_GIGASPWR_GIGA_PMA_STATUS_ALIGN_STATE(reg,f)                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,3,0)

#define	OFFSET_GIGASPWR_GIGA_PMA_STATUS_LOCK                                 	4
#define	GIGASPWR_GIGA_PMA_STATUS_LOCK(a)                                     	GIGASPWR_REG_FIELDS_H_FIELD(a,5,4)
#define	GET_GIGASPWR_GIGA_PMA_STATUS_LOCK(a)                                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,5,4)
#define	SET_GIGASPWR_GIGA_PMA_STATUS_LOCK(reg,f)                             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,5,4)

#define	OFFSET_GIGASPWR_GIGA_PMA_STATUS_ALIGN_ERROR                          	6
#define	GIGASPWR_GIGA_PMA_STATUS_ALIGN_ERROR(a)                              	GIGASPWR_REG_FIELDS_H_FIELD(a,6,6)
#define	GET_GIGASPWR_GIGA_PMA_STATUS_ALIGN_ERROR(a)                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,6)
#define	SET_GIGASPWR_GIGA_PMA_STATUS_ALIGN_ERROR(reg,f)                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,6)

#define	OFFSET_GIGASPWR_GIGA_PMA_STATUS_OVR                                  	7
#define	GIGASPWR_GIGA_PMA_STATUS_OVR(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,7,7)
#define	GET_GIGASPWR_GIGA_PMA_STATUS_OVR(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,7,7)
#define	SET_GIGASPWR_GIGA_PMA_STATUS_OVR(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,7,7)

#define	OFFSET_GIGASPWR_GIGA_PMA_STATUS_UNR                                  	8
#define	GIGASPWR_GIGA_PMA_STATUS_UNR(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	GET_GIGASPWR_GIGA_PMA_STATUS_UNR(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	SET_GIGASPWR_GIGA_PMA_STATUS_UNR(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,8,8)

#define	OFFSET_GIGASPWR_GIGA_SPW_PMA_MODE_PMA_RX_SPEED                       	0
#define	GIGASPWR_GIGA_SPW_PMA_MODE_PMA_RX_SPEED(a)                           	GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	GET_GIGASPWR_GIGA_SPW_PMA_MODE_PMA_RX_SPEED(a)                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	SET_GIGASPWR_GIGA_SPW_PMA_MODE_PMA_RX_SPEED(reg,f)                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,0)

#define	OFFSET_GIGASPWR_GIGA_SPW_PMA_MODE_ALIGN_MODE                         	7
#define	GIGASPWR_GIGA_SPW_PMA_MODE_ALIGN_MODE(a)                             	GIGASPWR_REG_FIELDS_H_FIELD(a,8,7)
#define	GET_GIGASPWR_GIGA_SPW_PMA_MODE_ALIGN_MODE(a)                         	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,8,7)
#define	SET_GIGASPWR_GIGA_SPW_PMA_MODE_ALIGN_MODE(reg,f)                     	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,8,7)

#define	OFFSET_GIGASPWR_GIGA_SPW_PMA_MODE_EN_PMA_RX                          	9
#define	GIGASPWR_GIGA_SPW_PMA_MODE_EN_PMA_RX(a)                              	GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	GET_GIGASPWR_GIGA_SPW_PMA_MODE_EN_PMA_RX(a)                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	SET_GIGASPWR_GIGA_SPW_PMA_MODE_EN_PMA_RX(reg,f)                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,9,9)

#define	OFFSET_GIGASPWR_GIGA_SPW_PMA_MODE_CDR_MODE                           	10
#define	GIGASPWR_GIGA_SPW_PMA_MODE_CDR_MODE(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,11,10)
#define	GET_GIGASPWR_GIGA_SPW_PMA_MODE_CDR_MODE(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,10)
#define	SET_GIGASPWR_GIGA_SPW_PMA_MODE_CDR_MODE(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,10)

#define	OFFSET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_RX                           	12
#define	GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_RX(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,12,12)
#define	GET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_RX(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,12,12)
#define	SET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_RX(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,12,12)

#define	OFFSET_GIGASPWR_GIGA_SPW_PMA_MODE_PMA_TX_SPEED                       	13
#define	GIGASPWR_GIGA_SPW_PMA_MODE_PMA_TX_SPEED(a)                           	GIGASPWR_REG_FIELDS_H_FIELD(a,19,13)
#define	GET_GIGASPWR_GIGA_SPW_PMA_MODE_PMA_TX_SPEED(a)                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,19,13)
#define	SET_GIGASPWR_GIGA_SPW_PMA_MODE_PMA_TX_SPEED(reg,f)                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,19,13)

#define	OFFSET_GIGASPWR_GIGA_SPW_PMA_MODE_EN_PMA_TX                          	20
#define	GIGASPWR_GIGA_SPW_PMA_MODE_EN_PMA_TX(a)                              	GIGASPWR_REG_FIELDS_H_FIELD(a,20,20)
#define	GET_GIGASPWR_GIGA_SPW_PMA_MODE_EN_PMA_TX(a)                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,20,20)
#define	SET_GIGASPWR_GIGA_SPW_PMA_MODE_EN_PMA_TX(reg,f)                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,20,20)

#define	OFFSET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_TX                           	21
#define	GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_TX(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,21,21)
#define	GET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_TX(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,21,21)
#define	SET_GIGASPWR_GIGA_SPW_PMA_MODE_LB_EN_TX(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,21,21)

#define	OFFSET_GIGASPWR_TX_PMA_CTR_TX_SPEED                                  	0
#define	GIGASPWR_TX_PMA_CTR_TX_SPEED(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	GET_GIGASPWR_TX_PMA_CTR_TX_SPEED(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	SET_GIGASPWR_TX_PMA_CTR_TX_SPEED(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,0)

#define	OFFSET_GIGASPWR_TX_PMA_CTR_LB_EN_TX                                  	15
#define	GIGASPWR_TX_PMA_CTR_LB_EN_TX(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,15,15)
#define	GET_GIGASPWR_TX_PMA_CTR_LB_EN_TX(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,15,15)
#define	SET_GIGASPWR_TX_PMA_CTR_LB_EN_TX(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,15,15)

#define	OFFSET_GIGASPWR_TX_PMA_CTR_TST_TX_CODE                               	16
#define	GIGASPWR_TX_PMA_CTR_TST_TX_CODE(a)                                   	GIGASPWR_REG_FIELDS_H_FIELD(a,25,16)
#define	GET_GIGASPWR_TX_PMA_CTR_TST_TX_CODE(a)                               	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,25,16)
#define	SET_GIGASPWR_TX_PMA_CTR_TST_TX_CODE(reg,f)                           	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,25,16)

#define	OFFSET_GIGASPWR_TX_PMA_CTR_TST_EN_TX_CODE                            	26
#define	GIGASPWR_TX_PMA_CTR_TST_EN_TX_CODE(a)                                	GIGASPWR_REG_FIELDS_H_FIELD(a,26,26)
#define	GET_GIGASPWR_TX_PMA_CTR_TST_EN_TX_CODE(a)                            	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,26,26)
#define	SET_GIGASPWR_TX_PMA_CTR_TST_EN_TX_CODE(reg,f)                        	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,26,26)

#define	OFFSET_GIGASPWR_TX_PMA_CTR_TST_WR_TX_CODE                            	27
#define	GIGASPWR_TX_PMA_CTR_TST_WR_TX_CODE(a)                                	GIGASPWR_REG_FIELDS_H_FIELD(a,27,27)
#define	GET_GIGASPWR_TX_PMA_CTR_TST_WR_TX_CODE(a)                            	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,27,27)
#define	SET_GIGASPWR_TX_PMA_CTR_TST_WR_TX_CODE(reg,f)                        	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,27,27)

#define	OFFSET_GIGASPWR_RX_PMA_CTR_RX_SPEED                                  	0
#define	GIGASPWR_RX_PMA_CTR_RX_SPEED(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	GET_GIGASPWR_RX_PMA_CTR_RX_SPEED(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	SET_GIGASPWR_RX_PMA_CTR_RX_SPEED(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,0)

#define	OFFSET_GIGASPWR_RX_PMA_CTR_ALIGN_MODE                                	8
#define	GIGASPWR_RX_PMA_CTR_ALIGN_MODE(a)                                    	GIGASPWR_REG_FIELDS_H_FIELD(a,9,8)
#define	GET_GIGASPWR_RX_PMA_CTR_ALIGN_MODE(a)                                	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,9,8)
#define	SET_GIGASPWR_RX_PMA_CTR_ALIGN_MODE(reg,f)                            	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,9,8)

#define	OFFSET_GIGASPWR_RX_PMA_CTR_CDR_MODE                                  	10
#define	GIGASPWR_RX_PMA_CTR_CDR_MODE(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,11,10)
#define	GET_GIGASPWR_RX_PMA_CTR_CDR_MODE(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,10)
#define	SET_GIGASPWR_RX_PMA_CTR_CDR_MODE(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,10)

#define	OFFSET_GIGASPWR_RX_PMA_CTR_LB_EN_RX                                  	15
#define	GIGASPWR_RX_PMA_CTR_LB_EN_RX(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,15,15)
#define	GET_GIGASPWR_RX_PMA_CTR_LB_EN_RX(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,15,15)
#define	SET_GIGASPWR_RX_PMA_CTR_LB_EN_RX(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,15,15)

#define	OFFSET_GIGASPWR_TX_IDLE_CTR_TX_COMMAND_0                             	0
#define	GIGASPWR_TX_IDLE_CTR_TX_COMMAND_0(a)                                 	GIGASPWR_REG_FIELDS_H_FIELD(a,7,0)
#define	GET_GIGASPWR_TX_IDLE_CTR_TX_COMMAND_0(a)                             	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,7,0)
#define	SET_GIGASPWR_TX_IDLE_CTR_TX_COMMAND_0(reg,f)                         	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,7,0)

#define	OFFSET_GIGASPWR_TX_IDLE_CTR_TX_COMMAND_1                             	8
#define	GIGASPWR_TX_IDLE_CTR_TX_COMMAND_1(a)                                 	GIGASPWR_REG_FIELDS_H_FIELD(a,15,8)
#define	GET_GIGASPWR_TX_IDLE_CTR_TX_COMMAND_1(a)                             	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,15,8)
#define	SET_GIGASPWR_TX_IDLE_CTR_TX_COMMAND_1(reg,f)                         	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,15,8)

#define	OFFSET_GIGASPWR_TX_IDLE_CTR_TX_COMMAND_2                             	16
#define	GIGASPWR_TX_IDLE_CTR_TX_COMMAND_2(a)                                 	GIGASPWR_REG_FIELDS_H_FIELD(a,23,16)
#define	GET_GIGASPWR_TX_IDLE_CTR_TX_COMMAND_2(a)                             	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,23,16)
#define	SET_GIGASPWR_TX_IDLE_CTR_TX_COMMAND_2(reg,f)                         	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,23,16)

#define	OFFSET_GIGASPWR_TX_IDLE_CTR_TX_COMMAND_3                             	24
#define	GIGASPWR_TX_IDLE_CTR_TX_COMMAND_3(a)                                 	GIGASPWR_REG_FIELDS_H_FIELD(a,31,24)
#define	GET_GIGASPWR_TX_IDLE_CTR_TX_COMMAND_3(a)                             	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,31,24)
#define	SET_GIGASPWR_TX_IDLE_CTR_TX_COMMAND_3(reg,f)                         	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,31,24)

#define	OFFSET_GIGASPWR_RX_BUF_STATE_RX_FIFO_LEVEL                           	0
#define	GIGASPWR_RX_BUF_STATE_RX_FIFO_LEVEL(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	GET_GIGASPWR_RX_BUF_STATE_RX_FIFO_LEVEL(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,6,0)
#define	SET_GIGASPWR_RX_BUF_STATE_RX_FIFO_LEVEL(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,6,0)

#define	OFFSET_GIGASPWR_RX_BUF_STATE_RX_FIFO_FULL                            	7
#define	GIGASPWR_RX_BUF_STATE_RX_FIFO_FULL(a)                                	GIGASPWR_REG_FIELDS_H_FIELD(a,7,7)
#define	GET_GIGASPWR_RX_BUF_STATE_RX_FIFO_FULL(a)                            	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,7,7)
#define	SET_GIGASPWR_RX_BUF_STATE_RX_FIFO_FULL(reg,f)                        	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,7,7)

#define	OFFSET_GIGASPWR_RX_BUF_STATE_RX_FIFO_EMPTY                           	8
#define	GIGASPWR_RX_BUF_STATE_RX_FIFO_EMPTY(a)                               	GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	GET_GIGASPWR_RX_BUF_STATE_RX_FIFO_EMPTY(a)                           	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	SET_GIGASPWR_RX_BUF_STATE_RX_FIFO_EMPTY(reg,f)                       	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,8,8)

#define	OFFSET_GIGASPWR_MODE_TEST                                            	0
#define	GIGASPWR_MODE_TEST(a)                                                	GIGASPWR_REG_FIELDS_H_FIELD(a,0,0)
#define	GET_GIGASPWR_MODE_TEST(a)                                            	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,0,0)
#define	SET_GIGASPWR_MODE_TEST(reg,f)                                        	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,0,0)

#define	OFFSET_GIGASPWR_MODE_CLR_RX                                          	1
#define	GIGASPWR_MODE_CLR_RX(a)                                              	GIGASPWR_REG_FIELDS_H_FIELD(a,1,1)
#define	GET_GIGASPWR_MODE_CLR_RX(a)                                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,1,1)
#define	SET_GIGASPWR_MODE_CLR_RX(reg,f)                                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,1,1)

#define	OFFSET_GIGASPWR_MODE_CLR_TX                                          	2
#define	GIGASPWR_MODE_CLR_TX(a)                                              	GIGASPWR_REG_FIELDS_H_FIELD(a,2,2)
#define	GET_GIGASPWR_MODE_CLR_TX(a)                                          	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,2,2)
#define	SET_GIGASPWR_MODE_CLR_TX(reg,f)                                      	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,2,2)

#define	OFFSET_GIGASPWR_MODE_RX_DMA_EN                                       	4
#define	GIGASPWR_MODE_RX_DMA_EN(a)                                           	GIGASPWR_REG_FIELDS_H_FIELD(a,4,4)
#define	GET_GIGASPWR_MODE_RX_DMA_EN(a)                                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,4,4)
#define	SET_GIGASPWR_MODE_RX_DMA_EN(reg,f)                                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,4,4)

#define	OFFSET_GIGASPWR_MODE_TX_DMA_EN                                       	5
#define	GIGASPWR_MODE_TX_DMA_EN(a)                                           	GIGASPWR_REG_FIELDS_H_FIELD(a,5,5)
#define	GET_GIGASPWR_MODE_TX_DMA_EN(a)                                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,5,5)
#define	SET_GIGASPWR_MODE_TX_DMA_EN(reg,f)                                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,5,5)

#define	OFFSET_GIGASPWR_MODE_RX_PWRDN                                        	8
#define	GIGASPWR_MODE_RX_PWRDN(a)                                            	GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	GET_GIGASPWR_MODE_RX_PWRDN(a)                                        	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	SET_GIGASPWR_MODE_RX_PWRDN(reg,f)                                    	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,8,8)

#define	OFFSET_GIGASPWR_MODE_TX_PWRDN                                        	9
#define	GIGASPWR_MODE_TX_PWRDN(a)                                            	GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	GET_GIGASPWR_MODE_TX_PWRDN(a)                                        	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	SET_GIGASPWR_MODE_TX_PWRDN(reg,f)                                    	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,9,9)

#define	OFFSET_GIGASPWR_MODE_RX_UNINIT                                       	10
#define	GIGASPWR_MODE_RX_UNINIT(a)                                           	GIGASPWR_REG_FIELDS_H_FIELD(a,10,10)
#define	GET_GIGASPWR_MODE_RX_UNINIT(a)                                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,10,10)
#define	SET_GIGASPWR_MODE_RX_UNINIT(reg,f)                                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,10,10)

#define	OFFSET_GIGASPWR_MODE_TX_UNINIT                                       	11
#define	GIGASPWR_MODE_TX_UNINIT(a)                                           	GIGASPWR_REG_FIELDS_H_FIELD(a,11,11)
#define	GET_GIGASPWR_MODE_TX_UNINIT(a)                                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,11)
#define	SET_GIGASPWR_MODE_TX_UNINIT(reg,f)                                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,11)

#define	OFFSET_GIGASPWR_MODE_RX_DATA_ACCEPT                                  	12
#define	GIGASPWR_MODE_RX_DATA_ACCEPT(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,12,12)
#define	GET_GIGASPWR_MODE_RX_DATA_ACCEPT(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,12,12)
#define	SET_GIGASPWR_MODE_RX_DATA_ACCEPT(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,12,12)

#define	OFFSET_GIGASPWR_MODE_RX_CMD_ACCEPT                                   	13
#define	GIGASPWR_MODE_RX_CMD_ACCEPT(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,13,13)
#define	GET_GIGASPWR_MODE_RX_CMD_ACCEPT(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,13,13)
#define	SET_GIGASPWR_MODE_RX_CMD_ACCEPT(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,13,13)

#define	OFFSET_GIGASPWR_MODE_EN_PMA_RX                                       	14
#define	GIGASPWR_MODE_EN_PMA_RX(a)                                           	GIGASPWR_REG_FIELDS_H_FIELD(a,14,14)
#define	GET_GIGASPWR_MODE_EN_PMA_RX(a)                                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,14,14)
#define	SET_GIGASPWR_MODE_EN_PMA_RX(reg,f)                                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,14,14)

#define	OFFSET_GIGASPWR_MODE_EN_PMA_TX                                       	15
#define	GIGASPWR_MODE_EN_PMA_TX(a)                                           	GIGASPWR_REG_FIELDS_H_FIELD(a,15,15)
#define	GET_GIGASPWR_MODE_EN_PMA_TX(a)                                       	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,15,15)
#define	SET_GIGASPWR_MODE_EN_PMA_TX(reg,f)                                   	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,15,15)

#define	OFFSET_GIGASPWR_MODE_CLR_RDC                                         	16
#define	GIGASPWR_MODE_CLR_RDC(a)                                             	GIGASPWR_REG_FIELDS_H_FIELD(a,16,16)
#define	GET_GIGASPWR_MODE_CLR_RDC(a)                                         	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,16,16)
#define	SET_GIGASPWR_MODE_CLR_RDC(reg,f)                                     	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,16,16)

#define	OFFSET_GIGASPWR_MODE_CLR_RCC                                         	17
#define	GIGASPWR_MODE_CLR_RCC(a)                                             	GIGASPWR_REG_FIELDS_H_FIELD(a,17,17)
#define	GET_GIGASPWR_MODE_CLR_RCC(a)                                         	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,17,17)
#define	SET_GIGASPWR_MODE_CLR_RCC(reg,f)                                     	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,17,17)

#define	OFFSET_GIGASPWR_MODE_CLR_REC                                         	18
#define	GIGASPWR_MODE_CLR_REC(a)                                             	GIGASPWR_REG_FIELDS_H_FIELD(a,18,18)
#define	GET_GIGASPWR_MODE_CLR_REC(a)                                         	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,18,18)
#define	SET_GIGASPWR_MODE_CLR_REC(reg,f)                                     	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,18,18)

#define	OFFSET_GIGASPWR_MODE_DECODER_WRTST                                   	19
#define	GIGASPWR_MODE_DECODER_WRTST(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,19,19)
#define	GET_GIGASPWR_MODE_DECODER_WRTST(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,19,19)
#define	SET_GIGASPWR_MODE_DECODER_WRTST(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,19,19)

#define	OFFSET_GIGASPWR_MODE_DECODER_TSTCD8                                  	20
#define	GIGASPWR_MODE_DECODER_TSTCD8(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,20,20)
#define	GET_GIGASPWR_MODE_DECODER_TSTCD8(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,20,20)
#define	SET_GIGASPWR_MODE_DECODER_TSTCD8(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,20,20)

#define	OFFSET_GIGASPWR_MODE_DECODER_RSTCD8                                  	21
#define	GIGASPWR_MODE_DECODER_RSTCD8(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,21,21)
#define	GET_GIGASPWR_MODE_DECODER_RSTCD8(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,21,21)
#define	SET_GIGASPWR_MODE_DECODER_RSTCD8(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,21,21)

#define	OFFSET_GIGASPWR_MODE_RX_10B_ACCEPT                                   	22
#define	GIGASPWR_MODE_RX_10B_ACCEPT(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,22,22)
#define	GET_GIGASPWR_MODE_RX_10B_ACCEPT(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,22,22)
#define	SET_GIGASPWR_MODE_RX_10B_ACCEPT(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,22,22)

#define	OFFSET_GIGASPWR_MODE_PMA_RXD_TO_REG                                  	23
#define	GIGASPWR_MODE_PMA_RXD_TO_REG(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,23,23)
#define	GET_GIGASPWR_MODE_PMA_RXD_TO_REG(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,23,23)
#define	SET_GIGASPWR_MODE_PMA_RXD_TO_REG(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,23,23)

#define	OFFSET_GIGASPWR_MODE_CNT_COMMA_ONLY                                  	24
#define	GIGASPWR_MODE_CNT_COMMA_ONLY(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,24,24)
#define	GET_GIGASPWR_MODE_CNT_COMMA_ONLY(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,24,24)
#define	SET_GIGASPWR_MODE_CNT_COMMA_ONLY(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,24,24)

#define	OFFSET_GIGASPWR_RX_STATE_LOCK                                        	0
#define	GIGASPWR_RX_STATE_LOCK(a)                                            	GIGASPWR_REG_FIELDS_H_FIELD(a,1,0)
#define	GET_GIGASPWR_RX_STATE_LOCK(a)                                        	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,1,0)
#define	SET_GIGASPWR_RX_STATE_LOCK(reg,f)                                    	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,1,0)

#define	OFFSET_GIGASPWR_RX_STATE_ALIGN_STATE                                 	4
#define	GIGASPWR_RX_STATE_ALIGN_STATE(a)                                     	GIGASPWR_REG_FIELDS_H_FIELD(a,7,4)
#define	GET_GIGASPWR_RX_STATE_ALIGN_STATE(a)                                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,7,4)
#define	SET_GIGASPWR_RX_STATE_ALIGN_STATE(reg,f)                             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,7,4)

#define	OFFSET_GIGASPWR_RX_STATE_COMMADET8                                   	8
#define	GIGASPWR_RX_STATE_COMMADET8(a)                                       	GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	GET_GIGASPWR_RX_STATE_COMMADET8(a)                                   	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,8,8)
#define	SET_GIGASPWR_RX_STATE_COMMADET8(reg,f)                               	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,8,8)

#define	OFFSET_GIGASPWR_RX_STATE_ALIGN_ERROR                                 	9
#define	GIGASPWR_RX_STATE_ALIGN_ERROR(a)                                     	GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	GET_GIGASPWR_RX_STATE_ALIGN_ERROR(a)                                 	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,9,9)
#define	SET_GIGASPWR_RX_STATE_ALIGN_ERROR(reg,f)                             	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,9,9)

#define	OFFSET_GIGASPWR_RX_STATE_ALIGN_ERROR_LATCHED                         	10
#define	GIGASPWR_RX_STATE_ALIGN_ERROR_LATCHED(a)                             	GIGASPWR_REG_FIELDS_H_FIELD(a,10,10)
#define	GET_GIGASPWR_RX_STATE_ALIGN_ERROR_LATCHED(a)                         	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,10,10)
#define	SET_GIGASPWR_RX_STATE_ALIGN_ERROR_LATCHED(reg,f)                     	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,10,10)

#define	OFFSET_GIGASPWR_RX_STATE_PMA_COMMA_DET                               	11
#define	GIGASPWR_RX_STATE_PMA_COMMA_DET(a)                                   	GIGASPWR_REG_FIELDS_H_FIELD(a,11,11)
#define	GET_GIGASPWR_RX_STATE_PMA_COMMA_DET(a)                               	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,11,11)
#define	SET_GIGASPWR_RX_STATE_PMA_COMMA_DET(reg,f)                           	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,11,11)

#define	OFFSET_GIGASPWR_RX_STATE_PMA_RXD10B                                  	16
#define	GIGASPWR_RX_STATE_PMA_RXD10B(a)                                      	GIGASPWR_REG_FIELDS_H_FIELD(a,25,16)
#define	GET_GIGASPWR_RX_STATE_PMA_RXD10B(a)                                  	GET_GIGASPWR_REG_FIELDS_H_FIELD(a,25,16)
#define	SET_GIGASPWR_RX_STATE_PMA_RXD10B(reg,f)                              	SET_GIGASPWR_REG_FIELDS_H_FIELD(reg,f,25,16)

#endif

