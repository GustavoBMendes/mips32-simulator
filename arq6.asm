lui $t0, 1
lui $t1, 3
lui $t2, 3
loop:
sub $t1, $t1, $t0
mul $t2, $t2, $t1
bgtz $t1, -12