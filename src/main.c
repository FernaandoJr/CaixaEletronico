/**
 * Função principal do programa Caixa Eletrônico Helpay.
 * 
 * Este programa simula um caixa eletrônico, permitindo ao usuário realizar diversas operações bancárias.
 * O programa lê os dados do usuário de um arquivo de dados e permite ao usuário realizar operações como:
 * - Visualizar os dados da conta
 * - Excluir a conta atual e cadastrar uma nova conta
 * - Realizar depósitos na conta
 * - Realizar saques da conta
 * - Visualizar o relatório de transações
 * - Realizar recarga de celular
 * - Editar os dados do usuário
 * - Simular um empréstimo
 * 
 * O programa utiliza arquivos para armazenar os dados do usuário e o relatório de transações.
 * 
 * @param argc O número de argumentos de linha de comando.
 * @param argv Um array de strings contendo os argumentos de linha de comando.
 * @return O código de status da execução do programa.
 */
int main(int argc, char *argv[]) {
    // ...
}
#include <stdio.h>
#include <string.h>
#include "conta.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[]) {
    int loop = 1;
    char arquivoDados[] = "./user/data.txt";
    char arquivosRelatorio[] = "./user/report.txt";
    int menu = 1;
    struct Conta usuario;

    FILE *p_dados = fopen(arquivoDados,"a+");
    system("cls");
    printf("\n************ Caixa Eletronico Helpay ************\n");

    if(NULL != p_dados){
        fseek (p_dados, 0, SEEK_END);
        int size = ftell(p_dados);
        if(size == 0){
            printf("Nao foram encontrados os dados!\n");
            fclose(p_dados);
            CadastrarConta(&usuario);
            RegistrarArquivo(&usuario);
        } else{
            SincronizarDados(&usuario);
            printf("\nBem vindo(a) novamente %s!\n\n",usuario.nomeTitular);

        }
    }
    SincronizarDados(&usuario);
    LimparRelatorio();
    
    do {
        ListarOpcoes();
        printf("Escolha uma das opcoes: ");
        scanf("%d",&menu);
        system("cls");
        
        switch (menu) {
            case 0:
                system("cls");
                printf("Encerrando o programa...\nObrigado pela preferencia!");
                loop = 0;
            break;
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
                RecargaCelular(&usuario);
            break;
            case 7:
                EditarUsuario(&usuario);
            break;
            case 8:
                SimulacaoEmprestimo();
            break;
            default:
                printf("Opcao invalida!\n");
        }
    }   while (loop);
    fclose(p_dados);
    LimparRelatorio();
    return 0;
}
