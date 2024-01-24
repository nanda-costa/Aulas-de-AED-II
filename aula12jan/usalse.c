#include "stdio.h"
#include "stdlib.h"
#include "lseneutra.h"

typedef struct{
    int a;
    double b;
} t_composto;

t_composto* criar_composto(int a, double b){
    t_composto* c = malloc(sizeof(t_composto));
    c->a = a;
    c->b = b;

    return c;
}

void imprimir_composto(t_composto *c){
    printf("a: %d b: %lf\n", c->a, c->b);
}

int* criar_int(int init){
    int* x = malloc(sizeof(int));
    *x = init;
    return x;
}

void imprimir_int(int* nro){
    printf("%d\n", *nro);
}


/*int main(){
    t_lse* nros = criar_lse(imprimir_int);
    
    t_lse* dos_composto = criar_lse(imprimir_composto);

    // povoando a lista
    // int num;
    // scanf("%d", &num);
    // while(num>=0){
    //     inserir_final_lse(nros, criar_int(num));
    //     scanf("%d", &num);
    // }

    int a;
    double b;
    scanf("%d %lf", &a, &b);
    while(a>=0){
        inserir_final_lse(nros, criar_composto(a,b));
        scanf("%d %lf", &a, &b);
    }

    //acessado a lista
    // int pos;
    // scanf("%d", &pos);
    // while(pos>0){
    //     int *p = acessar_lse(nros,pos);
    //     printf("valor: %d na posicao: %d\n", *p, pos);
    //     scanf("%d", &pos);
    // }

    // imprimir
    //imprimir_lse(nros);

    imprimir_lse(dos_composto);

    // posicao
}*/