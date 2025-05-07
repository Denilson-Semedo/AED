#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void inserir_no_inicio(No **lista, int numero) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->valor = numero;
        novo->prox = *lista;
        *lista = novo;
    } else {
        printf("Erro de alocação\n");
    }
}

void inserir_no_final(No **lista, int numero) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->valor = numero;
        novo->prox = NULL;

        if (*lista == NULL)
            *lista = novo;
        else {
            No *aux = *lista;
            while (aux->prox)
                aux = aux->prox;
            aux->prox = novo;
        }
    } else {
        printf("Erro de alocação\n");
    }
}

void inserir_no_meio(No **lista, int numero, int ant) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo) {
        novo->valor = numero;

        if (*lista == NULL) {
            novo->prox = NULL;
            *lista = novo;
        } else {
            No *aux = *lista;
            while (aux->valor != ant && aux->prox) {
                aux = aux->prox;
            }

            if (aux->valor == ant) {
                novo->prox = aux->prox;
                aux->prox = novo;
            } else {
                printf("Valor anterior não encontrado\n");
                free(novo);
            }
        }
    } else {
        printf("Erro de alocação\n");
    }
}

void remover_do_inicio(No **lista) {
    if (*lista) {
        No *aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    } else {
        printf("Lista vazia\n");
    }
}

void remover_do_final(No **lista) {
    if (*lista) {
        No *aux = *lista;
        No *prev = NULL;
        while (aux->prox) {
            prev = aux;
            aux = aux->prox;
        }
        if (prev) {
            prev->prox = NULL;
        } else {
            *lista = NULL;
        }
        free(aux);
    } else {
        printf("Lista vazia\n");
    }
}

void remover_do_meio(No **lista, int numero) {
    if (*lista) {
        No *aux = *lista;
        No *prev = NULL;
        while (aux && aux->valor != numero) {
            prev = aux;
            aux = aux->prox;
        }

        if (aux) {
            if (prev) {
                prev->prox = aux->prox;
            } else {
                *lista = aux->prox;
            }
            free(aux);
        } else {
            printf("Valor não encontrado\n");
        }
    } else {
        printf("Lista vazia\n");
    }
}

void remover_numero(No **lista, int numero) {
    if (*lista) {
        No *aux = *lista;
        No *prev = NULL;
        
        // Caso a lista tenha o primeiro elemento a ser removido
        if (aux->valor == numero) {
            *lista = aux->prox; // Atualiza a cabeça da lista
            free(aux); // Libera a memória do nó removido
            return;
        }
        
        // Percorre a lista procurando pelo número
        while (aux && aux->valor != numero) {
            prev = aux;
            aux = aux->prox;
        }

        // Se o número foi encontrado, remove o nó
        if (aux) {
            prev->prox = aux->prox; // Atualiza o ponteiro do nó anterior
            free(aux); // Libera a memória do nó removido
        } else {
            printf("Valor %d não encontrado na lista.\n", numero);
        }
    } else {
        printf("Lista vazia.\n");
    }
}

void exibir_lista(No *lista) {
    if (lista) {
        No *aux = lista;
        while (aux) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    } else {
        printf("Lista vazia\n");
    }
}

int main() {
    No *lista = NULL;
    int opcao, numero, ant;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no final\n");
        printf("3. Inserir no meio\n");
        printf("4. Remover do início\n");
        printf("5. Remover do final\n");
        printf("6. Remover do meio\n");
        printf("7. Remover\n");
        printf("8. Exibir lista\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o número para inserir no início: ");
                scanf("%d", &numero);
                inserir_no_inicio(&lista, numero);
                break;
            case 2:
                printf("Digite o número para inserir no final: ");
                scanf("%d", &numero);
                inserir_no_final(&lista, numero);
                break;
            case 3:
                printf("Digite o número para inserir no meio: ");
                scanf("%d", &numero);
                printf("Digite o valor anterior para inserir após: ");
                scanf("%d", &ant);
                inserir_no_meio(&lista, numero, ant);
                break;
            case 4:
                remover_do_inicio(&lista);
                break;
            case 5:
                remover_do_final(&lista);
                break;
            case 6:
                printf("Digite o número para remover do meio: ");
                scanf("%d", &numero);
                remover_do_meio(&lista, numero);
                break;
            case 7:
                printf("Digite o número para ser removido: ");
                scanf("%d", &numero);
                remover_numero(&lista, numero);
                break;
            case 8:
                printf("Lista atual: ");
                exibir_lista(lista);
                break;
            case 9:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}