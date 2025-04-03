#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

void inserir_no_inicio(No **lista, int numero){
    No *novo = (No*)malloc(sizeof(No));
    if(novo){
        novo->valor = numero;
        novo->prox = *lista;
        *lista = novo;
    }
    else
        printf("Erro de alocação\n");
}

void inserir_no_final(No **lista, int numero){
    No *novo = (No*)malloc(sizeof(No));

    if(novo){
        novo->valor = numero;
        novo->prox = NULL;

        if(*lista == NULL)
            *lista = novo;
        else{
            No *aux = *lista;
            while(aux->prox)
                aux = aux->prox;
            aux->prox = novo;
        } 
    }
    else
        printf("Erro de alocação\n");
}

void inserir_no_meio(No **lista, int numero, int ant){
    No *novo = (No*)malloc(sizeof(No));
    if(novo){
        novo->valor = numero;

        if(*lista == NULL){
            novo->prox = NULL;
            *lista = novo;
        }
        else{
            No *aux = *lista;
            while(aux->valor != ant && aux->prox){
                aux = aux->prox;
            }

            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
    else
        printf("Erro de alocação\n");
}

int main(){
    No *lista = NULL;
    inserir_no_inicio(&lista, 10);
    inserir_no_inicio(&lista, 20);
    inserir_no_inicio(&lista, 30);
    inserir_no_inicio(&lista, 40);
    inserir_no_inicio(&lista, 50);

    printf("Lista após inserção no início:\n");
    No *aux = lista;
    while(aux){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
    inserir_no_final(&lista, 60);
    printf("Lista após inserção no final:\n");
    aux = lista;
    while(aux){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
    inserir_no_meio(&lista, 70, 30);
    printf("Lista após inserção no meio:\n");
    aux = lista;
    while(aux){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    return 0;
}