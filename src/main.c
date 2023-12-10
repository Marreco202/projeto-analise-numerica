#include <stdio.h>
#include <stdlib.h>
#include "bezier.h"
#include "myvetor.h"

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
    double* vetor = ponto_x_y(func_xt,func_yt,0.5);
    double length = get_s(0,0.5,0.1);
    double* inverse_vetor = inverse_vector(func_xt,func_yt,length,0.1,0,1);
    printf("%f %f",inverse_vetor[1],vetor[1]);
    free(vetor);
    free(inverse_vetor);
    return 0;
}
