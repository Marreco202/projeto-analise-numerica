#ifndef MYVETOR_H
#define MYVETOR_H

// cria (aloca) um vetor de dimensão n, retornando seu ponteiro
double* myvet_cria (int n);

// libera (a memória) de um vetor previamente criado
void myvet_libera (double* v);

// calcula e retorna o produto escalar entre dois vetores de dimensão n
double myvet_escalar (int n, double* v, double* w);

// calcula e retorna a norma-2 de um vetor de dimensão n
double myvet_norma2 (int n, double* v);

// verifica se dois vetores double sao iguais elemento a elemento (sem sinal)
int myvet_iguais (int n, double* g, double* x, double tol);

// calcula a produto de um vetor v por um escalar s;
// o resultado deve ser armazenado no vetor w, previamente criado
void myvet_mults (int n, double* v, double s, double *w);

// imprime elementos do vetor
void myvet_imprime (int n, double* v);
#endif
