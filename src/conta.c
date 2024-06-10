#include "Conta.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>

// Função para capturar entrada do usuário
void capturarEntrada(char *buffer, int tamanho) {
    // Continua solicitando entrada até que uma entrada válida seja fornecida
    do {
        if (fgets(buffer, tamanho, stdin) != NULL) {
            size_t comprimento = strlen(buffer);
            if (comprimento > 0 && buffer[comprimento - 1] == '\n') {
                // Verifica se a linha inserida é apenas uma nova linha ('\n')
                if (comprimento == 1) {
                    // Se a entrada for apenas '\n', limpa o buffer
                    buffer[0] = '\0';
                } else {
                    // Caso contrário, remove o caractere '\n' do final
                    buffer[comprimento - 1] = '\0';
                }
            }
        }
    } while (buffer[0] == '\0'); // Continua enquanto a entrada estiver vazia
}

// Função para ler um número inteiro sem sinal com validação
void LerUnsignedInt(const char *prompt, unsigned int *numero) {
    char buffer[50];
    while (1) {
        printf("%s", prompt);
        capturarEntrada(buffer, sizeof(buffer));
        if (sscanf(buffer, "%u", numero) == 1) {
            break;
        } else {
            printf("Entrada invalida. Por favor, digite um numero valido.\n");
        }
    }
}

// Função para ler um número inteiro com validação
void LerInt(const char *prompt, int *numero) {
    char buffer[50];
    while (1) {
        printf("%s", prompt);
        capturarEntrada(buffer, sizeof(buffer));
        if (sscanf(buffer, "%d", numero) == 1) {
            break;
        } else {
            printf("Entrada invalida. Por favor, digite um numero valido.\n");
        }
    }
}

// Função para ler um número long long com validação
void LerLongLong(const char *prompt, long long *numero) {
    char buffer[50];
    while (1) {
        printf("%s", prompt);
        capturarEntrada(buffer, sizeof(buffer));
        if (sscanf(buffer, "%lld", numero) == 1) {
            break;
        } else {
            printf("Entrada invalida. Por favor, digite um numero valido.\n");
        }
    }
}

// Função para ler um número de ponto flutuante com validação
void LerFloat(const char *prompt, double *numero) {
    char buffer[50];
    while (1) {
        printf("%s", prompt);
        capturarEntrada(buffer, sizeof(buffer));
        if (sscanf(buffer, "%lf", numero) == 1) {
            break;
        } else {
            printf("Entrada invalida. Por favor, digite um numero valido.\n");
        }
    }
}

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar uma nova conta
void CadastrarConta(struct Conta *p_conta) {
    int email_check = 1;
    printf("Cadastrando uma nova conta...\n");
    limparBuffer();
    LerInt("Digite o numero da sua conta: ", &p_conta->numeroConta);
    printf("Digite o nome do titular da conta: ");
    capturarEntrada(p_conta->nomeTitular, sizeof(p_conta->nomeTitular));

    while (email_check) {
        printf("Digite seu e-mail: ");
        capturarEntrada(p_conta->email, sizeof(p_conta->email));
        if (strchr(p_conta->email, '@') != NULL && strchr(p_conta->email, '.') != NULL) {
            email_check = 0;
        } else {
            printf("Digite um e-mail valido contendo '@' e '.'\n");
        }
    }

    LerLongLong("Digite seu telefone: ", &p_conta->telefone);
    printf("Digite seu endereco: ");
    capturarEntrada(p_conta->endereco, sizeof(p_conta->endereco));
    LerUnsignedInt("Digite o CEP: ", &p_conta->CEP);
    system("cls");
    printf("\nConta cadastrada com sucesso!\n\n");
    RegistrarArquivo(p_conta);
}

// Função para imprimir os dados da conta
void ImprimirDados(struct Conta *p_conta) {
    Linha();
    printf("Numero da conta: %d\n", p_conta->numeroConta);
    printf("Nome: %s\n", p_conta->nomeTitular);
    printf("Email: %s\n", p_conta->email);
    printf("Telefone: %lld\n", p_conta->telefone);
    printf("Endereco: %s\n", p_conta->endereco);
    printf("CEP: %u\n", p_conta->CEP);
    printf("Saldo atual: R$ %.2lf\n", p_conta->saldo);
    printf("Credito de celular: R$ %.2lf\n", p_conta->credito_tel);
    RegistarConsulta();
}

// Função para listar as opções do menu
void ListarOpcoes() {
    Linha();
    printf("1. Visualizar conta\n");
    printf("2. Excluir conta\n");
    printf("3. Depositar\n");
    printf("4. Sacar\n");
    printf("5. Gerar relatorio\n");
    printf("6. Recarga de celular\n");
    printf("7. Editar conta\n");
    printf("8. Simular Emprestimo\n");
    printf("0. Sair\n");
    Linha();
}

// Função para registrar os dados da conta no arquivo
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
        fprintf(arquivo, "%s", p_conta->email);
        fprintf(arquivo,"\n");
        fprintf(arquivo, "%lld", p_conta->telefone);
        fprintf(arquivo,"\n");
        fprintf(arquivo, "%s", p_conta->endereco);
        fprintf(arquivo,"\n");
        fprintf(arquivo, "%u", p_conta->CEP);
        fprintf(arquivo,"\n");
        fprintf(arquivo, "%lf", p_conta->saldo);
        fprintf(arquivo,"\n");
        fprintf(arquivo, "%lf", p_conta->credito_tel);
        // Fecha o arquivo
        fclose(arquivo);
    }

}

void SincronizarDados(struct Conta *p_conta){
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
        sscanf(linha, "%s", &p_conta->email);

        fgets(linha, sizeof(linha), arquivo);
        sscanf(linha, "%lld", &p_conta->telefone);

        if (fgets(linha, sizeof(linha), arquivo) != NULL) {
            linha[strcspn(linha, "\n")] = '\0';
        }
        strcpy(p_conta->endereco,linha);

        fgets(linha, sizeof(linha), arquivo);
        sscanf(linha, "%u", &p_conta->CEP);

        fgets(linha, sizeof(linha), arquivo);
        sscanf(linha, "%lf", &p_conta->saldo);
        
        fgets(linha, sizeof(linha), arquivo);
        sscanf(linha, "%lf", &p_conta->credito_tel);
        
        

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
    p_conta->CEP = 0;
    p_conta->credito_tel = 0;
    LimparRelatorio();
    printf("Excluindo conta...\n");
}

void Depositar(struct Conta *p_conta){
    double deposito;
    double saldo_antigo = p_conta->saldo;
    printf("Digite o valor a ser depositado: R$ ");
    scanf("%lf", &deposito);

    if(deposito < 0){
        printf("Valor invalido! Tente novamente.\n");
        return;
    }

    p_conta->saldo += deposito;
    RegistrarArquivo(p_conta);
    system("cls");
    printf("Valor depositado com sucesso!\n");
    printf("Seu saldo foi de R$ %.2lf para R$ %.2lf\n", saldo_antigo,p_conta->saldo);
    RegistrarRelatorio(p_conta, &saldo_antigo, &p_conta->saldo);
}


void Sacar(struct Conta *p_conta){
    double saque;
    double saldo_antigo = p_conta->saldo;
    printf("Valor disponivel para saque: R$ %.2lf\n", p_conta->saldo);
    printf("Digite o valor a ser sacado: R$ ");
    scanf("%lf", &saque);
    if((p_conta->saldo - saque) < 0){// trocar por um while
        printf("Saldo insuficiente, tente sacar um quantia menor\n");
        return;
    }
    if(saque < 0){
        printf("Valor invalido! Tente novamente.\n");
        return;
    }
    p_conta->saldo = p_conta->saldo - saque;
    system("cls");
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
        strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", infoTempo);

        if((*val_antigo > *val_atual)){
            fprintf(arquivo, "[%s] - Saque de R$%.2lf [R$ %.2lf --> R$ %.2lf]\n",dataHora,(*val_antigo-*val_atual), *val_antigo, *val_atual);
        } else{
            fprintf(arquivo, "[%s] - Deposito de R$ %.2lf [R$ %.2lf --> R$ %.2lf]\n",dataHora,(*val_atual-*val_antigo), *val_antigo, *val_atual);

        }

    }
    fclose(arquivo);
}

void RegistarConsulta(){
    FILE *arquivo = fopen("./user/report.txt", "a+");
    // Verifica se o arquivo foi aberto corretamente

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else{
        time_t agora = time(NULL);
        struct tm *infoTempo = localtime(&agora);
        char dataHora[20];
        strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", infoTempo);

            fprintf(arquivo, "[%s] - Consulta de saldo",dataHora);
            fprintf(arquivo,"\n");
    }
    fclose(arquivo);
}


void ImprimirRelatorio() {
    FILE *arquivo = fopen("./user/report.txt", "a+");
    system("cls");
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    // Verificar se o arquivo está vazio
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    if (tamanho == 0) {
        printf("Relatorio nao gerado.\n");
        Linha();
        fclose(arquivo);
        return;
    }

    // Voltar ao início do arquivo
    fseek(arquivo, 0, SEEK_SET);

    char linha[256];
    printf("Relatorio de transacoes e consultas de saldo:\n");
    Linha();
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }
    fclose(arquivo);
}

void LimparRelatorio(){
    fclose(fopen("./user/report.txt", "w"));
}

void RegistrarRecargaCelular(struct Conta *p_conta, double val_recarga){
    FILE *arquivo = fopen("./user/report.txt", "a+");
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else{
        time_t agora = time(NULL);
        struct tm *infoTempo = localtime(&agora);
        char dataHora[20];
        strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", infoTempo);

        fprintf(arquivo, "[%s] - Recarga de R$ %.2lf realizada no numero %lld",dataHora,val_recarga,p_conta->telefone);
        fprintf(arquivo,"\n");

    }
    fclose(arquivo);
}

void RecargaCelular(struct Conta *p_conta){
    double val_recarga;
    printf("Credito atual: R$ %.2lf\n",p_conta->credito_tel);
    printf("Saldo disponivel: R$ %.2lf\n", p_conta->saldo);
    LerFloat("Digite o valor da recarga: ", &val_recarga);
    system("cls");


    if(val_recarga < 0){
        printf("Valor invalido! Tente novamente.\n");
        return;
    }
    
    if(val_recarga > p_conta->saldo){
        printf("Saldo insuficiente para realizar a recarga!\n");
    } else{
        p_conta->saldo -= val_recarga;
        printf("Recarga de R$ %.2lf realizada no numero %lld\n", val_recarga, p_conta->telefone);
        p_conta->credito_tel =+ val_recarga;
        printf("Saldo atualizado: %.2lf\n", p_conta->saldo);

    }
    RegistrarArquivo(p_conta);
    RegistrarRecargaCelular(p_conta, val_recarga);
}

void RegistrarEdicao(const char *prompt, struct Conta *p_conta){
    FILE *arquivo = fopen("./user/report.txt", "a+");
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else{
        time_t agora = time(NULL);
        struct tm *infoTempo = localtime(&agora);
        char dataHora[20];
        strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", infoTempo);

        fprintf(arquivo, "[%s] - %s foi alterado",dataHora,prompt);
        fprintf(arquivo,"\n");

    }
    fclose(arquivo);
}



void EditarUsuario(struct Conta *p_conta){
    int input = 1;
    int loop_editar = 1;
    int email_check = 1;

    do { 
        printf("Selecione o que deseja editar:\n");
        Linha();
        printf("1. Nome\n");
        printf("2. Email\n");
        printf("3. Telefone\n");
        printf("4. Endereco\n");
        printf("5. CEP\n");
        printf("0. Sair\n");
        Linha();

        LerInt("Escolha uma das opcoes: ", &input);
        switch(input){
        case 0:
            system("cls");
            loop_editar = 0;
            break;
        case 1:
            system("cls");
            printf("Nome atual: %s\n",p_conta->nomeTitular);
            printf("Nome editado: ");
            capturarEntrada(p_conta->nomeTitular, sizeof(p_conta->nomeTitular));
            RegistrarEdicao("Nome",p_conta);
            RegistrarArquivo(p_conta);
            system("cls");
            DadosSucesso();
            break;

        case 2:
            system("cls");
            printf("Email atual: %s\n",p_conta->email);
            printf("Email editado: ");
            while(email_check){
                capturarEntrada(p_conta->email, sizeof(p_conta->email));
                if(strchr(p_conta->email, '@') != NULL && strchr(p_conta->email, '.') != NULL){
                    email_check = 0;
                } else{
                    printf("Digite um e-mail valido contendo '@' e '.'\n");
                }
            }
            RegistrarEdicao("Email",p_conta);
            RegistrarArquivo(p_conta);
            system("cls");
            DadosSucesso();
            break;
        case 3:
            system("cls");
            printf("Telefone atual: %lld\n",p_conta->telefone);
            
            LerLongLong("Telefone editado: ", &p_conta->telefone);
            RegistrarEdicao("Telefone",p_conta);
            RegistrarArquivo(p_conta);
            system("cls");
            DadosSucesso();
            break;
        case 4:
            system("cls");
            printf("Endereco atual: %s\n",p_conta->endereco);
            printf("Endereco editado: ");
            
            capturarEntrada(p_conta->endereco, sizeof(p_conta->endereco));
            RegistrarEdicao("Endereco",p_conta);
            RegistrarArquivo(p_conta);
            system("cls");
            DadosSucesso();
            break;
        case 5:
            system("cls");
            printf("CEP atual: %u\n",p_conta->CEP);
            
            LerUnsignedInt("CEP editado: ", &p_conta->CEP);
            RegistrarEdicao("CEP",p_conta);
            RegistrarArquivo(p_conta);
            system("cls");
            DadosSucesso();
            break;
        default:
            printf("Opcao invalida!");
        }
    } while(loop_editar);

}

void DadosSucesso(){
    printf("Dados alterados com sucesso!\n");
}

void SimulacaoEmprestimo(){
    system("cls");
    printf("Iniciando simulacao de emprestimo...\n");
    double val_emprestimo;
    double taxa_anual;
    int prazo_meses;
    char sair;
    int menu = 1;
        LerFloat("Digite o valor do emprestimo: ", &val_emprestimo);
        LerFloat("Digite o valor da taxa anual (em %): ", &taxa_anual);
        LerInt("Digite o prazo (em meses): ",&prazo_meses);

        double parcelaMensal = CalcularParcelaMensal(val_emprestimo, taxa_anual, prazo_meses);

        system("cls");
        Linha();
        printf("Dados do emprestimo simulado:\n\n");
        printf("Valor do emprestimo: R$ %.2lf \n", val_emprestimo);
        printf("Total de parcelas: %d \n", prazo_meses);
        printf("Taxa anual: %.2lf%% \n", taxa_anual);


        printf("Juros devidos: R$ %.2lf\n", fabs(val_emprestimo - (parcelaMensal * prazo_meses)));
        printf("Parcela mensal: R$ %.2f\n", parcelaMensal);
        printf("Montante total a ser pago: R$ %.2f", parcelaMensal * prazo_meses);
        printf("\n");
}

double CalcularParcelaMensal(double valorEmprestimo, double taxaJurosAnual, int prazoMeses) {
    double taxaJurosMensal = taxaJurosAnual / 12 / 100;
    double parcelaMensal = (valorEmprestimo * taxaJurosMensal) / (1 - pow(1 + taxaJurosMensal, -prazoMeses));
    return parcelaMensal;
}

