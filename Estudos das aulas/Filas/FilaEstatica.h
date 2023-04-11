#define MAX 100
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila*li);
int consulta_Fila(Fila*li,int pos, struct aluno* al);
int insere_Fila(Fila*li,struct aluno al);
int remove_Fila(Fila*li);
int tamanho_Fila(Fila*li);