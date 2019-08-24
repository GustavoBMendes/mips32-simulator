lui $t0, 0
lui $t1, 0
lui $t2, 5
lui $t3, 2
loop:
add $t1, $t1, $t2
addi $t0, $t0, 1
bne $t0, $t3, -12