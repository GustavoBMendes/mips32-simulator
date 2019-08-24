add $t0, $zero, $zero
addi $t0, $zero, 1
and $t1, $t0, $zero
andi $t1, $t0, 1
b 0
beq $t0, $t1, 0
beql $t0, $t1, 0
bgez $t0, 0
bgtz $t0, 0
blez $t0, 0
bltz $t0, 0
bne $t0, $t1, 0
div $t2, $t1, $t0
j 0
jr $zero
lui $t3, 10
madd $t4, $t3, $t2
mfhi $t5
mflo $t6
mthi $t3
mtlo $t4
movn $t5, $t1, $zero
movz $t5, $t1, $t2
msub $t7, $t5, $t6
mul $t8, $t0, $t7
mult $t9, $t0, $t1
nor $s0, $t9, $t8
or $s1, $t0, $zero
ori $s2, $t1, 10
sub $s3, $s2, $s1
xor $s4, $s3, $zero
xori $s5, $s4, 5