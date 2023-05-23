struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct hash Hash;

Hash* criaHash(int tamanho);
void liberaHash(Hash* ha);
int chaveDivisao(int chave,int TABLE_SIZE);
int chaveMultiplicaçao(int chave,int TABLE_SIZE);
int chaveDobra(int chave,int TABLE_SIZE);
int valorString(char *str);
int inesereHash_SemColisao(Hash *ha,struct aluno al);
int buscaHash_SemColisao(Hash *ha,int mat, struct aluno* al);
int sondagemLinear(int pos,int i, int TABLE_SIZE);
int sondagemQuadratica(int pos, int i, int TABLE_SIZE);
int duploHash(int H1,int chave,int i, int TABLE_SIZE);
int insereHash_EnderAberto(Hash *ha,struct aluno al);
int buscaHash_EnderAberto(Hash *ha, int mat, struct aluno*al);
 