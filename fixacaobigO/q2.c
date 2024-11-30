#include <stdio.h>

int verificaOrdenado(int vetor[]){
    int qtd = 0;
    for(int i = 0; i < 10; i++){
        if (vetor[i] < vetor[i+1]){
            qtd = qtd + 1;
        }
    }
    if(qtd == 9){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int r = verificaOrdenado(vetor);

    if (r == 1){
        printf("Desordenada");
    }
    else{
        printf("Ordenada");
    }

    return 0;
}