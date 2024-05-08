#include <stdio.h>
#include "conta.h"

int main(void) {
    int menu = 1;
    printf("|===================================|\n");
    printf("| Bem vindo (a) ao Caixa Eletronico |\n");
    printf("|===================================|\n");

    Conta Usuario;

    do {
        printf("\t\tMENU\n");
        printf("\t1.Visualizar saldo\n");
        printf("\t2.Depositar\n");
        printf("\t3.Sacar\n");
        printf("\t4.Relatorio de movimentacoes\n");
        printf("\t5.Sair\n");
        printf("=================================\n");
        printf("\nDigite uma das opcoes acima:");
        scanf("%d",&menu);
        switch (menu) {
            case 1:
                printf("\nEscolheu 1\n");
            break;
            case 2:
                printf("\nEscolheu 2\n");
            break;
            case 3:
                printf("\nEscolheu 3\n");
            break;
            case 4:
                printf("\nEscolheu 4\n");
            break;
            case 5:
                printf("\nEscolheu 5\n");
            break;
            case 6:
                printf("\nEncerrando o programa.");
            break;
            default:
                printf("\nVoce escolheu uma opcao invalida.\n");
        }
    }   while (menu != 5);
    return 0;
}