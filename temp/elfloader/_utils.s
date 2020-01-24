      .set      noreorder
      .set      noat
      .text

########################################################################
# wmemset:  word memory set - sets A2 32-bit words of buffer at        #
#           address A0 with the 32-bit value passed by A1.             #
########################################################################
# intput:                                                              #
# a0 - address where to copy                                           #
# a1 - address of buffer to copy                                       #
# a2 - number of bytes to copy                                  #
########################################################################
      .globl    wmemset
      .ent      wmemset
wmemset:

    move $24,$4
    move $25,$5
    move $26,$6
    beqz $6,4f
    nop

    srl $5, $5, 2
    sll $5, $5, 2

    srl $4, $4, 2
    sll $4, $4, 2

    srl $6, $6, 2
    addiu $6, $6, 1

1:  sw    $5,0x0($4)
    addiu $6,-1
    addiu $4,4
    bnez  $6,1b
    nop

4:  move $4,$24
    move $5,$25
    move $6,$26

  jr $31
  nop

 .end wmemset


########################################################################
# wmemcpy:  word memory copy - copies a buffer of A2 32-bit words at   #
#           address A1 to address A0.                                  #
########################################################################
# intput:                                                              #
# a0 - address where to copy                                           #
# a1 - address of buffer to copy                                       #
# a2 - number of bytes to copy                                  #
########################################################################
      .globl    wmemcpy
      .ent      wmemcpy
wmemcpy:
    beqz $6,3f
    nop
    move $24,$4
    move $25,$5
    move $26,$6


    srl $5, $5, 2
    sll $5, $5, 2

    srl $4, $4, 2
    sll $4, $4, 2

    srl $6, $6, 2
    addiu $6, $6, 1

1:  lw $2,0($5)
    nop
    addiu $5,4
    addiu $6,-1
    sw $2,0($4)
    addiu $4,4
    bnez $6,1b
    nop

#    move $4,$24
#    move $5,$25
#    move $6,$26

#    srl $5, $5, 2
#    sll $5, $5, 2

#    srl $4, $4, 2
#    sll $4, $4, 2

#    srl $6, $6, 2
#    addiu $6, $6, 1

#2:  lw $1,0($4)
#    nop
#    lw $2,0($5)
#    nop
#    addiu $6,-1
#    bne $1,$2,3f
#    nop
#    addiu $4,4
#    addiu $5,4
#    bnez $6,2b
#    nop

3:  jr $31
    nop

4:  nop
    nop
    nop

      .end wmemcpy

