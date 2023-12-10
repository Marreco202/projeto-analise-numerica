#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mymatriz.h"
#include "myvetor.h"
#define H 0.00001
/*

Alunos:

João Victor Godinho Woitschach - 2011401
Lucas Daibes Lucena - 2010796
Matheus Valejo - 2011536

*/

double func_xt1(double t){
    return 0.5+ 0.3*t + 3.9*t*t - 4.7*t*t*t;
}

double func_yt1(double t){
    return 1.5+ 0.3*t + 0.9*t*t - 2.7*t*t*t;
}

/*
x(t)=1+3t+9t^2 +5t^3
y(t)=1−3t+9t ^2 +t^3
*/

double func_xt2(double t){
    return 1+ 3*t + 9*t*t - 5*t*t*t;
}

double func_yt2(double t){
    return 1 - 0.3*t + 9*t*t - 1*t*t*t;
}

/*
x(t) = 13t^3 - 27t^2 + 9t -1
y(t) = 6t^3 - 15t^2 +9t
*/
double func_xt3(double t){
    return -1 + 9*t - 27*t*t - 13*t*t*t;
}

double func_yt3(double t){
    return 9*t - 15*t*t + 6*t*t*t;
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
    return sqrt(derivada(func_xt3,t) * derivada(func_xt3,t) + derivada(func_yt3,t) * derivada(func_yt3,t));
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


double func_ft(double s, double n,double a,double b){ //s = comprimento da curva,n = step, a = menor ponto da integral, b = maior ponto da integral
    double meio,length;
    double t1 = a;
    double t2 = b;
    int contador = 0;

    while(fabs(t2-t1) > 1e-14){
        contador++;
        meio = (t1+t2)/2.0;
        length = get_s(a,meio,n);
        if (length < s) {
            /*
            printf("L:%f\n",length);
            printf("A%f\n",a);
            printf("M:%f\n",meio);*/
            t1 = meio;  
        
        } else {
        /*
            printf("L:%f\n",length);
            printf("B%f\n",b);
            printf("M:%f\n",meio);
            */

            t2 = meio;  

        }
    } 
    printf("quantidade de iteracoes: %d\n",contador);
    return meio;
}

double* inverse_vector(double (*fx) (double),double (*fy) (double),double s,double n,double a ,double b){ //s = comprimento da curva,n = step, a = menor ponto da integral, b = maior ponto da integral
    double t = func_ft(s,n,a,b);
    double* vetor = ponto_x_y(fx,fy,t);
    return vetor;
}

/*double func_ft(double s, double t, double n){
    return s - get_s(0,t,n);
}*/