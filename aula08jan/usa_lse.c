#include "stdio.h"
#include "stdlib.h"
#include "lseneutra.h"

int* criar_int(int init){
    int* x =  malloc(sizeof(int));
    *x = init;
    return x; 
}

int main(){
    t_lse *nros = criar_lse();

    // povoando a lista
    int num;
    scanf("%d", &num);
    while(num>=0){
        inserir_final_lse(nros, criar_int(num));
        scanf("%d", &num);
    }

    //acessado a lista
    int pos;
    scanf("%d", &pos);
    while(pos>0){
        int *p = acessar_lse(nros,pos);
        printf("valor: %d na posicao: %d", *p, pos);
        scanf("%d", &pos);
    }
    // posicao
}