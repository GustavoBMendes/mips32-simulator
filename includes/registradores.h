#ifndef REGISTERS_H
#define REGISTERS_H

//Registradores de uso geral 
extern unsigned int reg[32];

#define $zero reg[0]
#define $at reg[1]
#define $v0 reg[2]
#define $v1 reg[3]
#define $a0 reg[4]
#define $a1 reg[5]
#define $a2 reg[6]
#define $a3 reg[7]
#define $t0 reg[8]
#define $t1 reg[9]
#define $t2 reg[10]
#define $t3 reg[11]
#define $t4 reg[12]
#define $t5 reg[13]
#define $t6 reg[14]
#define $t7 reg[15]
#define $s0 reg[16]
#define $s1 reg[17]
#define $s2 reg[18]
#define $s3 reg[19]
#define $s4 reg[20]
#define $s5 reg[21]
#define $s6 reg[22]
#define $s7 reg[23]
#define $t8 reg[24]
#define $t9 reg[25]
#define $k0 reg[26]
#define $k1 reg[27]
#define $gp reg[28]
#define $sp reg[29]
#define $fp reg[30]
#define $ra reg[31]

//Registradores especiais
extern unsigned int HI, LO, PC; 

void printRegistradores();

#endif