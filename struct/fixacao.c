#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pessoa {
    char nome[50];
    int idade;
    char tipoAtendimento[30];
    int preferencial; // 1 para preferencial, 0 para normal
} Pessoa;

typedef struct Fila {
    Pessoa pessoa;
    struct Fila *proximo;
} Fila;

// Inicializar a fila
Fila *inicializarFila() {
    return NULL;
}

// Verificar se a fila está vazia
int filaVazia(Fila *fila) {
    return fila == NULL;
}

// Inserir uma pessoa na fila
void inserirNaFila(Fila **fila, Pessoa pessoa) {
    Fila *novo = (Fila *)malloc(sizeof(Fila));
    if (!novo) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    novo->pessoa = pessoa;
    novo->proximo = NULL;

    if (*fila == NULL) {
        *fila = novo;
    } else {
        Fila *atual = *fila;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

// Remover uma pessoa da fila
Pessoa removerDaFila(Fila **fila) {
    Pessoa pessoaVazia = {"", 0, "", 0};

    if (filaVazia(*fila)) {
        printf("Fila vazia!\n");
        return pessoaVazia;
    }

    Fila *remover = *fila;
    Pessoa pessoa = remover->pessoa;
    *fila = remover->proximo;
    free(remover);

    return pessoa;
}

// Listar as pessoas na fila
void listarFila(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        return;
    }

    Fila *atual = fila;
    while (atual != NULL) {
        Pessoa p = atual->pessoa;
        printf("Nome: %s, Idade: %d, Tipo de Atendimento: %s, Preferencial: %s\n",
               p.nome, p.idade, p.tipoAtendimento, p.preferencial ? "Sim" : "Não");
        atual = atual->proximo;
    }
}

// Atender uma pessoa com base nas regras
void atenderPessoa(Fila **filaPreferencial, Fila **filaNormal, int *alternarAtendimento) {
    if (*alternarAtendimento == 0 && !filaVazia(*filaPreferencial)) {
        Pessoa atendida = removerDaFila(filaPreferencial);
        printf("Atendendo preferencial: %s\n", atendida.nome);
        *alternarAtendimento = 1; // Alterna para atendimento normal
    } else if (!filaVazia(*filaNormal)) {
        Pessoa atendida = removerDaFila(filaNormal);
        printf("Atendendo normal: %s\n", atendida.nome);
        *alternarAtendimento = 0; // Alterna para atendimento preferencial
    } else if (!filaVazia(*filaPreferencial)) {
        Pessoa atendida = removerDaFila(filaPreferencial);
        printf("Atendendo preferencial: %s\n", atendida.nome);
    } else {
        printf("Nenhuma pessoa para atender!\n");
    }
}

int main() {
    Fila *filaPreferencial = inicializarFila();
    Fila *filaNormal = inicializarFila();
    int opcao, alternarAtendimento = 0;

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
        getchar(); // Limpar buffer

        switch (opcao) {
            case 1: {
                Pessoa pessoa;
                printf("Nome: ");
                fgets(pessoa.nome, 50, stdin);
                pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0'; // Remover o '\n'
                printf("Idade: ");
                scanf("%d", &pessoa.idade);
                getchar();
                printf("Tipo de Atendimento (Gestante, Lactante, Deficiência): ");
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
                pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0'; // Remover o '\n'
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
                listarFila(filaPreferencial);
                break;
            case 5:
                printf("Fila Normal:\n");
                listarFila(filaNormal);
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
