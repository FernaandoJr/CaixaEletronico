#include <stdio.h>

int main(void) {
    int menu = 1;
    printf("|===================================|\n");
    printf("| Bem vindo (a) ao Caixa Eletronico  |\n");
    printf("|===================================|\n\n");
    printf(" \t\tMENU\n");
    printf("\t1.Criar uma conta\n");
    printf("\t2.Depositar\n");
    printf("\t3.Sacar\n");
    printf("\t4.Visualizar saldo\n");
    printf("\t4.Relatorio de transacoes\n");
    printf("\t4.Sair\n");
    printf(" ===================================\n");


    printf("Digite uma das opcoes acima:");
    scanf("%d",&menu);

    switch (menu) {
        case 1:
            printf("\nusuario escolheu 1");
        break;
        case 2:
            printf("\nusuario escolheu 2");
        break;
        case 3:
            printf("\nusuario escolheu 3");
        break;
        case 4:
            printf("\nusuario escolheu 4");
        break;
        default: ;
    }

    return 0;


}
