#ifndef REGISTERS_H
#define REGISTERS_H

//Mudar para o tipo adequado para o vetor
//Registradores de uso geral 
extern unsigned int reg[32];

#define ZERO reg[0]
#define AT reg[1]
#define V0 reg[2]
#define V1 reg[3]
#define A0 reg[4]
#define A1 reg[5]
#define A2 reg[6]
#define A3 reg[7]
#define T0 reg[8]
#define T1 reg[9]
#define T2 reg[10]
#define T3 reg[11]
#define T4 reg[12]
#define T5 reg[13]
#define T6 reg[14]
#define T7 reg[15]
#define S0 reg[16]
#define S1 reg[17]
#define S2 reg[18]
#define S3 reg[19]
#define S4 reg[20]
#define S5 reg[21]
#define S6 reg[22]
#define S7 reg[23]
#define T8 reg[24]
#define T9 reg[25]
#define K0 reg[26]
#define K1 reg[27]
#define GP reg[28]
#define SP reg[29]
#define FP reg[30]
#define RA reg[31]

//Registradores especiais
extern unsigned int HI, LO, PC; 

#endif