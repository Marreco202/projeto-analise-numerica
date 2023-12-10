#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mymatriz.h"
#include "myvetor.h"
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
double derivada (double (*f) (double x), double x, double h){
    return (f(x+h) - f(x-h)) / (2*h);
}

double func_zt(double t, double h){ //funcao que retorna S
    return sqrt(derivada(func_xt,t,h) * derivada(func_xt,t,h) + derivada(func_yt,t,h) * derivada(func_yt,t,h) );
    // integral(t1,t1){
        // sqrt(x'(t)² + y'(t)²)
    //}
}

double simpson (double (*f) (double), double a, double b, int n){
    double h = (b -a)/n; 
    double ret = 0;

    for(double i = a; i < b; i+=h){
        ret+=  (h/6) * (f(i) + (4 * f(i + (h/2))) + f(i + h));
    }
    return ret;
}

double get_s(double t1, double t2, double n){ // n == step
    return simpson(func_zt, t1,t2,n);
}


double *func_ft(double (*fx) (double x),double (*fy) (double x),double s, double n,double a,double b){ //
    double *vet = myvet_cria(2);
    double meio,length;
    while((b-a)> 10e-5){
        meio = (a+b)/2.0;
        length = get(0,meio,n);
    }
    vet[0] = fx(meio);
    vet[1] = fy(meio);    
    return vet;
}
