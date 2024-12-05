#include <stdio.h>

struct Contato {
    char nome[50];
    char telefone[15];
};

int menu(){
    int op = 0;
        printf("Digite a opcao: ");
        printf("1 - Inserir  2 - Listar  3 - Deletar  4 - Atualizar  0 - Sair\n");
        scanf("%d", &op);

        return op;
}

int main() {
    struct Contato agenda[100];
    int num_contatos;

    int op = menu();

    while (op != 0){
        if (op == 1){
                printf("Digite o número de contatos: ");
                scanf("%d", &num_contatos);

            for (int i = 0; i < num_contatos; i++) {
                printf("Digite o nome do contato %d: ", i + 1);
                scanf("%s", agenda[i].nome);

                printf("Digite o telefone do contato %d: ", i + 1);
                scanf("%s", agenda[i].telefone);
            }
            
            op = menu();
        }
        if (op == 2){
            printf("Contatos:\n");

            for (int i = 0; i < num_contatos; i++) {
                printf("Nome: %s\n", agenda[i].nome);
                printf("Telefone: %s\n", agenda[i].telefone);
            }  
            op = menu();  
        }
        if (op == 3){

        }
    }


    return 0;
}