#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define G 9.8
#define length 10

double function(double t,double A){
    return A*cos(sqrt(G/length)*t);
    
}
double RungeKuttaAdapt (double t0, double t1, double y0, double (*f) (double t, double A), double tol){ 
    double h = 10e-7;
    double k0,k1,k2,k3,lim,erro,y_full,y_half1,y_half2,fator;
    double ti = t0;
    double yi = y0;
    while(ti<t1){
        erro = 2 * tol;
        while(erro > tol){
            ti = ti+h;
            
            k0 = h * f(t0, yi);
            k1 = h * f(t0 + h / 2.0, yi + k0 / 2.0);
            k2 = h * f(t0 + h / 2.0, yi + k1 / 2.0);
            k3 = h * f(t0 + h, yi + k2);
            
            y_full = yi + (1.0/6.0)*(k0+2*k1+2*k2+k3);

            k0 = h / 2.0 * f(t0, yi);
            k1 = h / 2.0 * f(t0 + h / 4.0, yi + k0 / 2.0);
            k2 = h / 2.0 * f(t0 + h / 4.0, yi + k1 / 2.0);
            k3 = h / 2.0 * f(t0 + h / 2.0, yi + k2);
            y_half1 = yi + (1.0/6.0)*(k0+2*k1+2*k2+k3);

            k0 = h / 2.0 * f(t0, y_half1);
            k1 = h / 2.0 * f(t0 + h / 4.0, y_half1 + k0 / 2.0);
            k2 = h / 2.0 * f(t0 + h / 4.0, y_half1 + k1 / 2.0);
            k3 = h / 2.0 * f(t0 + h / 2.0, y_half1 + k2);
            y_half2 = y_half1 + (1.0/6.0)*(k0+2*k1+2*k2+k3);

            erro = fabs((y_full - y_half2)/15.0);
            fator = pow((tol/erro),1.0/5.0);

            if (ti + h > t1) {
                h = t1 - ti;
            }
            if(fator >= 1.0){
                yi = y_full;
                h = fmin(h*fmin(fator,1.2),lim);
            }

            else{
                ti = ti-h;
                h = fmin(0.8*fator*h,lim);
            }
            t0 = ti;
            yi = y_full;
        }
    }
    return yi;
}   