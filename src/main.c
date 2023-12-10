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

int main(void){

    //Bezier do exemplo do slide 
        // double xT[] = {0.5, 0.3, 3.9, -4.7};
        // double yT[] = {1.5, 0.3, 0.9, -2.7};
    
    double passo = 0.00001;


    printf("=== BEZIER 3 ===        \n");

    printf("passo: %.6f\n",passo);
    double* vetor = ponto_x_y(func_xt3,func_yt3,0.9);
    double length = get_s(0,0.9,passo);
    double* inverse_vetor = inverse_vector(func_xt3,func_yt3,length,passo,0,1); //mudar nome da variavel depois. muito parecido com chamada da funcao
    //printf("%f ",func_ft(length,0.1,0,1));
    printf("Ponto x y real: (%f,%f)\n",vetor[0],vetor[1]);
    printf("Ponto x y aproximado obtido atraves de p*: (%f,%f)\n",inverse_vetor[0],inverse_vetor[1]);
    printf("Percentual de erro em x: %.12f%%\n",fabs(((inverse_vetor[0]-vetor[0])/vetor[0]) * 100));
    printf("Percentual de erro em y: %.12f%%\n", fabs(((inverse_vetor[1]-vetor[1])/vetor[1]) * 100)) ;
    
    
    printf("================\n");
    
    // printf("=== BEZIER 2 ===        \n");

    // vetor = ponto_x_y(func_xt2,func_yt2,0.9);
    // length = get_s(0,0.9,0.001);
    // inverse_vetor = inverse_vector(func_xt2,func_yt2,length,0.001,0,1); //mudar nome da variavel depois. muito parecido com chamada da funcao

    // //printf("%f ",func_ft(length,0.1,0,1));
    // printf("Ponto x y real: (%f,%f)\n",vetor[0],vetor[1]);
    // printf("Ponto x y aproximado obtido atraves de p*: (%f,%f)\n",inverse_vetor[0],inverse_vetor[1]);
    // printf("Percentual de erro em x: %.9f\n", 1 - ((inverse_vetor[0]-vetor[0])/vetor[0]) * 100);
    // printf("Percentual de erro em y: %.9f\n", 1 - ((inverse_vetor[1]-vetor[1])/vetor[1]) * 100) ;
    
    
    // printf("================\n");
    
    // printf("=== BEZIER 2 ===        \n");

    // vetor = ponto_x_y(func_xt3,func_yt3,0.9);
    // length = get_s(0,0.9,0.001);
    // inverse_vetor = inverse_vector(func_xt3,func_yt3,length,0.001,0,1); //mudar nome da variavel depois. muito parecido com chamada da funcao
    
    // //printf("%f ",func_ft(length,0.1,0,1));
    // printf("Ponto x y real: (%f,%f)\n",vetor[0],vetor[1]);
    // printf("Ponto x y aproximado obtido atraves de p*: (%f,%f)\n",inverse_vetor[0],inverse_vetor[1]);
    // printf("Percentual de erro em x: %.9f\n", 1 - ((inverse_vetor[0]-vetor[0])/vetor[0]) * 100);
    // printf("Percentual de erro em y: %.9f\n", 1 - ((inverse_vetor[1]-vetor[1])/vetor[1]) * 100) ;
    
    
    // printf("================\n");

    free(vetor);
    free(inverse_vetor);
    return 0;
}
