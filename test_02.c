#include <stdio.h>
#include "array_list_int.h"


int main(){
  array_list_int a1 = ali_create();
  int i, tamanho, elemento = 0, n, valor, indice, capacidade,delete;
  double porcentagem;
  for (i=0; i < 8 ; ++i)
    ali_push_back(a1,i*3+1);
  tamanho = ali_size(a1);
  printf("Tamanho de a1: %d\n",tamanho);
  printf("a1 = { ");
  for (i=0; i < tamanho ; ++i)
    printf("%d ", ali_get(a1,i));
  printf("}\n");
  printf("Digite o novo valor para ser inserido: \n");
  scanf("%d", &valor);
  printf("Digite o indice no qual deseja incluir o valor: \n");
  scanf("%d", &indice);
  ali_insert_at(a1,indice,valor);
  printf("a1 = { ");
  for (i=0; i < tamanho ; ++i)
    printf("%d ", ali_get(a1,i));
  printf("}\n");
  porcentagem = ali_percent_occuped(a1);
  printf("Porcentagem ocupada em a1 : %f \n",porcentagem);
  capacidade = ali_capacity(a1);
  printf("Capacidade total do Arraylist: %d\n",capacidade);
  return 0;
}
