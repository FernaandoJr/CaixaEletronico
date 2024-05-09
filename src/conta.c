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
    printf("\nNumero da conta: %d", p_conta->numeroConta);
    printf("\nNome: %s",p_conta->nomeTitular);
    printf("\nSaldo: %.2lf\n", p_conta->saldo);
}

void ListarOpcoes(){
        printf("\tMenu\n");
        printf("\t1.Visualizar saldo\n");
        printf("\t2.Depositar\n");
        printf("\t3.Sacar\n");
        printf("\t4.Relatorio de movimentacoes\n");
        printf("\t5.Listar opcoes\n");
        printf("\t6.Sair\n");
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