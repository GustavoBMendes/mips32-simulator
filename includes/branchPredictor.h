#ifndef PREDICTOR_H
#define PREDICTOR_H

typedef struct numerosPrevisao;

struct numerosPrevisao{
    int acertos;
    int erros;
};

struct numerosPrevisao previsao();
bool isBranch(char* instrucao);
bool prediction(char *instrucao,char* reg1, char* reg2);


#endif