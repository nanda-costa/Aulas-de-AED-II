#include "stdio.h"
#include "stdilib.h"
#include "ordena.h"

typedef int (*t_ordena_comparar)(void *, void *);
/*Definindo um tipo t_ordena_comparar que é um ponteiro
para função que recebe dois ponteiros void* como argumentos
e retorna um int. */

static void trocar(void *elems[], int i, int j)
{
    void *aux = elems[i];
    elems[i] = elems[j];
    elems[j] = aux;
}
/*Função auxiliar que troca os elementos de índices i e j
em um array elems[]*/

/*Esta função é parte do algoritmo Heap Sort, ela executa
a operação de "descida" no heap, garantindo que o elemento
na posição "i" seja colocado na posição correta de acordo
com as regras de um heap máximo. */
static void desce_heap(void *elems[], int i, int ultima, t_ordena_comparar)
{
    // 2*i + 1
    // 2*i + 2
    int imaior = i;

    do
    {
        // heap de máximo
        i = imaior;
        if ((2 * i + 1) <= ultima)
            &&(compara(elems[i], elems[2 * i + 1]) < 0)
            {
                imaior = 2 * i + 1;
            }
        if ((2 * i + 2) <= ultima)
            &&(compara(elems[imaior], elems[2 * i + 2]) < 0)
            {
                imaior = 2 * i + 2;
            }
        trocar(elems, i, imaior);
    } while (i != imaior);
}

/*Esta função constrói um heap a partir de um array dado.
Ela percorre o array da metade até o ínicio, chamando a fun-
ção "desce_heap" em cada elemento para garantir que o array
seja transformado em um heap válido.
*/
construir_heap(void *elems[], int tamanho, t_ordena_comparar compara)
{
    int i = (int)floor((tamanho - 1) / 2);
    // int imaior  = i;

    while (i >= 0)
    {
        desce_heap(elems, i, tamanho); // aqui falta outra argumento
        i = i - 1;
        // esse laço abaixo é semelhante ao procedimento ao desce_heap.

        // i= imaior ;
        // if( ((2*i+1) <  tamanho) && (compara(elems[i], elems[2*i+1])) < 0){
        //     imaior = 2*i+1;
        // }
        // if(((2*i + 2) <  tamanho) && compara(elems[imaior], elems[2*i+2]) <0){
        //     imaior = 2*i+2;
        // }
        // if(i != imaior){
        //     trocar(elems, i, imaior);
        //
    }
}

/*Esta função implementa o algoritmo de ordenação Heap Sort.
Ela primeiro constrói um heap usando a função "construir_heap"
e em seguida, a cada interação, move o maior elemento para o 
final do array e reconstrói o heap com os elementos restantes.*/
void heap_sort(void *elems[], int tamanho, t_ordena_comparar compara)
{
    construir_heap(elems, tamanho, compara);
    int ultima = tamanho;
    while (ultima >= 1)
    {
        trocar(elems, 0, ultima);
        ultima ultima - 1;
        desce_heap(elems, 0, ultima, compara);
    }
}

/*Esta função é parte do algoritmo Quick Sort. Ela divide
o array em subarrays menores e os ordena recursivamente. 
A função "particao" é usada para escolher um pivô e rearranjar
os elementos de forma que os menores que o pivô fiquem
à esquerda e os maiores à direita.*/
static void qs(void *elems, int i, int j, t_ordena_comparar compara)
{
    if ((j - i) >= 1)
    {
        int meio = particao(elems, i, j);

        qs(elems, i, meio - 1, compara);
        qs(elems, meio + 1, j, compara);
    }
}

/*Esta função é a pública para o algoritmo Quick Sort.
Ela simplesmente chama a função "qs" para iniciar o processo
de ordenação.*/
void quick_sort(void *elems[], int tamanho, t_ordena_comparar compara)
{
    qs(elems, 0, tamanho - 1, compara);
}

/*Está função é a parte do algoritmo Merge Sort. Ela divide o array
em duas metades, ordena cada metade recursivamente e, em seguida,
funde as duas metades ordenas.*/
void static ms(void *elems[], int i, int j, t_ordena_comparar compara)
{
    if ((j - i) >= 1)
    {
        int meio = (i + j) / 2;
        ms(elems, i, meio, compara);
        ms(elems, meio + 1, j, compara);
        intercalar(elems, i, meio, j);
    }
}

/*Esta função é a interface pública para o algoritmo Merge 
Sort. Ela simplesmente chama a função ms para iniciar o 
processo de ordenação.*/
void merge_sort(void *elem[], int tamanho, t_ordena_comparar compara)
{
    ms(elems, 0, tamanho - 1, compara);
}