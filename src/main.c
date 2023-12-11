#include <stdio.h>
#include <stdlib.h>
#include "bezier.h"
#include "myvetor.h"
#include <math.h>

/*

Alunos:

João Victor Godinho Woitschach - 2011401
Lucas Daibes Lucena - 2010796
Matheus Valejo - 2011536

*/
double func_xt(double t){
    return -1 + 9*t -  27*t*t + 13*t*t*t;
    //return 13*t**3 - 27*t**2 + 9*t -1
}

double func_yt(double t){
    return 9*t - 15*t*t + 6*t*t*t;
    //return  6*t**3 - 15*t**2 +9*t

}

int main(void){

    double passo = 0.0001;
    double t = 0.75;

    printf("=== BEZIER 3 ===        \n");

    printf("passo: %.6f\n",passo);
    double* vetor = ponto_x_y(func_xt,func_yt,t);
    double length = get_s(0,t,passo,func_xt,func_yt);
    double* inverse_vetor = inverse_vector(func_xt,func_yt,length,passo,0,1); //mudar nome da variavel depois. muito parecido com chamada da funcao
    //printf("%f ",func_ft(length,0.1,0,1));
    printf("Ponto x y real: (%f,%f)\n",vetor[0],vetor[1]);
    printf("Ponto x y aproximado obtido atraves de p*: (%f,%f)\n",inverse_vetor[0],inverse_vetor[1]);
    printf("Percentual de erro em x: %.12f%%\n",fabs(((inverse_vetor[0]-vetor[0])/vetor[0]) * 100));
    printf("Percentual de erro em y: %.12f%%\n", fabs(((inverse_vetor[1]-vetor[1])/vetor[1]) * 100)) ;
    
    
    printf("================\n");
    free(vetor);
    free(inverse_vetor);
    return 0;
}
