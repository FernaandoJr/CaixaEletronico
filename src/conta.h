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

void CadastrarConta(struct Conta *p_conta);
void LerDados(struct Conta *p_conta);
void ImprimirDados(struct Conta *p_conta);
void ListarOpcoes();
void RegistrarArquivo(struct Conta *p_conta, char arquivoDados);


#endif //CONTA_H
