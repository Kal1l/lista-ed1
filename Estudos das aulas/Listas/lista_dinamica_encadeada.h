struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista*li);
int busca_lista_pos(Lista*li,int pos, struct aluno* al);
int busca_lista_mat(Lista*li,int mat, struct aluno* al);
int insere_lista_inicio(Lista*li,struct aluno al);
int insere_lista_final(Lista*li,struct aluno al);
int insere_lista_ordenada(Lista*li,struct aluno al);
int remove_lista(Lista*li,int mat);
int remove_lista_inicio(Lista*li);
int remove_lista_final(Lista*li);
int tamanho_lista(Lista*li);

