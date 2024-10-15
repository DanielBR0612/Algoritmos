#include <stdio.h>

int main(){
    char string[100];

    printf("digite seu nome: \n");
    scanf("%s", string);

    printf("Olá %s, bem-vindo(a) ao mundo da linguagem de programação C!\n", string);

    return 0;
}