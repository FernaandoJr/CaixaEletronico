#include <stdio.h>
#include <string.h>
#include "conta.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("|===================================|\n");
    printf("| Bem vindo (a) ao Caixa Eletronico |\n");
    printf("|===================================|\n\n");
    
    //Declaração de variáveis
    char arquivoDados[] = "./user/data.txt";
    char arquivosRelatorio[] = "./user/report.txt";
    int menu = 1;
    struct Conta usuario;
    int size;
    FILE *p_dados;
    p_dados = fopen(arquivoDados,"a+");
    
    // Verifica se o arquivo foi aberto corretamente
    if(NULL != p_dados){
        fseek (p_dados, 0, SEEK_END);
        size = ftell(p_dados);
        if(size == 0){
            // Condição: Arquivo vazio
            printf("Nao foram encontrados os dados!\n");
            CadastrarConta(&usuario);
            fclose(p_dados);

            RegistrarArquivo(arquivoDados, &usuario);
        } else{
            // Condição: Arquivo com dados
            printf("arquivo com coisa");
        }


        // CadastrarConta(&usuario);
    }

    ListarOpcoes();
    do {
        printf("\nDigite uma das opcoes acima:");
        scanf("%d",&menu);
        
        switch (menu) {
            case 1:
                ImprimirDados(&usuario);
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
                ListarOpcoes();
            break;
            case 6:
                printf("\nEscolheu 6\n");
            break;
            case 7:
                printf("\nEncerrando o programa.");
            break;
            default:
                printf("\nVoce escolheu uma opcao invalida.\n");
        }
    }   while (menu != 7);
    fclose(arquivoDados);
    return 0;
}
