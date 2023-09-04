/**
 *	strlib: string library
 *	Uma biblioteca para manipulação de strings.
 *
 */
#include <stdlib.h>

#ifndef _strlib_
#define _strlib_

/**
 * @brief string length (tamanho da string) --- 0.5 pontos
 * @details função determina o tamanho da string passada como parâmetro
 * desconsiderando o caractere '\0', ou seja, ele não é contabilizado no
 * tamanho. se a string for nula, a função deve retornar -1. a função
 * assume que a string é bem formada, isto é, termina com o '\0'.
 *
 * @param str string para qual o tamanho deve ser computado
 * @return o tamanho da string ou -1 no caso de string nula
 */
int str_length();

/**
 * @brief string duplicate (duplica string) --- 0.5 pontos
 * @details a função duplica a string recebida como parâmetro. um novo
 * ponteiro é criado, memória para acomodar a cópia é alocada e o con-
 * teúdo de str é copiado para a nova região de memória criada. este
 * ponteiro é então retornado pela função.
 *
 * @param str a string a ser duplicada
 * @return ponteiro para a nova string que é uma cópia da original. caso
 * a string recebida como parâmetro seja nula a função retorna um pon-
 * teiro nulo.
 */
char *str_duplicate(const char *str);

/**
 * @brief string compare (compara strings) --- 0.5 pontos
 * @details compara duas strings com relação a seus caracteres. a função
 * assume (pré condição) que as duas strings passadas como parâmetro não
 * são nulas e não trata estes casos.
 *
 * @param stra uma string não nula devidamente formada (com \0 ao final)
 * @param strb uma string não nula devidamente formada (com \0 ao final)
 *
 * @return a função retorna: 0 caso as strings sejam lexicograficamente
 * iguais; -1 caso stra < strb; +1 caso stra > strb.
 */
int str_compare(const char *stra, const char *strb);

/**
 * @brief string revese (reverte string)  --- 1.0 pontos
 * @details reverte uma string
 *
 * @param str a string a ser revertida
 * @return retorna 1 caso consiga reverter a string e 0 caso contrário.
 * Note que é possível reverter uma string vazia (o resultado é ela mes-
 * ma), mas não é possível reverter uma string nula.
 */
int str_reverse(char *str);

/**
 * @brief string upper (string maiúsculas) --- 0.5 pontos
 * @details transforma todos caracteres alfabéticos da string para caixa
 * alta (maiúsculo). somente os caracteres alfabéticos são alterados.
 *
 * @param str a string que deve ser passada para caixa alta
 * @return o número de caracteres que foram transformados para caixa al-
 * ta. caso a string seja nula, retorna -1.
 */
int str_upper(char *str);

/**
 * @brief string lower (string minúsculas) --- 0.5 pontos
 * @details transforma todos caracteres alfabéticos da string para caixa
 * baixa (minúsculo). somente os caracteres alfabéticos são alterados.
 *
 * @param str a string que deve ser passada para caixa baixa
 * @return o número de caracteres que foram transformados para caixa
 * baixa. caso a string seja nula, retorna -1.
 */
int str_lower(char *str);

/**
 * @brief string copy (copia string)  --- 1.0 pontos
 * @details copia o conteúdo da string src (source - fonte) para a
 * string dst (destination - destino), incluindo o caractere \0. Todo o
 * conteúdo da string dst será perdido. antes de realizar a cópia, a
 * função verifica se a string dst possui tamanho suficiente para acomo-
 * dar a string src. ou seja, o número de caracteres de dst inlcuindo \0
 * deve ser maior ou igual que o número de caracteres de src (incluindo
 * o caractere \0). caso dst seja menor que src a cópia não é realizada.
 *
 * @param dst string que conterá a cópia
 * @param src string a ser copiada
 *
 * @return retorna 1 caso a cópia seja feita, 0 caso não seja possível
 * copiar (restrições de tamanho) e -1 caso src ou dst sejam nulas.
 */
int str_copy(char *dst, const char *src);


/**
 * @brief string contatenate (contatena strings)  --- 1.5 pontos
 * @details contatena stra e strb em uma nova string, alocada pela fun-
 * ção. o ponteiro desta nova string é retornado pela função.
 * 
 * @param stra primeira string
 * @param strb segunda string
 * 
 * @return a concatenação das strings stra e strb. caso as duas sejam 
 * não nulas, retorna a concatenação. caso uma das strings seja nula, 
 * uma nova string deve ser alocada e uma cópia da string não nula é
 * retornada. caso stra e strb sejam nulas, um ponteiro nulo é retorna-
 * do pela função.
 */
char* 	str_concatenate (const char *stra, const char *strb);

/**
 * @brief string find first (encontra primeira ocorrência) --- 1.0 pontos
 * @details encontra a primeira ocorrência do caractere c em str
 * 
 * @param str a string na qual o caractere será procurado
 * @param c o caractere a ser buscado
 * 
 * @return retorna a posição da primeira ocorrência do caractere c na 
 * string str. caso o caractere não seja encontrado ou str seja nula
 * a função retorna -1.
 */
int 	str_find_first	(const char *str, const char c);

/**
 * @brief string find last (encontra última ocorrência)  --- 1.0 pontos
 * @details encontra a última ocorrência do caractere c em str
 * 
 * @param str a string na qual o caractere será procurado
 * @param c o caractere a ser buscado
 * 
 * @return retorna a posição da última ocorrência do caractere c na 
 * string str. caso o caractere não seja encontrado ou str seja nula
 * a função retorna -1.
 */
int 	str_find_last 	(const char *str, const char c);

/**
 * @brief string count words (conta palavras)  --- 2.0 pontos
 * @details conta o número de palavras em uma string
 * 
 * @param str a string para a qual a contagem será realizada
 * @return retorna o número de palavras da string. uma palavra é defini-
 * da como uma região de caracteres (quaisquer caracteres) separada por 
 * um ou mais espaços, ex: "   o gato preto cruzou a   estrada" possui
 * seis palavras. retorna -1 caso str seja nula.
 */
int 	str_count_words (const char *str);
#endif