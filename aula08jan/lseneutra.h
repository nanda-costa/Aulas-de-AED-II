typedef struct lse t_lse;
void inserir_lse(t_lse* lse, void* carga_util);
void inserir_final_lse(t_lse* lse, void* carga_util);
void* acessar_lse(t_lse* lse, int pos);
void destruir_lse(t_lse* lse);
t_lse* criar_lse();