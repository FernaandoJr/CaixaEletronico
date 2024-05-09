#include "Conta.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void CadastrarConta(struct Conta *p_conta){
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

// void RegistrarArquivo(struct Conta *p_conta, char *arquivoDados){


// }