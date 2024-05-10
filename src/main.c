#include <stdio.h>
#include <string.h>
#include "conta.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
    //Declaração de variáveis
    char arquivoDados[] = "./user/data.txt";
    char arquivosRelatorio[] = "./user/report.txt";
    int menu = 1;
    struct Conta usuario;

    FILE *p_dados;
    p_dados = fopen(arquivoDados,"a+");

    printf("---------------------------------------\n");
    printf("-- Bem vindo (a) ao Caixa Eletronico --\n");
    printf("---------------------------------------\n\n");


    // Verifica se o arquivo foi aberto corretamente
    if(NULL != p_dados){
        fseek (p_dados, 0, SEEK_END);
        int size = ftell(p_dados);
        if(size == 0){
            // Condição: Arquivo vazio
            printf("Nao foram encontrados os dados!\n");
            fclose(p_dados);
            CadastrarConta(&usuario);
            RegistrarArquivo(&usuario);
        }
    }
    ListarOpcoes();
    do {
        AtualizarArquivo(&usuario);
        printf("Escolha uma das opcoes do MENU: \n");
        scanf("%d",&menu);
        
        switch (menu) {
            case 1:
                ImprimirDados(&usuario);
            break;
            case 2:
                ExcluirConta(&usuario);
                printf("Excluindo conta...\n");
                CadastrarConta(&usuario);
                RegistrarArquivo(&usuario);
                ListarOpcoes();
            break;
            case 3:
                Depositar(&usuario);
            break;
            case 4:
                printf("Escolheu 4\n");
            break;
            case 5:
                ListarOpcoes();
            break;
            case 6:
                printf("Escolheu 6\n");
            break;
            case 7:
                printf("Encerrando o programa.");
                return;
            break;
            default:
                printf("Voce escolheu uma opcao invalida.\n");
        }
    }   while (1);
    fclose(arquivoDados);
    return 0;
}
