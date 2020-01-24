TEST_NAME = tfc11_swic

QUIET:=

ifndef VERBOSE
	QUIET:=@
endif

BINDIR=C:/MCStudio_3M/Tools4x/bin
CC		= $(addsuffix $(suffix), $(BINDIR)/mipsel-elf32-gcc)
LD		= $(addsuffix $(suffix), $(BINDIR)/mipsel-elf32-ld)
DIS		= $(addsuffix $(suffix), $(BINDIR)/mipsel-elf32-objdump)
CFLAGS = -mips32 -EL -G0 -g -fno-delayed-branch -Wa,-O0 -Wa,--mc24r2
LFLAGS = -g -EL -G0 -fno-delayed-branch -Wa,-O0 -Wa,--mc24r2

C_SRC = \
    main.c \
	risc_runtime/swic.c \
	risc_runtime/system.c \
    risc_runtime/risc_interrupt.c

S_SRC = \
    risc_interrupt_handler.s

C_OBJ	:= $(C_SRC:%.c=%.o)
S_OBJ	:= $(S_SRC:%.s=%.o)

all: clean sdram cram

clean:
	rm -rf *.o risc_runtime/*.o *.dis *.bin
	
<<<<<<< .mine
sdram:$(C_OBJ)
=======
sdram:$(C_OBJ) $(S_OBJ)
	$(CC) $(LFLAGS) -T $(TEST_NAME).xl -Ttext=0x80001000 $(C_OBJ) $(S_OBJ) -o $(TEST_NAME)_ext.o
>>>>>>> .r1347
	
<<<<<<< .mine
	$(CC) $(LFLAGS) -T tfc11_swic.xl -Ttext=0x80001000 $(C_OBJ) risc_interrupt_handler.o -o $(TEST_NAME)_ext.o
	
cram:$(C_OBJ)

	$(CC) $(LFLAGS) -T tfc11_swic.xl $(C_OBJ) risc_interrupt_handler.o -o tfc11_swic.o
=======
cram:$(C_OBJ) $(S_OBJ)
	$(CC) $(LFLAGS) -T $(TEST_NAME).xl $(C_OBJ) $(S_OBJ) -o $(TEST_NAME).o
>>>>>>> .r1347
	
%.o:%.c
	$(CC) $(CFLAGS) -c -I. -o $@ $<
	
%.o:%.s
	$(CC) $(CFLAGS) -c -o $@ $<