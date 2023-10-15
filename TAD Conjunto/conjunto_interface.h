#ifndef conjunto_interface_h
#define conjunto_interface_h

typedef struct conjunto conjunto_t;
typedef int elem_t;

/*
 * Retorna um ponteiro para conjunto recem criado com espaco para armazenar inicialmente 10 elementos
 * Pre-condicao: o sistema deve ter memoria para alocar o novo conjunto
 * Pos-condicao: o novo conjunto eh retornado
 */
conjunto_t *conjunto_cria(void);

/*
 * Destroi o conjunto "a"
 * Pre-condicao: o conjunto "a" deve ter sido previamente criado com a operacao "cria_conjunto"
 * Pos-condicao: o conjunto passado por parametro nao eh mais valido, nao podera mais ser utilizado e devera apontar para NULL
 */
void conjunto_destroi(conjunto_t **a);

/*
 * Retorna o numero de elementos que estao no conjunto "a"
 * Pre-condicao: o conjunto "a" deve ter sido previamente criado com a operacao "cria_conjunto"
 * Pos-condicao: 
 */
int conjunto_numero_elementos(conjunto_t *a);

/*
 * Recebe um conjunto como parametro e o inicializa como conjunto vazio
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o conjunto "a" passara a ser um conjunto vazio
 */
void conjunto_inicializa_vazio(conjunto_t *a);

/*
 * Recebe os conjuntos "a e "b" e retorna a uniao entre eles no conjunto "c"
 * Pre-condicao: os conjuntos "a", "b" e "c" devem ser conjuntos validos
 * Pos-condicao: o conjunto "c" contera a uniao entre os conjuntos "a" e "b"
 */
void conjunto_uniao(conjunto_t *a, conjunto_t *b, conjunto_t *c);

/*
 * Recebe os conjuntos "a e "b" e retorna a interseccao entre eles no conjunto "c"
 * Pre-condicao: os conjuntos "a", "b" e "c" devem ser conjuntos validos
 * Pos-condicao: o conjunto "c" contera a interseccao entre os conjuntos "a" e "b"
 */
void conjunto_interseccao(conjunto_t *a, conjunto_t *b, conjunto_t *c);

/*
 * Recebe os conjuntos "a" e "b" e retorna a diferenca entre eles no conjunto "c"
 * Pre-condicao: os conjuntos "a", "b" e "c" devem ser conjuntos validos, criados pela operacao "cria_conjunto"
 * Pos-condicao: o conjunto "c" contera a diferenca entre os conjuntos "a" e "b"
 */
void conjunto_diferenca(conjunto_t *a, conjunto_t *b, conjunto_t *c);

/*
 * Retorna 1 se o elemento "x" pertence ao conjunto "a", 0 caso contrario
 * Pre-condicao: o conjunto A deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o valor retornado sera 0 ou 1
 */
int conjunto_membro(elem_t x, conjunto_t *a);

/*
 * Insere o elemento "x" no conjunto "a". Se "x" ja pertencer a "a" nao faz nada (retorna 1 nesse caso). Retorna 1 caso inseriu corretamente, 0 caso contrario.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o elemento "x" passara a pertencer ao conjunto "a"
 */
int conjunto_insere_elemento(elem_t x, conjunto_t *a);

/*
 * Remove o elemento "x" no conjunto "a". Se "x" nao pertencer a "a", nao faz nada
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: o conjunto "a" passara a nao ter mais o elemento "x"
 */
void conjunto_remove_elemento(elem_t x, conjunto_t *a);

/*
 * Atribui o conjunto "a" ao "b" (b = a)
 * Pre-condicao: os conjuntos "a" e "b" devem ser conjuntos criados previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
void conjunto_atribui(conjunto_t *a, conjunto_t *b);

/*
 * Retorna 1 caso o conjunto "a" seja igual ao conjunto "b", 0 caso contrario
 * Pre-condicao: os conjuntos "a" e "b" devem ser conjuntos criados previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
int conjunto_igual(conjunto_t *a, conjunto_t *b);

/*
  * Retorna o valor minimo dentro do conjunto "a", retorne ELEM_MAX caso erro.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
elem_t conjunto_minimo(conjunto_t *a);

/*
 * Retorna o valor maximo dentro do conjunto "a", retorne ELEM_MIN caso erro.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
elem_t conjunto_maximo(conjunto_t *a);

/*
 * Imprime o conjunto "a", sendo os elementos separados por espaço. Se for o ultimo elemento, nao deve ser impresso o ultimo espaco. Quebra de linha no final.
 * Pre-condicao: o conjunto "a" deve ser um conjunto criado previamente pela operacao "cria_conjunto"
 * Pos-condicao: 
 */
void conjunto_imprime(conjunto_t *a);

#endif

