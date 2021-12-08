#include <stdio.h>
#include <stdlib.h>

struct lista{
  int num;
  struct lista *prox;
};
typedef struct lista Lista;
Lista *primeiro;

void adicionar(int x){
  Lista *lista = malloc(sizeof(Lista));
  lista->num=x;
  lista->prox=primeiro;
  primeiro = lista;
}

void negativo(Lista *lista){
  if (lista != NULL) {
    if(lista->num < 0){
      Lista* excluir;
      Lista *listaAux= primeiro->prox;
      excluir = listaAux->prox;
      listaAux->prox=listaAux->prox->prox;
      free(excluir);
      
    }
   negativo(lista->prox);
   }
} 

void imprimir(Lista *lista) {
    if (lista != NULL) {
        printf("\n%d", lista->num);
        imprimir(lista->prox);
    }
}

int main(void) {
  adicionar(-1);
  adicionar(1);
  adicionar(2);
  adicionar(3);
  adicionar(4);
  adicionar(-5);


  printf("\nAntes: ");
  imprimir(primeiro);
  printf("\nDepois: ");
  negativo(primeiro);
  imprimir(primeiro);


  return 0;
}