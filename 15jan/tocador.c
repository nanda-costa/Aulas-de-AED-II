#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "lseneutra.h"

typedef struct {
    char nome[60];
    char genero[30];
    int duracao;
} t_musica;

void imprimir_musica(void* m1){
    t_musica *m = m1;
    int min = m->duracao / 60;
    int seg = m->duracao - min*60;
    printf("%s %s %02d:%02d\n", m->nome, m->genero, min, seg);
    
}

t_musica* criar_musica(char nome[], char genero[], int duracao){
    t_musica *nova = malloc(sizeof(t_musica));
    
    strcpy(nova->nome, nome);
    strcpy(nova->genero, genero);
    nova->duracao = duracao;

    return nova;
}

int comparar_musica(void* m1, void* m2){
    t_musica *mm1 = mm1;
    t_musica *mm2 = mm2;
    return strcmp(mm1->nome, mm2->nome);

    // if (strcmp(m1->nome, m2->nome)==0)
    //     return 0;
    // else if (strcmp(m1->nome, m2->nome)>0)
    //     return 1;
    // else
    //     return -1;
}

int main(){
    char nome[60], genero[30];
    int duracao;
    t_lse *playlist = criar_lse(imprimir_musica, comparar_musica);
    scanf("%s", nome);
    while(strcmp(nome,"FIM")!=0){
        scanf("%s", genero);
        scanf("%d", &duracao);
        inserir_ordenado_lse(playlist, criar_musica(nome,genero,duracao));
        //inserir_final_lse(playlist, criar_musica(nome,genero,duracao));

        scanf("%s", nome);
    }
    t_musica* buscado = malloc(sizeof(t_musica));
    //char buscado[60];
    
    scanf("%s", buscado->nome);
    t_musica* m = buscar_lse(playlist,(void*)buscado);
    if (m!=NULL)
        imprimir_musica(m);

    //imprimir_lse(playlist);

}