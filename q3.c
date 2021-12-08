#include <stdio.h>
#include <stdlib.h>

struct lista{
  int x;
  struct lista *prox;
};
typedef struct lista Lista;
Lista *primeiro;

struct lista2{
  int x2;
  struct lista2 *prox2;
};
typedef struct lista2 Lista2;
Lista2 *primeiro2;

void preencher_lista(int num){
  Lista *lista = malloc(sizeof(Lista));
  lista->x=num;
  lista->prox=primeiro;
  primeiro=lista;
}

void inverte(Lista *lista){
  Lista2 *lista2 = malloc(sizeof(Lista2));
   if (lista != NULL){
      lista2->x2 = lista->x;
      lista2->prox2=primeiro2;
      primeiro2=lista2;
      inverte(lista->prox);  
  }
  
}

void imprimirlista(Lista *lista){
  if (lista != NULL){
      printf("\n%d",lista->x);
      imprimirlista(lista->prox);
  }
}

void imprimirlista2(Lista2 *lista2){
  if (lista2 != NULL){
      printf("\n%d",lista2->x2);
      imprimirlista2(lista2->prox2);
  }
}

int main(void){
 
  preencher_lista(1);
  preencher_lista(2);
  preencher_lista(3);
  preencher_lista(4);

  inverte(primeiro);

  printf("\nLista Original:");
  imprimirlista(primeiro); 
  printf("\nLista Invertida:");
  imprimirlista2(primeiro2);

  return 0;
}