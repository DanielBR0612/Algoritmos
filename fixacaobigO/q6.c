#include <stdio.h>

//O(logn)
int verifica(int vetor[], int v, int tamanho){
    int esquerda = 0, direita = tamanho - 1;
    
    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;

        if (vetor[meio] == v){
            return 1;
        }
        if (vetor[meio] < v){
            esquerda = meio + 1;
        }
        else{
            direita = meio - 1;
        }
    }

    return 0;
}


int main(){
    int vetor[] = {1,2,3,4,5,6,7,8,9,10};
    int v = 12;

    int r = verifica(vetor, v, sizeof(vetor)/sizeof(vetor[0]));

    if (r == 1){
        printf("Possui o valor");
    }
    else{
        printf("nao possui o valor");
    }
    
    return 0;
}