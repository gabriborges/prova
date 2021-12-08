#include <stdio.h>
#include <stdlib.h>

struct nodalista{
    char titulo[51]; 
    char autor[51]; 
    int ano; 
    int quantidade; 
    struct nodalista *prox; 
};
typedef struct nodalista Nodalista;
Nodalista *primeiro;
int tamanho=0;

void adicionarlivro(){
  Nodalista *nodalista = malloc(sizeof(Nodalista));
  printf("\n---------Adicionando Livro---------");
  printf("\nTitulo: ");
  scanf("%s", nodalista->titulo);
  printf("Autor: ");
  scanf("%s", nodalista->autor);
  printf("Ano: ");
  scanf("%d", &nodalista->ano);
  printf("Quantidade: ");
  scanf("%d", &nodalista->quantidade);
  printf("\n");
  nodalista->prox = primeiro;
  primeiro = nodalista;
}

void mostrar_livros(Nodalista *nodalista){
    if (nodalista!=NULL){
      printf("\n%s - %s - %d - %d", nodalista->titulo, nodalista->autor, nodalista->ano,  nodalista->quantidade);
      mostrar_livros(nodalista->prox);
    }
}

int quantidade_livros(Nodalista *nodalista){
    if (nodalista!=NULL){
      tamanho++;
      quantidade_livros(nodalista->prox);
    } 
    return(tamanho);  
}

void livros_anos(Nodalista *nodalista, int ano){
    if(nodalista != NULL){
      if(nodalista->ano == ano){
        printf("\nLivro encontrado: ");
        printf("\n%s - %s - %d - %d", nodalista->titulo, nodalista->autor,nodalista->ano,  nodalista->quantidade);
      }
      livros_anos(nodalista->prox, ano);
    }
}

int main(){

  int ano;
  adicionarlivro();
  adicionarlivro();

  printf("\nLivros na Lista: ");
  mostrar_livros(primeiro);

  printf("\nPesquisar livro por ano: ");
  scanf("%d", &ano);
  livros_anos(primeiro,ano);

  quantidade_livros(primeiro);
  printf("\nQuantidade de Livros em toda a lista: %d", tamanho);
  return(0);
}