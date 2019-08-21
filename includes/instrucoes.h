#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "registradores.h"

extern unsigned int imediato;




int add(int regDestino,int regOrigem1, int regOrigem2); //adicionado a ula
unsigned int addi(int regDestino,int regOrigem1, int imediato);
unsigned int And(int regDestino,int regOrigem1, int regOrigem2); //adicionado a ula
unsigned int andi(int regDestino,int regOrigem1, int imediato);
int b(int PC, int offset); //adicionado a OPU
int beq(int regOrigem1,int regOrigem2,int PC, int offset); //adicionado a ula
int beql(int regOrigem1,int regOrigem2,int PC, int offset); //adicionado a OPU
int bgez(int regOrigem1, int PC, int offset); //adicionado a OPU
int bgtz(int regOrigem1, int PC, int offset); //adicionado a OPU
int blez(int regOrigem1, int PC, int offset); //adicionado a OPU
int bltz(int regOrigem1, int PC, int offset); //adicionado a OPU
int bne(int regOrigem1,int regOrigem2,int PC, int offset); //adicionado a OPU
int DivHI(int regOrigem1, int regOrigem2, int HI, int LO); //adicionado a mdu
int DivLO(int regOrigem1, int regOrigem2,int HI, int LO);
int j(int PC, int offset); //adicionado a OPU
int jr(int PC, int regOrigem1); //adicionado a OPU
unsigned int lui(int regDestino, int imediato); //revisar | adicionado a OPU
int madd(int regOrigem1, int regOrigem2, int regAcumulador); //adicionado a mdu
int mfhi(int HI,int regOrigem1); //adicionado a mdu
int mflo(int LO, int regOrigem1); //adicionado a mdu
int movn(int regDestino,int regOrigem1, int regOrigem2); //adicionado a OPU
int movz(int regDestino,int regOrigem1, int regOrigem2); //adicionado a OPU
int msub(int regOrigem1, int regOrigem2, int regAcumulador); //adicionado a mdu
int mthi(int regOrigem1, int HI); //adicionado a mdu
int mtlo(int regOrigem1, int LO); //adicionado a mdu
int mul(int regDestino,int regOrigem1, int regOrigem2); //adicionado a mdu
int mult(int regOrigem1, int regOrigem2, int regAcumulador); //adicionado a mdu
void nop();
int nor(int regDestino,int regOrigem1, int regOrigem2);
int Or(int regDestino,int regOrigem1, int regOrigem2); //adicionado a ula
int Ori(int regDestino,int regOrigem1, int imediato);
int sub(int regDestino,int regOrigem1, int regOrigem2); //adicionado a ula
int Xor(int regDestino,int regOrigem1, int regOrigem2); //adicionado a ula
int Xori(int regDestino,int regOrigem1, int imediato);


#endif