#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mymatriz.h"
#include "myvetor.h"
#include "bezier.h"
#define H 0.0001
/*

Alunos:

João Victor Godinho Woitschach - 2011401
Lucas Daibes Lucena - 2010796
Matheus Valejo - 2011536

*/

double tol = 10e-9;


double* ponto_x_y(double (*fx) (double x), double(*fy) (double x),double t){
    double *vet = myvet_cria(2);
    vet[0] = fx(t);
    vet[1] = fy(t);
    return vet;

}
double derivada (double (*f) (double x), double x){
    return (f(x+H) - f(x-H)) / (2*H);
}

double func_zt(double t, double (*fx) (double), double (*fy) (double)){ 
    return sqrt(derivada(fx,t) * derivada(fx,t) + derivada(fy,t) * derivada(fy,t));
}

double simpson(double (*f) (double,double (*fx)(double),double(*fy) (double)), double a, double b, int n,double (*fx) (double), double (*fy) (double)){
    double ret = 0;

    for(double i = a; i < b; i+=H){
        ret+=  (H/6) * (f(i,fx,fy) + (4 * f(i + (H/2),fx,fy)) + f(i + H,fx,fy));
    }
    return ret;
}


double func_ft(double s, double n,double a,double b,double (*fx) (double), double (*fy) (double)){ //s = comprimento da curva,n = step, a = menor ponto da integral, b = maior ponto da integral
    double meio,length;
    double t1 = a;
    double t2 = b;
    int iteracoes = 0;

    while(fabs(t2-t1) > 1e-12){ 
        meio = (t1+t2)/2.0;
        length = get_s(a,meio,n,fx,fy);
        if (length < s) {
            t1 = meio;  
        } else{
            t2 = meio;  
        }
        iteracoes++;
    } 
     
    printf("iteracoes: %d \n",iteracoes);
    return meio;
}

double* inverse_vector(double (*fx) (double),double (*fy) (double),double s,double n,double a ,double b){ //s = comprimento da curva,n = step, a = menor ponto da integral, b = maior ponto da integral
    double t = func_ft(s,n,a,b,fx,fy);
    double* vetor = ponto_x_y(fx,fy,t);
    return vetor;
}

static double S(double (*f) (double,double (*f1)(double),double(*f2) (double)), const double a, const double b, double (*fx)(double x), double (*fy)(double y));


double adaptsimpson(double a, double b, double (*f) (double,double (*f1)(double),double(*f2) (double)), double tol, double (*fx)(double x), double (*fy)(double y)) {
	const double m = (a + b) / 2.0;
	const double delta = S(f, a, b,fx,fy) - (S(f, a, m,fx,fy) + S(f, m, b,fx,fy));

	if (fabs(delta) > 15.0 * tol) {
		const double halfTol = tol/2.0;
		return adaptsimpson(a, m, f, halfTol,fx,fy) + adaptsimpson(m, b, f, halfTol,fx,fy);
	} else {
		return S(f, a, m,fx,fy) + S(f, m, b,fx,fy) - (delta/15.0);
	}
}

static double S(double (*f) (double,double (*f1)(double),double(*f2) (double)), const double a, const double b, double (*fx)(double x), double (*fy)(double y)) { //um passo se simpson
	const double h = b - a;
	
	return (h/6.0) * (f(a,fx,fy) + 4.0*f((a+b)/2.0,fx,fy) + f(b,fx,fy));
}

double get_s(double t1, double t2, double n,double (*fx) (double), double (*fy) (double)){ // n == step
    // return simpson(func_zt, t1,t2,n,fx,fy);
    return adaptsimpson(t1,t2,func_zt,tol,fx,fy);
}

