#include "myvetor.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double* myvet_cria (int n)
{
  double* v = (double*)malloc(n*sizeof(double));
  return v;
}
void myvet_libera (double* v)
{
  free(v);
}
double myvet_escalar (int n, double* v, double* w)
{
  double s = 0;
  for (int i=0; i<n; ++i)
    s += v[i]*w[i];
  return s;
}
double myvet_norma2 (int n, double* v)
{
  double s = myvet_escalar(n,v,v);
  return sqrt(s);
}

int myvet_iguais (int n, double* g, double* x, double tol)
{
  for (int i=0; i<n; ++i) {
    if (fabs(g[i]-x[i]) > tol)
      return 0;
  }
  return 1;
}

void myvet_mults (int n, double* v, double s, double* w)
{
  for (int i=0; i<n; ++i)
    w[i] = v[i]*s;
}

void myvet_imprime (int n, double* v)
{
  for (int i=0; i<n; ++i)
    printf("%.16g  ",v[i]);
  printf("\n");
}

