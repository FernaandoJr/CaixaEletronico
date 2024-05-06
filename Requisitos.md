## Simulador de Caixa Eletrônico

### Requisitos Detalhados:

- **Estrutura de Dados para Conta Bancária:**
  Defina uma estrutura `Conta` para armazenar informações do titular da conta e o saldo atual:

    ```c
    typedef struct {
        int numeroConta;  // Número da conta
        char nomeTitular[100];  // Nome do titular da conta
        double saldo;  // Saldo atual da conta
    } Conta;
    
    ```

- **Validação de Transações:**

  Assegure que as transações sejam validadas, por exemplo, não permitindo saques que excedam o saldo disponível.

- **Persistência de Dados:**

  Todas as informações das contas devem ser armazenadas em um arquivo, garantindo que as informações sejam mantidas mesmo após o programa ser encerrado.

- **Interface do Usuário:**

  Desenvolva uma interface simples de linha de comando que permita ao usuário realizar operações bancárias e visualizar o saldo de sua conta.

- **Relatório de Transações:**

  Implemente uma funcionalidade para gerar um relatório de todas as transações realizadas durante a sessão, incluindo depósitos, retiradas e consultas de saldo.

- **Digrama de Caso de Uso:**

  Criar um Diagrama de Caso de Uso que represente todas as interações possíveis dos usuários com o simulador de caixa eletrônico.

  ### Requisitos Adicionais:

    - **Documentação do Projeto:**
      Preparem uma documentação completa para o Simulador de Caixa Eletrônico. A documentação deve incluir:
        - **Parte Escrita:**
            - **Descrição Geral do Sistema:** Um resumo do propósito e das funcionalidades do sistema.
            - **Requisitos Funcionais:** Uma descrição detalhada de todas as funcionalidades e casos de uso implementados no sistema.
            - **Diagramas:** Incluir diagramas de caso de uso já desenvolvidos, diagramas de fluxo de dados e quaisquer outros diagramas relevantes que ajudem a visualizar a arquitetura e o fluxo do sistema.
            - **Guia do Usuário:** Instruções passo a passo sobre como usar o sistema, incluindo screenshots das interfaces de usuário.
            - **Seção de Problemas e Soluções:** Uma discussão sobre quaisquer desafios enfrentados durante o desenvolvimento e como foram resolvidos.
        - **Comentários no Código:**
            - **Código Fonte Comentado:** Todos os arquivos de código devem incluir comentários detalhados explicando a funcionalidade de blocos de código importantes e a lógica por trás de decisões de programação críticas.
            - **Funções e Módulos:** Cada função e módulo deve ter uma breve descrição de sua finalidade e de quaisquer parâmetros ou valores de retorno.
            - **Estruturas de Dados:** Comentários detalhados sobre as estruturas de dados usadas, explicando o motivo da escolha e como elas são utilizadas no sistema.

      Esta documentação deve ser entregue em formato digital, preferencialmente em PDF, e deve ser clara, concisa e bem organizada para facilitar a compreensão e a manutenção do sistema.