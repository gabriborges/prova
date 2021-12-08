#include <stdio.h>
#include <stdlib.h>

int identificador = 0;

struct pessoa{
  char nome[50];
  int identificador;
  int amigo;
  int amigo2;
  struct pessoa *prox;
};
typedef struct pessoa Pessoa;
Pessoa *primeiro;

int cadastrarpessoa(){
  Pessoa *pessoa = malloc(sizeof(Pessoa));
  identificador++;
  printf("Nome: ");
  scanf("%s", pessoa->nome);
  pessoa->identificador=identificador;
  pessoa->prox=primeiro;
  primeiro = pessoa;
  return(identificador);
}

void relaciona(int amg1, int amg2, Pessoa *pessoa){
      cadastrarpessoa();
      pessoa->amigo=amg1;
      cadastrarpessoa();
      pessoa->amigo2=amg2;
}

int main(void) {
 
  cadastrarpessoa();
  
  relaciona(2,2,primeiro);

  return 0;
}