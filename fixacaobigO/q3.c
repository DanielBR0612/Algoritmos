#include <stdio.h>

void inserirOrdenado(int vetor[], int tamanho) {
    int aux = vetor[tamanho - 1];  
    int i = tamanho - 2;           

    while (i >= 0 && vetor[i] > aux) {
        vetor[i + 1] = vetor[i];    
        i--;                   
    }
    
    vetor[i + 1] = aux;
}

int main() {
    int vetor[11] = {1, 2, 3, 4,5, 6, 7, 9, 10, 8};  
    
    inserirOrdenado(vetor, 10);  

    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}
