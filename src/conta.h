#define MAX 100

#ifndef CONTA_H
#define CONTA_H

typedef struct Conta{
    int numeroConta;
    char nomeTitular[100];
    char email[50];
    int telefone;
    char endereco[100];
    double saldo;
} item;

// typedef Conta *p_conta;

//extern p_conta v[MAX];


void LerTexto(char *buffer, int tamanho);
void CadastrarConta(struct Conta *p_conta);
void LerDados(struct Conta *p_conta);
void ImprimirDados(struct Conta *p_conta);
void ListarOpcoes();
void RegistrarArquivo(struct Conta *p_conta);
void ExcluirConta(struct Conta *p_conta);
void Depositar(struct Conta *p_conta);
void AtualizarArquivo(struct Conta *p_conta);
void Sacar(struct Conta *p_conta);
void RegistrarRelatorio(struct Conta *p_conta, double *val_antigo, double *val_atual);
void ImprimirRelatorio();
void ExcluirRelatorio();
void RegistartConsulta();
void LimparRelatorio();

#endif //CONTA_H
