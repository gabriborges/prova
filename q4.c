#include <stdio.h>
#include <stdlib.h>

int main(void){

  struct lista{
  int valor;
  int valor2;
  struct lista *prox;
};
  typedef struct lists Lista;
  struct  lista l1, l2;
  struct lista *aponta = &l1;

  l1.valor=1;
  l1.valor2=2;
  l2.valor=3;
  l2.valor2=4;

  l1.prox=&l2;
  l2.prox=NULL;
  
  while(aponta != NULL){
    printf("\n%d \n%d", aponta->valor, aponta->valor2);
    aponta = aponta->prox;
  }
 
  return 0;
}