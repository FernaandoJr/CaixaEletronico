#include "Conta.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


void CadastrarConta(struct Conta *p_conta){
    // Pegar os dados do usuário e colocar dentro da struct
    printf("Cadastrando uma nova conta...\n");
    printf("Digite o numero da sua conta: ");
    scanf("%d", &p_conta->numeroConta);
    fflush(stdin);
    printf("Digite o nome do titular da conta: ");
    gets(p_conta->nomeTitular); 
    printf("Digite o saldo: ");
    scanf("%lf", &p_conta->saldo);
    printf("Conta cadastrada com sucesso!\n");
    RegistrarArquivo(p_conta);
}

void ImprimirDados(struct Conta *p_conta){
    printf("Numero da conta: %d\n", p_conta->numeroConta);
    printf("Nome do titular: %s\n",p_conta->nomeTitular);
    printf("Saldo disponivel: R$ %.2lf\n", p_conta->saldo);
    RegistartConsulta();
}

void ListarOpcoes(){
        printf("*************************************************\n");
        printf("1. Visualizar conta\n");
        printf("2. Excluir conta\n");
        printf("3. Depositar\n");
        printf("4. Sacar\n");
        printf("5. Gerar relatorio da sessao\n");
        printf("6. Listar opcoes\n");
        printf("7. Sair\n");
        printf("*************************************************\n");
}

void RegistrarArquivo(struct Conta *p_conta){
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

void AtualizarArquivo(struct Conta *p_conta){
    FILE *arquivo = fopen("./user/data.txt", "r");
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }else{
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

    
}

void ExcluirConta(struct Conta *p_conta){
    FILE *arquivo = fopen("./user/data.txt", "w+"); // Abre o arquivo em modo de escrita

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fclose(arquivo); // Fecha o arquivo para limpar seu conteúdo ou criar um novo arquivo vazio

    p_conta->numeroConta = 0;
    p_conta->nomeTitular[0] = '\0';
    p_conta->saldo = 0.0;
    LimparRelatorio();
    printf("Excluindo conta...\n");
}

void Depositar(struct Conta *p_conta){
    double deposito;
    double saldo_antigo = p_conta->saldo;
    printf("Digite o valor a ser depositado: ");
    scanf("%lf", &deposito);

    if(deposito < 0){
        printf("Valor invalido! Tente novamente.");
        return;
    }

    p_conta->saldo += deposito;
    RegistrarArquivo(p_conta);
    printf("Valor depositado com sucesso!\n");
    printf("Seu saldo foi de R$ %.2lf para R$ %.2lf\n", saldo_antigo,p_conta->saldo);
    RegistrarRelatorio(p_conta, &saldo_antigo, &p_conta->saldo);
}


void Sacar(struct Conta *p_conta){
    double saque;
    double saldo_antigo = p_conta->saldo;
    printf("Valor Disponivel: %.2lf\n", p_conta->saldo);
    printf("Digite o valor a ser sacado: ");
    scanf("%lf", &saque);
    if((p_conta->saldo - saque) < 0){// trocar por um while
        printf("Saldo insuficiente, tente sacar um quantia menor\n");
        return;
    }
    p_conta->saldo = p_conta->saldo - saque;
    printf("Valor sacado com sucesso!\n");
    printf("Seu saldo foi de R$ %.2lf para R$ %.2lf\n", saldo_antigo,p_conta->saldo);
    RegistrarArquivo(p_conta);
    RegistrarRelatorio(p_conta, &saldo_antigo, &p_conta->saldo);
}

void RegistrarRelatorio(struct Conta *p_conta, double *val_antigo, double *val_atual){
    FILE *arquivo = fopen("./user/report.txt", "a+");
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else{
        time_t agora = time(NULL);
        struct tm *infoTempo = localtime(&agora);
        char dataHora[20];
        strftime(dataHora, sizeof(dataHora), "%H:%M:%S", infoTempo);

        if((*val_antigo > *val_atual)){
            fprintf(arquivo, "[%s] - Saque de R$%.2lf [R$ %.2lf --> R$ %.2lf]\n",dataHora,(*val_antigo-*val_atual), *val_antigo, *val_atual);
        } else{
            fprintf(arquivo, "[%s] - Deposito de R$ %.2lf [R$ %.2lf --> R$ %.2lf]\n",dataHora,(*val_atual-*val_antigo), *val_antigo, *val_atual);

        }

    }
    fclose(arquivo);
}

void RegistartConsulta(){
    FILE *arquivo = fopen("./user/report.txt", "a+");
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else{
        time_t agora = time(NULL);
        struct tm *infoTempo = localtime(&agora);
        char dataHora[20];
        strftime(dataHora, sizeof(dataHora), "%H:%M:%S", infoTempo);

            fprintf(arquivo, "[%s] - Consulta de saldo",dataHora);
            fprintf(arquivo,"\n");
    }
    fclose(arquivo);
}


void ImprimirRelatorio() {
    FILE *arquivo = fopen("./user/report.txt", "a+");
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Verificar se o arquivo está vazio
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    if (tamanho == 0) {
        printf("Nenhuma transacao encontrada.\n");
        fclose(arquivo);
        return;
    }

    // Voltar ao início do arquivo
    fseek(arquivo, 0, SEEK_SET);

    char linha[256];
    printf("Relatorio de Transacoes:\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }
    fclose(arquivo);
}

void LimparRelatorio(){
    fclose(fopen("./user/report.txt", "w"));
}