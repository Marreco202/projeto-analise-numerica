#include <stdio.h>
#include <stdlib.h>
#include "bezier.h"

/*

Alunos:

João Victor Godinho Woitschach - 2011401
Lucas Daibes Lucena - 2010796
Matheus Valejo - 2011536

*/

int main(void){

    //Bezier do exemplo do slide 
    double xT[] = {0.5, 0.3, 3.9, -4.7};
    double yT[] = {1.5, 0.3, 0.9, -2.7};
    double* vetor = ponto_x_y(func_xt,func_yt,10);
    double length = get_s(0,10,0.1);
    double* inverse_vetor = func_ft(func_xt,func_yt,length,0.1,0,10);
    printf("Hello there!\n");

    return 0;
}
