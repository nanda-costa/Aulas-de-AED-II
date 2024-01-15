# include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "lseneutra.h"

typedef struct{
    char nome[60];
    int duracao;
    char genero[30];
} t_musica;

void imprimir_musica(void* m1){
    t_musica *m = m1;
    int min = m->duracao /60;
    int seg = m->duracao - min*60;
    printf("%s %02d:%02d\n ", m->nome, min, seg);
}

t_musica *criar_musica(char nome[], char genero[], int duracao){
    t_musica *nova = malloc(sizeof(t_musica));
    strcpy(nova->nome, nome);
    strcpy(nova->genero, genero);
    nova->duracao = duracao;

    return nova;
}

int comparar_musica(t_musica *m1, t_musica *m2){

    return strcmp(m1->nome, m2->nome); //ele retorna os valores referentes aos ifs abaixo, sem redundância.

    /*if(strcmp(m1->nome, m2->nome) == 0)
        return 0;
    else if ((strcmp(m1->nome, m2->nome) == 0) > 0 )
        return 1;
    else
        return -1;*/
}

int main(){
    char nome[60], genero[30];
    int duracao;
    t_lse *playlist = criar_lse(imprimir_lse, comparar_musica);
    scanf("%s", nome);

    while(strcmp(nome, "Fim") != 0){
        scanf("%s", genero);
        scanf("%d", &duracao);
        inserir_final_lse(playlist, criar_musica(nome, genero, duracao));

        scanf("%s", nome);
    }
    char buscado[60];
    scanf("%s", buscado);
    t_musica *m = buscar_lse(playlist, buscado);
    if(m!=NULL){
        imprimir_musica(m);
    }
    imprimir_musica(m);

}