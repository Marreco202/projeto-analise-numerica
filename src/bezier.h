#ifndef BEZIER_H
#define BEZIER_H

double func_xt(double t);

double func_yt(double t);

double* ponto_x_y(double (*fx) (double x), double(*fy) (double x),double t);

double derivada (double (*f) (double x), double x, double h);

double func_zt(double t, double h);

double simpson (double (*f) (double), double a, double b, int n);

double get_s(double t1, double t2, double n);

double func_ft(double s, double n, double a,double b);

double* inverse_vector(double (*fx) (double),double (*fy) (double),double s,double n,double a ,double b);

#endif