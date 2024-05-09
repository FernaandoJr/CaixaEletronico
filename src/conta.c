#include "Conta.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void CadastrarConta(struct Conta *p_conta){
    // Pegar os dados do usuário e colocar dentro da struct
    printf("Cadastrando novo usuario...\n\n");
    printf("Digite o numero da sua conta:\n");
    scanf("%d", &p_conta->numeroConta);
    fflush(stdin);
    printf("Digite o nome do titular da conta:\n");
    gets(p_conta->nomeTitular); 
    printf("Digite o saldo:\n");
    scanf("%lf", &p_conta->saldo);
}

void ImprimirDados(struct Conta *p_conta){
    printf("Numero da conta: %d\n", p_conta->numeroConta);
    printf("Nome: %s\n",p_conta->nomeTitular);
    printf("Saldo: %.2lf\n", p_conta->saldo);
}

void ListarOpcoes(){
        printf("\tMenu\n");
        printf("\t1.Visualizar conta\n");
        printf("\t2.Excluir conta\n");
        printf("\t3.Depositar\n");
        printf("\t4.Sacar\n");
        printf("\t5.Relatorio de movimentacoes\n");
        printf("\t6.Listar opcoes\n");
        printf("\t7.Sair\n");
}

void RegistrarArquivo(char *arquivoDados, struct Conta *p_conta){
    FILE *arquivo = fopen("./user/data.txt", "w+");
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }else{
        fprintf(arquivo, "%d", p_conta->numeroConta);
        fprintf(arquivo,"\n");
        fprintf(arquivo, "%s", p_conta->nomeTitular);
        fprintf(arquivo,"\n");
        fprintf(arquivo, "%lf", p_conta->saldo);
        // Fecha o arquivo
        fclose(arquivo);
    }

}

void PegarDados(char *ArquivoDados, struct Conta *p_conta){
    FILE *arquivo = fopen(ArquivoDados,"r");
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha),arquivo);
    sscanf(linha, "%d",&p_conta->numeroConta);

    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
    }

    strcpy(p_conta->nomeTitular,linha);

    fgets(linha, sizeof(linha), arquivo);
    sscanf(linha, "%lf", &p_conta->saldo);

    fclose(arquivo);
}

void ExcluirConta(struct Conta *p_conta, char *arquivoDados){
    FILE *arquivo = fopen(arquivoDados, "w"); // Abre o arquivo em modo de escrita

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fclose(arquivo); // Fecha o arquivo para limpar seu conteúdo ou criar um novo arquivo vazio

    p_conta->numeroConta = 0;
    p_conta->nomeTitular[0] = '\0';
    p_conta->saldo = 0.0;

}