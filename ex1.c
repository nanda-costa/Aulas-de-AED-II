#include <stdio.h>
#include <stdlib.h>

/*typedef struct elem_lse t_elem_lse;
typedef struct{
    //end, do primeiro elemento
    t_elemento_lse* primeiro;

// end. do último elemento
t_elem_lse* ultimo;
//tamanho da lista
int tamanho;
}t_lse*/

typedef struct elem_se{
    int carga_util;
    struct elem_se* prox;
}t_elemento_lse;

//typedef struct lse t_lse; Outra forma de definir uma estrutura.

typedef struct lse{
    t_elemento_lse* inicio;
    t_elemento_lse* fim;
    int tamanho;
}t_lse;

t_elemento_lse* criar_elemento_lse(int carga_util){
    t_elemento_lse* novo = malloc(sizeof(t_elemento_lse));
    novo->carga_util = carga_util;
    novo->prox = NULL;

    //printf("Criando: %p %p %p\n", novo, novo->carga_util, novo->prox);

    return novo;
}
t_lse* criar_lse(){
    t_lse *l = malloc(sizeof(t_lse));
    l->inicio = l->fim = NULL;
    l->tamanho = 0;

    return l;
}

int main(){}
