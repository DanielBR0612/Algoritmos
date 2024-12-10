#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
    char nome[50];
    int idade;
    char tipoAtendimento[30];
    int preferencial; 
} Pessoa;

typedef struct Node {
    Pessoa pessoa;
    struct Node *proximo;
} Node;

typedef struct Fila {
    Node *inicio;
    Node *fim;
} Fila;


void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}


int filaVazia(Fila *fila) {
    return fila->inicio == NULL;
}


void inserirNaFila(Fila *fila, Pessoa pessoa) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->pessoa = pessoa;
    novo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}


Pessoa removerDaFila(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        Pessoa pessoaVazia = {"", 0, "", 0};
        return pessoaVazia;
    }

    Node *remover = fila->inicio;
    Pessoa pessoa = remover->pessoa;
    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(remover);
    return pessoa;
}


void listarFila(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }

    Node *atual = fila->inicio;
    while (atual != NULL) {
        printf("Nome: %s, Idade: %d, Tipo de Atendimento: %s, Preferencial: %s\n",
               atual->pessoa.nome, atual->pessoa.idade,
               atual->pessoa.tipoAtendimento,
               atual->pessoa.preferencial ? "Sim" : "Não");
        atual = atual->proximo;
    }
}


void atenderPessoa(Fila *filaPreferencial, Fila *filaNormal, int *alternarAtendimento) {
    if (*alternarAtendimento == 0 && !filaVazia(filaPreferencial)) {
        Pessoa atendida = removerDaFila(filaPreferencial);
        printf("Atendendo preferencial: %s\n", atendida.nome);
        *alternarAtendimento = 1; 
    } else if (!filaVazia(filaNormal)) {
        Pessoa atendida = removerDaFila(filaNormal);
        printf("Atendendo normal: %s\n", atendida.nome);
        *alternarAtendimento = 0; 
    } else if (!filaVazia(filaPreferencial)) {
        Pessoa atendida = removerDaFila(filaPreferencial);
        printf("Atendendo preferencial: %s\n", atendida.nome);
    } else {
        printf("Nenhuma pessoa para atender!\n");
    }
}

int main() {
    Fila filaPreferencial, filaNormal;
    int opcao, alternarAtendimento = 0;
    inicializarFila(&filaPreferencial);
    inicializarFila(&filaNormal);

    do {
        printf("\nMenu:\n");
        printf("1. Inserir na fila preferencial\n");
        printf("2. Inserir na fila normal\n");
        printf("3. Atender pessoa\n");
        printf("4. Listar fila preferencial\n");
        printf("5. Listar fila normal\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1: {
                Pessoa pessoa;
                printf("Nome: ");
                fgets(pessoa.nome, 50, stdin);
                pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0'; 
                printf("Idade: ");
                scanf("%d", &pessoa.idade);
                getchar();
                printf("Tipo de Atendimento (Idoso, Gestante, Deficiência): ");
                fgets(pessoa.tipoAtendimento, 30, stdin);
                pessoa.tipoAtendimento[strcspn(pessoa.tipoAtendimento, "\n")] = '\0';
                pessoa.preferencial = 1;
                inserirNaFila(&filaPreferencial, pessoa);
                break;
            }
            case 2: {
                Pessoa pessoa;
                printf("Nome: ");
                fgets(pessoa.nome, 50, stdin);
                pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0'; 
                printf("Idade: ");
                scanf("%d", &pessoa.idade);
                getchar();
                strcpy(pessoa.tipoAtendimento, "Normal");
                pessoa.preferencial = 0;
                inserirNaFila(&filaNormal, pessoa);
                break;
            }
            case 3:
                atenderPessoa(&filaPreferencial, &filaNormal, &alternarAtendimento);
                break;
            case 4:
                printf("Fila Preferencial:\n");
                listarFila(&filaPreferencial);
                break;
            case 5:
                printf("Fila Normal:\n");
                listarFila(&filaNormal);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}
