#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "registradores.h"

extern unsigned int imediato;


//Acredito que com certeza não serão do tipo void mas isso vamos ver ainda, por enquanto meti um void
void add(int regDestino,int regOrigem1, int regOrigem2);
void addi(int regDestino,int regOrigem1, int imediato);
void And(int regDestino,int regOrigem1, int regOrigem2);
void andi(int regDestino,int regOrigem1, int imediato);
void b(int PC, int offset);
void beq(int regOrigem1,int regOrigem2,int PC, int offset);
void beql(int regOrigem1,int regOrigem2,int PC, int offset); //else feito
void bgez(int regOrigem1, int PC, int offset);
void bgtz(int regOrigem1, int PC, int offset);
void blez(int regOrigem1, int PC, int offset);
void bltz(int regOrigem1, int PC, int offset);
void bne(int regOrigem1,int regOrigem2,int PC, int offset);
void div(int regOrigem1, int regOrigem2, int HI, int LO);
void j(int PC, int offset); //feito
void jr(int PC, int regOrigem1); // feito
void lui(int regDestino, int imediato);
void madd(int regOrigem1, int regOrigem2, int regAcumulador);
void mfhi(int regOrigem1, int HI);
void mflo(int regOrigem1, int LO);
void movn(int regDestino,int regOrigem1, int regOrigem2);
void movz(int regDestino,int regOrigem1, int regOrigem2);
void msub(int regOrigem1, int regOrigem2, int regAcumulador);
void mthi(int regOrigem1, int HI);
void mtlo(int regOrigem1, int LO);
void mul(int regDestino,int regOrigem1, int regOrigem2);
void mult(int regOrigem1, int regOrigem2, int regAcumulador);
void nop();
void nor(int regDestino,int regOrigem1, int regOrigem2);
void Or(int regDestino,int regOrigem1, int regOrigem2);
void ori(int regDestino,int regOrigem1, int imediato);
void sub(int regDestino,int regOrigem1, int regOrigem2);
void Xor(int regDestino,int regOrigem1, int regOrigem2);
void xori(int regDestino,int regOrigem1, int imediato);


#endif