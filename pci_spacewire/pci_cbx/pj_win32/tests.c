/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "tests.h"

#define u32 unsigned int 
#define u16 unsigned short

// ����� ������� � 32-��������� ������
#define ARRAY_LEN 8
unsigned int OutputArray [ARRAY_LEN] __attribute__ ((aligned (8))) = {0,};
unsigned int InputArray1 [ARRAY_LEN] __attribute__ ((aligned (8))) = {0,};
unsigned int InputArray2 [ARRAY_LEN] __attribute__ ((aligned (8))) = {0,};


int RAM_memtest_random(void)
{
struct timeval start, end;
long elapsed_ms, seconds, useconds;
int rand_val = 0;
int flags = 1;
int i=0;

printf("RAM_MEMTEST STARTED\n");
gettimeofday(&start, NULL);


for (i=MCB02_RAM_BASE;i<MCB02_RAM_BASE+ MCB02_RAM_LEN;i=i+4)
{
    rand_val = rand();
    mcb_write(i,rand_val);
    if(mcb_read_reg(i)!= rand_val)
    {
        flags =0;
        printf("ERORR RAM_MEMTEST STARTED\n");
        return 0;
    }
    //printf("i= %x \n",i);
}
    gettimeofday(&end, NULL);
	seconds  = end.tv_sec  - start.tv_sec;
	useconds = end.tv_usec - start.tv_usec;
	elapsed_ms = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    printf("RANDOM memtest finished, %ld ms elapsed, speed rate %.02f kbytes/sec\n",
           elapsed_ms, (float)i / elapsed_ms);
    printf("--------------------\r\n");
    return 1;
}

int swic_connection(unsigned int first_port, unsigned int second_port,unsigned int speed)
{
    swic_init(first_port);
    swic_init(second_port);
    usleep(1);
    if (swic_is_connected(first_port)&& swic_is_connected(second_port))
      printf("Base speed connection OK \n");
    else{ 
       printf("Base speed connection FAILED \n");
       return 0; 
        }
    
    if (swic_set_tx_speed(first_port,speed) && swic_set_tx_speed(second_port,speed)){
        printf("After setup speed connection OK \n");
        swic_get_rx_speed(first_port);
        swic_get_rx_speed(second_port);
        return 1;
    }
    else{
        printf("After setup speed connection FAILED \n");
        return 0;
        }
}

void array_init (u32 *a,u32 n,u16 test)
{
	unsigned int i=0;
	unsigned int z=0;
	
	for (i=0;i<n;i++) 
	{
		z=((test&0xffff)<<16)|i;
		a[i]=z;
	}
}

void clear (u32 adr,u32 n)
{
	u32 i=0;
	for (i=0;i<n;i++) mcb_write(adr+i*4,0x00000000);
}

int sw_send (u32 n,u32 port,u32 *M)
{
u32 error=0;	
	error = get_plase (n*4,port, M);//��������� ��������� ������������ ��� ��������
	if (error <0 )	{ printf("Get plase fail \n");}

	error = swic_send_packet (port,0); //���� 1, ���������� 0 - ��������
	if (error!=1) 	{ printf("Send fail \n");}
	
	return 1;
}

void init_LANE (u32 data)
{
	int error=0;
	int i=0;
	u32 z =0;
	u32 z1=0;
	u32 z2=0;
	u32 flag=0;
	extern manager_main manager; //��� �������� ������ ������������ RX � TX
	u32 addr = 0;
	u32 col=16;
	
	array_init (&OutputArray,col,data);//��������� ������������ ������ ��������� �������
	
	/*
	for (i=0;i<col;i++){	printf ("%x\n",OutputArray[i]);	}
	*/

	init_manager();
	
	manager_swic_reset(1);
	manager_swic_reset(2);
	
//---------------------------������ ������ �� ������------------------------------------------------------
	addr = manager.port[1].rx_mcb_addr;  
	addr = addr + MAX_RX_DESCRIPTORS_IN_MEMORY*4;
	
    clear(addr,col+1);//�������� ������ � ������� ����� ������ col - ����� 32 ������ ����
	clear(manager.descriptor[1].data_addres_in_mcb_memory,col+1);//�������� ������ � ������� �������� ������
	
	addr = manager.port[2].rx_mcb_addr;  
	addr = addr + MAX_RX_DESCRIPTORS_IN_MEMORY*4;
	
    clear(addr,col+1);//�������� ������ � ������� ����� ������
	clear(manager.descriptor[2].data_addres_in_mcb_memory,col+1);//�������� ������ � ������� �������� ������
//---------------------------------------------------------------------------------------------------------
//-----�������������� SPACEWIRE----------------------
	swic_init(1);
	swic_init(2);
	
	while ((((z1>>5)&0x7)!=5)&&(((z2>>5)&0x7)!=5)) //��� ��������� ����� �� ����� ������
	{
		if (flag==0) printf("\nwait LINK 1,2\n");
		flag=1;
		
		z1=mcb_read_reg(SWIC_STATUS(1)); // ������� �������� ������� ���������� ������������ ���������� 
		z2=mcb_read_reg(SWIC_STATUS(2)); // ������� �������� ������� ���������� ������������ ����������  		
	};
	
	swic_set_speed(1,200);
	swic_set_speed(2,200);
	
	z=mcb_read_reg(SWIC_STATUS(1)); //������� ������ ����������  	
	printf ("STATUS[7:5]:%x\n",(z>>5)&0x7);
	
	z=mcb_read_reg(SWIC_STATUS(2)); //������� ������ ����������  	
	printf ("STATUS[7:5]:%x\n",(z>>5)&0x7);

	//-----------RX stage------------
	init_rx_dma (1);
	init_rx_dma (2);
//	sleep(1);//��� 
	//------------TX stage------------
	sw_send (col,1,OutputArray);//col - ���������� 32 ������ ����
	sw_send (col,2,OutputArray);

//	sleep(1);//��� 
	
//--------------------------------------------------------------------------	
//������� ����� ������������ � �������� ������
	addr = manager.port[1].rx_mcb_addr;  
	addr = addr + MAX_RX_DESCRIPTORS_IN_MEMORY*4;	

	printf ("\n������������ ������ ���� 1\n");
	dump_from_mcb(manager.descriptor[1].data_addres_in_mcb_memory,col+1);
	printf ("\n��������     ������ ���� 1\n");
	dump_from_mcb(addr,col+8);
	
	addr = manager.port[2].rx_mcb_addr;  
	addr = addr + MAX_RX_DESCRIPTORS_IN_MEMORY*4;
	
	printf ("\n������������ ������ ���� 2\n");
	dump_from_mcb(manager.descriptor[2].data_addres_in_mcb_memory,col+1);
	printf ("\n��������     ������ ���� 2\n");
	dump_from_mcb(addr,col+8);
	
}

