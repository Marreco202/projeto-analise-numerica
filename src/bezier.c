#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mymatriz.h"
#include "myvetor.h"
#define H 0.1
/*

Alunos:

João Victor Godinho Woitschach - 2011401
Lucas Daibes Lucena - 2010796
Matheus Valejo - 2011536

*/

double func_xt(double t){
    return 0.5+ 0.3*t + 3.9*t*t - 4.7*t*t*t;
}

double func_yt(double t){
    return 1.5+ 0.3*t + 0.9*t*t - 2.7*t*t*t;
}

double* ponto_x_y(double (*fx) (double x), double(*fy) (double x),double t){
    double *vet = myvet_cria(2);
    vet[0] = fx(t);
    vet[1] = fy(t);
    return vet;

}
double derivada (double (*f) (double x), double x){
    return (f(x+H) - f(x-H)) / (2*H);
}

double func_zt(double t){ 
    return sqrt(derivada(func_xt,t) * derivada(func_xt,t) + derivada(func_yt,t) * derivada(func_yt,t));
}

double simpson(double (*f) (double), double a, double b, int n){
    double ret = 0;

    for(double i = a; i < b; i+=H){
        ret+=  (H/6) * (f(i) + (4 * f(i + (H/2))) + f(i + H));
    }
    return ret;
}

double get_s(double t1, double t2, double n){ // n == step
    return simpson(func_zt, t1,t2,n);
}


double func_ft(double s, double n,double a,double b){ 
    double meio,length;
    while((b-a)> 10e-10){
        meio = (a+b)/2.0;
        length = get_s(a,meio,n);
        if (length < s) {
            a = meio;  
        } else {
            b = meio;  
        }
    } 
    return meio;
}

double* inverse_vector(double (*fx) (double),double (*fy) (double),double s,double n,double a ,double b){
    double t = func_ft(s,n,a,b);
    double* vetor = ponto_x_y(fx,fy,t);
    return vetor;
}