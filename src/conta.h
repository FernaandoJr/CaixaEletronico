#define MAX 100

#ifndef CONTA_H
#define CONTA_H

typedef struct Conta{
    int numeroConta;
    char nomeTitular[100];
    char email[50];
    char telefone[13];
    char endereco[100];
    unsigned int CEP;
    double saldo;
    double credito_tel;
    double limite_saque;
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
void SincronizarDados(struct Conta *p_conta);
void Sacar(struct Conta *p_conta);
void RegistrarRelatorio(struct Conta *p_conta, double *val_antigo, double *val_atual);
void ImprimirRelatorio();
void ExcluirRelatorio();
void RegistarConsulta();
void LimparRelatorio();
void Linha();
void RecargaCelular(struct Conta *p_conta);
void EditarUsuario(struct Conta *p_conta);
void SimulacaoEmprestimo();
void limparBuffer();
void capturarEntrada(char *buffer, int tamanho);
void LerFloat(const char *prompt, double *numero);
void LerUnsignedInt(const char *prompt, unsigned int *numero);
void LerInt(const char *prompt,int *numero);
void DadosSucesso();

#endif //CONTA_H
