#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "lseneutra.h"

#define PLAYING 1
#define PAUSE 2
#define STOP 3
#define LOAD 4
#define FINAL 5
#define RESUME 6
#define ADD_TO_PLAYLIST 7

typedef struct
{
    char nome[60];
    char genero[30];
    int duracao;
} t_musica;

void imprimir_musica(void *m1)
{
    t_musica *m = m1;
    int min = m->duracao / 60;
    int seg = m->duracao - min * 60;
    printf("%s %s %02d:%02d\n", m->nome, m->genero, min, seg);
}

t_musica *criar_musica(char nome[], char genero[], int duracao)
{
    t_musica *nova = malloc(sizeof(t_musica));

    strcpy(nova->nome, nome);
    strcpy(nova->genero, genero);
    nova->duracao = duracao;

    return nova;
}

int comparar_musica(void *m1, void *m2)
{

    t_musica* musica1 = (t_musica*)m1;
    t_musica* musica2 = (t_musica*)m2;
    return strcmp(musica1->nome, musica2->nome);

    // if (strcmp(m1->nome, m2->nome)==0)
    //     return 0;
    // else if (strcmp(m1->nome, m2->nome)>0)
    //     return 1;
    // else
    //     return -1;
}

typedef struct
{
    char nome[60];
    int duracao;
    char descricao[1000];
    int qtde;
    int data, mes, ano;
    t_lse *musicas; // Lista de músicas na playlist

} t_playlists;

typedef struct
{
    t_lse *musicas;   // Lista de todas as músicas na biblioteca
    t_lse *playlists; // Lista de playlists na biblioteca
} t_t_biblioteca;

typedef struct
{
    int status;
    t_musica *faixa_carregada;
    t_t_biblioteca *biblioteca;
    // biblioteca de músicas
} t_tocador;

// FUNÇÕES para maninipular músicas

void adicionar_musica(t_t_biblioteca *biblioteca, t_musica *musica)
{
    inserir_ordenado_lse(biblioteca->musicas, musica);
}

// Funções para maninipular playlists
t_playlists *criar_playlist(char nome[], char descricao[])
{
    t_playlists *nova = malloc(sizeof(t_playlists));
    strcpy(nova->nome, nome);
    strcpy(nova->descricao, descricao);
    nova->duracao = 0;
    nova->qtde = 0;
    nova->musicas = criar_lse(imprimir_musica, comparar_musica);
    return nova;
}

void adicionar_musica_na_playlist(t_playlists *playlist, t_musica *musica)
{
    inserir_ordenado_lse(playlist->musicas, musica);
    playlist->duracao += musica->duracao;
    playlist->qtde;
}

void adicionar_playlist(t_t_biblioteca *biblioteca, t_playlists *playlist)
{
    inserir_ordenado_lse(biblioteca->playlists, playlist);
}

void imprimir_playlist(t_playlists *playlist)
{
    printf("Playlista: %s(%d músicas, %d segundos de duração)\n", playlist->nome, playlist->qtde, playlist->duracao);
    imprimir_lse(playlist->musicas);
}

void imprimir_biblioteca(t_t_biblioteca *biblioteca)
{
    printf("Biblioteca: \n");
    imprimir_lse(biblioteca->musicas);

    printf("Playlist:\n");
    imprimir_lse(biblioteca->playlists);
}

t_tocador *criar_tocador()
{
    t_tocador *novo = malloc(sizeof(t_tocador));
    novo->status = STOP;
    novo->faixa_carregada = NULL;

    return novo;
}

void play_tocador(t_tocador *t)
{
    if (t->status == LOAD)
    {
        printf("Reproduzindo \n");
        imprimir_musica(t->faixa_carregada);
        t->status = PLAYING;
    }
}

void pause_tocador(t_tocador *t)
{
    if (t->status == PLAYING)
    {
        printf("Pausando!\n");
        imprimir_musica(t->faixa_carregada);
        t->status = PAUSE;
    }
}

void stop_tocador(t_tocador *t)
{
    if (t->status != STOP)
    {
        printf("Parando!\n");
        t->status = STOP;
    }
}

void loading_tocador(t_tocador *t)
{
    if (t->status == STOP)
    {
        t->faixa_carregada = malloc(sizeof(t_musica));
        scanf("%s", t->faixa_carregada->nome);
        scanf("%s", t->faixa_carregada->genero);
        scanf("%d", &(t->faixa_carregada->duracao));
        t->status = LOAD;
    }
}

void resume_tocador(t_tocador *t)
{
    if (t->status == PAUSE)
    {
        printf("Retomando a música!\n");
        imprimir_musica(t->faixa_carregada);
        t->status = PLAYING;
    }
}

int main()
{

    int acao;
    t_tocador *tocador = criar_tocador();
    do
    {
        scanf("%d", &acao);
        switch (acao)
        {
        case LOAD:
            loading_tocador(tocador);
            break;
        case PLAYING:
            play_tocador(tocador);
            break;
        case PAUSE:
            pause_tocador(tocador);
            break;
        case STOP:
            stop_tocador(tocador);
            break;
        case RESUME:
            resume_tocador(tocador);
            break;
        default:
            break;
        }

    } while (acao != FINAL);
}

//  char nome[60], genero[30];
//     int duracao;
//     t_lse *playlist = criar_lse(imprimir_musica, comparar_musica);
//     scanf("%s", nome);
//     while(strcmp(nome,"FIM")!=0){
//         scanf("%s", genero);
//         scanf("%d", &duracao);
//         inserir_ordenado_lse(playlist,criar_musica(nome,genero,duracao));
// //        inserir_final_lse(playlist, criar_musica(nome,genero,duracao));

//         scanf("%s", nome);
//     }
//     t_musica* buscado = malloc(sizeof(t_musica));

//     scanf("%s", buscado->nome);
//     t_musica* m = buscar_lse(playlist,(void*)buscado);
//     if (m!=NULL)
//         imprimir_musica(m);

//     imprimir_lse(playlist);