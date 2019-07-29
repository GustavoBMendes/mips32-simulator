#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "registradores.h"

extern unsigned int imediato;




int add(int regDestino,int regOrigem1, int regOrigem2); //adicionado a ula
int addi(int regDestino,int regOrigem1, int imediato);
int And(int regDestino,int regOrigem1, int regOrigem2); //adicionado a ula
void andi(int regDestino,int regOrigem1, int imediato);
void b(int PC, int offset); //adicionado a OPU
void beq(int regOrigem1,int regOrigem2,int PC, int offset); //adicionado a ula
void beql(int regOrigem1,int regOrigem2,int PC, int offset); //adicionado a OPU
void bgez(int regOrigem1, int PC, int offset); //adicionado a OPU
void bgtz(int regOrigem1, int PC, int offset); //adicionado a OPU
void blez(int regOrigem1, int PC, int offset); //adicionado a OPU
void bltz(int regOrigem1, int PC, int offset); //adicionado a OPU
void bne(int regOrigem1,int regOrigem2,int PC, int offset); //adicionado a OPU
int DivHI(int regOrigem1, int regOrigem2, int HI, int LO); //adicionado a mdu
int DivLO(int regOrigem1, int regOrigem2,int HI, int LO);
void j(int PC, int offset); //adicionado a OPU
void jr(int PC, int regOrigem1); //adicionado a OPU
void lui(int regDestino, int imediato); //revisar | adicionado a OPU
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
void nor(int regDestino,int regOrigem1, int regOrigem2);
int Or(int regDestino,int regOrigem1, int regOrigem2); //adicionado a ula
void Ori(int regDestino,int regOrigem1, int imediato);
int sub(int regDestino,int regOrigem1, int regOrigem2); //adicionado a ula
int Xor(int regDestino,int regOrigem1, int regOrigem2); //adicionado a ula
void Xori(int regDestino,int regOrigem1, int imediato);


#endif