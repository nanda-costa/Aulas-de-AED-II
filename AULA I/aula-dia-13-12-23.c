#include <stdio.h>
#include <stdlib.h>

typedef struct NO { /*estrutura do tipo nó que contém um dado inteiro e uma
                       ponteiro do tipo no.*/
  int dado;
  struct no *prox;
} NO;

typedef struct FILA { /*criação da estrutura fila, com dois ponteiros do tipo
                         nó*/
  NO *ini;
  NO *fim;
} FILA;

void inicializaFila(FILA *f) { /*inicializa a fila com NULL.*/
  f->ini = NULL;
  f->fim = NULL;
}

void enfileira(int dado, FILA *f) { /*Função que enfileira*/
  NO *ptr = (NO *)malloc(sizeof(NO));
  if (ptr == NULL) {
    printf("\nERRO DE ALOCACAO DE MEMORIA!\n");
    return;
  } else {
    ptr->dado = dado;
    ptr->prox = NULL;
    if (f->ini == NULL) {
      f->ini = ptr;
    } else {
      f->fim->prox = ptr;
    }
    f->fim = ptr;
  }
}

int desifileira(FILA *f) {
  NO *ptr = f->ini;
  int dado;
  if (ptr != NULL) {
    f->ini = ptr->prox; // guardando o endereço de memória do próximo nó ptr;
    ptr->prox = NULL;
    dado = ptr->dado;
    free(ptr);
    if (f->ini == NULL) {
      f->fim = NULL;
    }
    return dado;
  } else {
    printf("\nlista vazia!\n");
    return;
  }
}

void imprimirFila(FILA *f) { /*Função que imprime uma fila.*/
  NO *ptr = f->ini;
  if (ptr != NULL) {
    while (ptr != NULL) {
      printf("%d ", ptr->dado);
      ptr = ptr->prox;
    }
  } else {
    printf("\nERRO DE ALOCACAO!\n");
  }
  printf("\n");
}

int main() {
  FILA *f1 = (FILA *)malloc(sizeof(FILA));
  if (f1 == NULL) {
    printf("\nERRO DE ALOCACAO!\n");
  } else {
    inicializaFila(f1);
    enfileira(7, f1);
    enfileira(55, f1);
    enfileira(100, f1);
  }
  imprimirFila(f1);
  desifileira(f1);
  imprimirFila(f1);
}