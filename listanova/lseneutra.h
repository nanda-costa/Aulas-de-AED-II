typedef struct lse t_lse;
typedef void(*t_imprimir_lse)(void*);
typedef int(*t_comparar_lse)(void*, void*);


t_lse* criar_lse(t_imprimir_lse impressora, t_comparar_lse comparador);
void imprimir_lse(t_lse* lse);

void inserir_lse(t_lse* lse, void* carga_util);
void inserir_final_lse(t_lse* lse, void* carga_util);
void inserir_ordenado_lse(t_lse* lse, void* carga_util);

void* remover_inicio_lse(t_lse* lse);
void* remover_final_lse(t_lse* lse);

void* acessar_lse(t_lse* lse, int pos);
void* buscar_lse(t_lse *lse, void* buscado);

void destruir_lse(t_lse* lse);

//void imprimir_inicio_lista(t_lse* lse);