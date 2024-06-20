/**
 * @file conta.h
 * @brief Definição da estrutura de dados e protótipos de funções relacionadas à conta bancária.
 */

#ifndef CONTA_H
#define CONTA_H

/**
 * @struct Conta
 * @brief Estrutura que representa uma conta bancária.
 * @var Conta::numeroConta
 * Número da conta.
 * @var Conta::nomeTitular
 * Nome do titular da conta.
 * @var Conta::email
 * Endereço de e-mail do titular da conta.
 * @var Conta::telefone
 * Número de telefone do titular da conta.
 * @var Conta::endereco
 * Endereço do titular da conta.
 * @var Conta::CEP
 * Código de Endereçamento Postal (CEP) do titular da conta.
 * @var Conta::saldo
 * Saldo atual da conta.
 * @var Conta::credito_tel
 * Crédito disponível para recarga de celular.
 * @var Conta::limite_saque
 * Limite máximo de saque da conta.
 */
typedef struct Conta{
    int numeroConta;
    char nomeTitular[100];
    char email[50];
    long long telefone;
    char endereco[100];
    unsigned int CEP;
    double saldo;
    double credito_tel;
    double limite_saque;
} item;

/**
 * @brief Lê um número long long do usuário.
 * @param prompt Mensagem de prompt exibida ao usuário.
 * @param numero Ponteiro para a variável onde o número lido será armazenado.
 */
void LerLongLong(const char *prompt, long long *numero);

/**
 * @brief Lê um texto do usuário.
 * @param buffer Buffer onde o texto lido será armazenado.
 * @param tamanho Tamanho máximo do texto a ser lido.
 */
void LerTexto(char *buffer, int tamanho);

/**
 * @brief Cadastra uma nova conta.
 * @param p_conta Ponteiro para a estrutura de conta onde os dados serão armazenados.
 */
void CadastrarConta(struct Conta *p_conta);

/**
 * @brief Lê os dados de uma conta.
 * @param p_conta Ponteiro para a estrutura de conta onde os dados serão armazenados.
 */
void LerDados(struct Conta *p_conta);

/**
 * @brief Imprime os dados de uma conta.
 * @param p_conta Ponteiro para a estrutura de conta que será impressa.
 */
void ImprimirDados(struct Conta *p_conta);

/**
 * @brief Lista as opções disponíveis.
 */
void ListarOpcoes();

/**
 * @brief Registra os dados de uma conta em um arquivo.
 * @param p_conta Ponteiro para a estrutura de conta que será registrada.
 */
void RegistrarArquivo(struct Conta *p_conta);

/**
 * @brief Exclui uma conta.
 * @param p_conta Ponteiro para a estrutura de conta que será excluída.
 */
void ExcluirConta(struct Conta *p_conta);

/**
 * @brief Deposita um valor na conta.
 * @param p_conta Ponteiro para a estrutura de conta onde o valor será depositado.
 */
void Depositar(struct Conta *p_conta);

/**
 * @brief Sincroniza os dados da conta.
 * @param p_conta Ponteiro para a estrutura de conta que será sincronizada.
 */
void SincronizarDados(struct Conta *p_conta);

/**
 * @brief Realiza um saque na conta.
 * @param p_conta Ponteiro para a estrutura de conta onde o valor será sacado.
 */
void Sacar(struct Conta *p_conta);

/**
 * @brief Registra um relatório de transação.
 * @param p_conta Ponteiro para a estrutura de conta relacionada à transação.
 * @param val_antigo Ponteiro para a variável que armazena o valor antigo da transação.
 * @param val_atual Ponteiro para a variável que armazena o valor atual da transação.
 */
void RegistrarRelatorio(struct Conta *p_conta, double *val_antigo, double *val_atual);

/**
 * @brief Imprime o relatório de transações.
 */
void ImprimirRelatorio();

/**
 * @brief Exclui o relatório de transações.
 */
void ExcluirRelatorio();

/**
 * @brief Registra uma consulta.
 */
void RegistarConsulta();

/**
 * @brief Limpa o relatório de transações.
 */
void LimparRelatorio();

/**
 * @brief Imprime uma linha de separação.
 */
void Linha();

/**
 * @brief Realiza uma recarga de celular.
 * @param p_conta Ponteiro para a estrutura de conta onde a recarga será realizada.
 */
void RecargaCelular(struct Conta *p_conta);

/**
 * @brief Edita os dados do usuário.
 * @param p_conta Ponteiro para a estrutura de conta que será editada.
 */
void EditarUsuario(struct Conta *p_conta);

/**
 * @brief Realiza uma simulação de empréstimo.
 */
void SimulacaoEmprestimo();

/**
 * @brief Limpa o buffer do teclado.
 */
void limparBuffer();

/**
 * @brief Captura a entrada do usuário.
 * @param buffer Buffer onde a entrada será armazenada.
 * @param tamanho Tamanho máximo da entrada a ser capturada.
 */
void capturarEntrada(char *buffer, int tamanho);

/**
 * @brief Lê um número float do usuário.
 * @param prompt Mensagem de prompt exibida ao usuário.
 * @param numero Ponteiro para a variável onde o número lido será armazenado.
 */
void LerFloat(const char *prompt, double *numero);

/**
 * @brief Lê um número unsigned int do usuário.
 * @param prompt Mensagem de prompt exibida ao usuário.
 * @param numero Ponteiro para a variável onde o número lido será armazenado.
 */
void LerUnsignedInt(const char *prompt, unsigned int *numero);

/**
 * @brief Lê um número int do usuário.
 * @param prompt Mensagem de prompt exibida ao usuário.
 * @param numero Ponteiro para a variável onde o número lido será armazenado.
 */
void LerInt(const char *prompt,int *numero);

/**
 * @brief Calcula o valor da parcela mensal de um empréstimo.
 * @param valorEmprestimo Valor total do empréstimo.
 * @param taxaJurosAnual Taxa de juros anual do empréstimo.
 * @param prazoMeses Prazo em meses para pagamento do empréstimo.
 * @return Valor da parcela mensal do empréstimo.
 */
double CalcularParcelaMensal(double valorEmprestimo, double taxaJurosAnual, int prazoMeses);

/**
 * @brief Registra uma recarga de celular.
 * @param p_conta Ponteiro para a estrutura de conta onde a recarga será registrada.
 * @param val_recarga Valor da recarga de celular.
 */
void RegistrarRecargaCelular(struct Conta *p_conta, double val_recarga);

/**
 * @brief Exibe uma mensagem de sucesso.
 */
void DadosSucesso();

/**
 * @brief Registra uma edição.
 * @param prompt Mensagem de prompt exibida ao usuário.
 * @param p_conta Ponteiro para a estrutura de conta que será editada.
 */
void RegistrarEdicao(const char *prompt, struct Conta *p_conta);

#endif //CONTA_H
