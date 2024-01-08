#include "stdio.h"
#include "stdlib.h"

void trocar(void **abacate, void **bolo){
    void *aux=*abacate;
    *abacate=*bolo;
    *bolo = aux;
    printf("%p %p\n", abacate, bolo);
}
double* criar_double(double init){
    double* x = malloc(sizeof(double));
    *x = init;
    return x;
}

int* criar_int(int init){
    int* x = malloc(sizeof(int));
    *x = init;
    return x;
}

typedef struct{
    int a,b;
    double x,y;
}t_composto;

t_composto* criar_composto(int a, int b, double x, double y){
    t_composto* c = malloc(sizeof(t_composto));
    c->a = a;
    c->b = b;
    c->x = x;
    c->y = y;

    return c;
}

int main(){
    double* a=criar_double(10);
    double* b=criar_double(20);
    int *x=criar_int(20);
    int *y=criar_int(30);
    t_composto *c1 = criar_composto(100,200,15.99,25.90);
    t_composto *c2 = criar_composto(1000,34,199.99, 345.99);

    // scanf("%d", &a);
    // scanf("%d",&b);

    printf("%lf %lf\n", *a, *b);
    printf("%d %d\n", *x, *y);
    printf("%d %lf\n", c1->a, c1->x);
    trocar(&x, &y);
    trocar(&a, (void**)&b);
    trocar(&c1, &c2);
    printf("%lf %lf\n", *a, *b);
    printf("%d %d\n", *x, *y);
    printf("%d %lf\n", c1->a, c1->x);

}