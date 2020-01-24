################################################################################
## Загрузчик ELF-файлов.
##
## Программа читает ELF-заголовок файла, находящегося в памяти
## по адресу ElfObjectPtr, и копирует секции ELF-объекта по прописанным в
## заголовке адресам.
## При работе использует стек (указатель StackTopPtr).
## Необходимо, чтобы область стека не перекрывалась секциями программы
##
## При инициализации MPORT настраивается на SDRAM, подключенную к nCS[0]
## Выводу соответствует диапазон физических адресов 0x0000_0000 - 0x04FF_FFFF
## Такая конфигурация соответствует отладочным платам MC-24RT3EM, MC-24EM3U, MC-24EM
################################################################################


## All Constants ##

## Значения в ELF-заголовке
ELF_MAGIC = 0x464c457f

ET_NONE   = 0
ET_REL	  = 1
ET_EXEC   = 2
ET_DYN    = 3
ET_CORE   = 4
ET_LOPROC = 0xff00
ET_HIPROC = 0xffff

EM_NONE	 =	0
EM_M32	 =	1
EM_SPARC =	2
EM_386	 =	3
EM_68K	 =	4
EM_88K	 =	5
EM_860	 =	7
EM_MIPS  =	8

EV_NONE	   = 0
EV_CURRENT = 1

ELFMAG0	= 0x7f
ELFMAG1	= 'E'
ELFMAG2	= 'L'
ELFMAG3	= 'F'

ELFDATANONE = 0
ELFDATA2LSB = 1
ELFDATA2MSB	= 2

PT_LOAD = 1

SHN_UNDEF	  = 0
SHN_LORESERVE = 0xff00
SHN_LOPROC	  = 0xff00	/* ??? wrong ELF spec ??? */
SHN_HIPROC	  = 0xff1f
SHN_ABS		  = 0xfff1
SHN_COMMON	  = 0xfff2
SHN_HIRESERVE = 0xffff

SHT_NULL	 = 0
SHT_PROGBITS = 1
SHT_SYMTAB	 = 2
SHT_STRTAB	 = 3
SHT_RELA	 = 4
SHT_HASH	 = 5
SHT_NOTE	 = 7
SHT_NOBITS	 = 8
SHT_REL		 = 9
SHT_SHLIB	 = 10
SHT_DYNSYM	 = 11
SHT_LOPROC	 = 0x70000000
SHT_HIPROC	 = 0x7fffffff
SHT_LOUSER	 = 0x80000000
SHT_HIUSER	 = 0xffffffff

SHF_WRITE	  = 0x1
SHF_ALLOC	  = 0x2
SHF_EXECINSTR =	0x4
SHF_MASKPROC  =	0xf0000000

STB_LOCAL  = 0
STB_GLOBAL = 1
STB_WEAK   = 2
STB_LOPROC = 13
STB_HIPROC = 15

STT_NOTYPE  = 0
STT_OBJECT  = 1
STT_FUNC    = 2
STT_SECTION = 3
STT_FILE    = 4
STT_LOPROC  = 13
STT_HIPROC  = 15

/* Регистры MPORT */
CSCON0      =0x1000
CSCON1      =0x1004
CSCON2      =0x1008
CSCON3      =0x100C
CSCON4      =0x1010
SDRCON      =0x1014
SDRTMR      =0x1018
SDRCSR      =0x101C
/* Системные регистры */
CR_PLL0      =0x4000
CR_PLL1      =0x407c
CLK_EN       =0x4004

/* Указатель стека */
StackTopPtr  = 0xb8002000
/* Адрес ELF-объекта */
 ElfObjectPtr = 0xbfc00800  /*адрес начала прошивки в ПЗУ в адресном пространстве процессора!!! для физики - пересчитывать, наша флеш видит только 0х00800 */
#ElfObjectPtr = 0xbc000000

## some macroses ##

#ELF32_ST_BIND(info)		((info) >> 4)
.macro ELF32_ST_BIND info
        move $2,\info
        srl  $2,4
        nop
.endm
#ELF32_ST_TYPE(info)		((info) & 0xf)
.macro ELF32_ST_TYPE info
        move $2,\info
        andi $2,0xf
        nop
.endm
#ELF32_ST_INFO(bind, type)	(((bind) << 4) +((type) & 0xf))
.macro ELF32_ST_INFO bind, tp
        move $2,\bind
        sll  $2,4
        move $3,\tp
        andi $3,0xf
        add  $2,$3
.endm

.macro SEND_SYMBOL symb
        lw $11, \symb
        sw $11,THR($30)
        li $8,0x60
        100:
            lw $11,LSR($30)
            andi $11,0x60
        bne $11,$8,100b
        nop
.endm

/* Режим отладки. Если DEBUG=1, в UART выводятся отладочные сообщения. */
/* DEBUG=1 */

 .text
 .set noreorder

.global _start

_start:
/* Инициализация тактовой частоты процессора*/
      li $30,0xB82F0000
      li $5, 0x8e90
      sw $5, CR_PLL0($30)
      li $5, 0x0000    
      sw $5, CR_PLL1($30)
	  li $5, 0xFFFFFFFF
      sw $5, CLK_EN ($30)
    
## cache enable
#    mfc0 $k1, $16        #enable program cache
#    li $k0, 0xfffffff8
#    and $k1, $k1, $k0
#    mtc0 $k1, $16


    li  $29,StackTopPtr    #set stack
    li  $5,ElfObjectPtr    #set elf.obj pointer
    nop

##############################################
# $5(a1) - input param.  Elf-object pointer  #
# $4(a0) - output param  Entry point.        #
##############################################
loadelf:
    move $30,$31
    beqz $5,exit
    nop
## check ehp->e_magic ##
    lw  $4,0x00($5)
    bne $4,ELF_MAGIC, exit
    nop
## check ehp->e_type ##
    lh  $4,0x10($5)
    bne $4,ET_EXEC, exit
    nop
## check ehp->e_machine  ##
    lh  $4,0x12($5)
    bne $4,EM_MIPS, exit
    nop
## check ehp->e_ehsize ##
    lh  $4,0x28($5)
    bne $4,52, exit
    nop
## check ehp->e_phentsize ##
    lh  $4,0x2a($5)
    bne $4,32, exit
    nop
## set ephp = (ehp + ehp->e_phoff)  ##
    lw  $4,0x1c($5)
    add $21,$4,$5                               # $21 <- ephp
## set eshp = (ehp + ehp->e_shoff)  ##
    lw  $4,0x20($5)
    add $20,$4,$5                               # $20 <- eshp


    #GET_FROM_STRUCT elf_header,e_shnum,2
    lh    $12,0x30($5)
    move  $8,$20      # $8 <- eshp
5:
    lw    $2,0xc($8)  # $2 <- eshp[i].sh_addr
    beqz  $2,7f       # if eshp[i].sh_addr == 0 end
    nop
    lw    $2,0x4($8)                  # $2 <- eshp[i].sh_type
    bne   $2,SHT_NOBITS,copy_section  # if eshp[i].sh_type != SHT_NOBITS copy_section
    nop

    lw    $4,0xc($8)  # a0 <- eshp[i].sh_addr
    move  $5,$0       # a1 <- 0
    lw    $6,0x14($8) # a2 <- eshp[i].sh_size
    jal   wmemset
    nop

    li    $5,ElfObjectPtr
    b     7f
    nop

copy_section:
    lw    $4,0xc($8)  # a0 <- eshp[i].sh_addr
    lw    $2,0x10($8)
    add   $5,$2       # a1 <- ehp + eshp[i].sh_offset
    lw    $6,0x14($8) # a2 <- eshp[i].sh_size
    #srl   $6,2
    jal   wmemcpy
    nop
    li    $5,ElfObjectPtr

7:  addiu $12,-1
    addiu $8,40       #eshp <- eshp + sizoef(eshp)
    bnez  $12,5b
    nop

exit:
/* В регистр $4 мы кладем адрес точки входа */
    lw  $4,0x18($5)
    nop
/* а здесь - передаем управление, то есть делаем переход на точку входа */
    jr $4
    nop



