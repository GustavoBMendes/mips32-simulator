#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "registradores.h"
//Falta definir os registradores que iriam entrar nas operações porém os desconheço
//Acredito que com certeza não serão do tipo void mas isso vamos ver ainda, por enquanto meti um void
void add(int regDestino,int regOrigem1, int regOrigem2);
void addi();
void And(int regDestino,int regOrigem1, int regOrigem2);
void andi();
void b();
void beq();
void beql();
void bgez();
void bgtz();
void blez();
void bltz();
void bne();
void div(int regOrigem1, int regOrigem2);
void j();
void jr();
void lui();
void madd(int regOrigem1, int regOrigem2);
void mfhi();
void mflo();
void movn(int regDestino,int regOrigem1, int regOrigem2);
void movz(int regDestino,int regOrigem1, int regOrigem2);
void msub(int regOrigem1, int regOrigem2);
void mthi();
void mtlo();
void mul(int regDestino,int regOrigem1, int regOrigem2);
void mult(int regOrigem1, int regOrigem2);
void nop();
void nor(int regDestino,int regOrigem1, int regOrigem2);
void Or(int regDestino,int regOrigem1, int regOrigem2);
void ori();
void sub(int regDestino,int regOrigem1, int regOrigem2);
void Xor(int regDestino,int regOrigem1, int regOrigem2);
void xori();


#endif