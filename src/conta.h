#define MAX 100

#ifndef CONTA_H
#define CONTA_H

typedef struct Conta{
    int numeroConta;  // Número da conta
    char nomeTitular[100];  // Nome do titular da conta
    double saldo;  // Saldo atual da conta
};

// typedef Conta *p_conta;

//extern p_conta v[MAX];

void Teste();
void LerDados(struct Conta *p_conta);
void ImprimirDados(struct Conta *p_conta);


#endif //CONTA_H
