#ifndef BEZIER_H
#define BEZIER_H

double func_xt(double t);

double func_yt(double t);

double derivada (double (*f) (double x), double x, double h);

double func_zt(double t, double h);

double simpson (double (*f) (double), double a, double b, int n);

double get_s(double t1, double t2, double n);

double func_ft(double s, double t, double n);

#endif