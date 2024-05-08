#define MAX 100

#ifndef CONTA_H
#define CONTA_H

typedef struct {
    int numeroConta;  // Número da conta
    char nomeTitular[100];  // Nome do titular da conta
    double saldo;  // Saldo atual da conta
} Conta;

typedef Conta *p_conta;

extern p_conta v[MAX];

void Teste();

#endif //CONTA_H
