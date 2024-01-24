#include "stdio.h"
#include "stdlib.h"

/*void troca_double(double *a, double *b){
    double aux = *a;
    *a = *b;
    *b = aux;
    printf("%p %p\n", a, b); //imprime o endereço de memória
}*/

void troca(void **a, void **b){
   void *aux = *a;
    *a = *b;
    *b = aux;
    printf("%p %p\n", a, b); //imprime o endereço de memória
}

double* criar_double(double init){
    double* x = malloc(sizeof(double));
    *x =init;
    return x;
}
int* criar_int(int init){
    int* x = malloc(sizeof(int));
    *x = init;
    return x;
}

typedef struct{
    int a,b;
    double x, y;
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
    double* num1 = criar_double(10), *num2 = criar_double(20);
    int *x= criar_int(20);
    int *y= criar_int(30);

    t_composto *c1 = criar_composto(100, 200, 15.99);
    t_composto *c2 = criar_composto(1000, 34, 99, 345.99);

    printf("%lf %lf\n", *num1,*num2);
    printf("%d %d\n", *x,*y);
    printf("%d %lf\n", c1->a, c1);4
    troca(&x, &y);
    troca((void**)&num1, (void**)&num2);
    printf("%d %d\n", *x,*y);

   
}