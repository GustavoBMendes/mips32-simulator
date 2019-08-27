lui $t0, 1
bltz $t0, 56
lui $t3, 3
sub $t1, $t0, $t3
beq $t1, $zero, 48
lui $t2, 1
beq $t0, $t2, 20
lui $t2, 2
beq $t0, $t2, 20
is0:
addi $t0, $zero, 0
j 32
is1:
j 24
is2: 
addi $t0, $zero, 1
j 12
def: 
addi $t0, $zero, -1
j 0
done: