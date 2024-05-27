#include <stdio.h>
#include <string.h>
#include "conta.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[]) {
    //Declaração de variáveis
    int loop = 1;
    char arquivoDados[] = "./user/data.txt";
    char arquivosRelatorio[] = "./user/report.txt";
    int menu = 1;
    int first_time = 0;
    struct Conta usuario;

    FILE *p_dados = fopen(arquivoDados,"a+");
    system("cls");
    printf("\n************ Caixa Eletronico Helpay ************\n");

    

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
        } else{
            AtualizarArquivo(&usuario);
            printf("\n\tBem vindo(a) novamente %s!\n\n",usuario.nomeTitular);

        }
    }
    AtualizarArquivo(&usuario);
    LimparRelatorio();
    
    do {
        ListarOpcoes();
        printf("Escolha uma das opcoes: ");
        scanf("%d",&menu);
        system("cls");
        
        switch (menu) {
            case 1:
                ImprimirDados(&usuario);
            break;
            case 2:
                ExcluirConta(&usuario);
                CadastrarConta(&usuario);
            break;
            case 3:
                Depositar(&usuario);
            break;
            case 4:
                Sacar(&usuario);
            break;
            case 5:
                ImprimirRelatorio();
            break;
            case 6:
                ListarOpcoes();
            break;
            case 7:
                printf("Encerrando o programa...\nObrigado pela preferencia!");
                loop = 0;
            break;
            default:
                printf("Opcao invalida!");
        }
    }   while (loop);
    fclose(p_dados);
    LimparRelatorio();
    return 0;
}
