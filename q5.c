#include <stdio.h>
#include <stdlib.h>

struct lista{
  int num;
  struct lista *prox;
};
typedef struct lista Lista;
Lista *primeiro;
int tamanho = 0;

void adicionar(int x){
  Lista *lista = malloc(sizeof(Lista));
  lista->num=x;
  lista->prox=primeiro;
  primeiro = lista;
}

void negativo(Lista *lista){
  Lista *anterior= lista;
  Lista *atual= anterior->prox;
  while(atual!=NULL){
    if(atual->num<0){ 
      Lista* tmp=atual;
      anterior->prox=atual->prox;
      atual = atual->prox;
      free(tmp);
  }else{
    anterior=atual;
    atual=atual->prox;
} } } 

void PrimeiroNumNegativo(int index,Lista *lista){
    int numero=lista->num;
if(numero<0){ 
        Lista *contatoParaExcluir;
        if(index==0){
            contatoParaExcluir = primeiro;
            primeiro = primeiro->prox;
        }else{
            Lista *listaAux = primeiro;
            int i=0;
            while(i!=index-1)
            {
                listaAux = listaAux->prox;
                i++;
            }
            contatoParaExcluir = listaAux->prox;
            listaAux->prox = listaAux->prox->prox;
        }
        free(contatoParaExcluir);
    }} 

void imprimir(Lista *lista){
    if (lista != NULL) {
        printf("\n%d", lista->num);
        imprimir(lista->prox);
    }
}

int main(void) {
  adicionar(-9);
  adicionar(8);
  adicionar(-7);
  adicionar(-6);
  adicionar(5);
  adicionar(4);
  adicionar(-3);
  adicionar(2);
  adicionar(-1);
  adicionar(-1);
  adicionar(-1);
  adicionar(1);
  adicionar(-1);
  adicionar(-1);
  
  printf("\nAntes: ");
  imprimir(primeiro);
  printf("\nDepois: ");
  
  negativo(primeiro);
  PrimeiroNumNegativo(0,primeiro);
  imprimir(primeiro);


  return 0;
}