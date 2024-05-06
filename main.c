#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    printf("|===================================|\n");
    printf("| Bem vindo (a) ao Caixa Eletronico |\n");
    printf("|===================================|\n");

    return 0;
}
