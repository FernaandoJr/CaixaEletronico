#include "Conta.h"
#include <stdio.h>

void Teste(){
    printf("Ola");
}

void LerDados(struct Conta *p_conta){
    printf("Digite o numero da conta:\n");
    scanf("%d", &p_conta->numeroConta);
    fflush(stdin);
    printf("Digite o nome do titular da conta:\n");
    gets(p_conta->nomeTitular); 
}

void ImprimirDados(struct Conta *p_conta){
    printf("\n Numero da conta: %d", &p_conta->numeroConta);
    printf("\nNome: %s",&p_conta->numeroConta);
    printf("Saldo: %d", &p_conta->saldo);
}