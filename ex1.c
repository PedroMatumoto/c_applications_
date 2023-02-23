#include <stdio.h>

#define MAX_ARR 1024 // Não modifique esse valor!!

/* 
 * Protótipos das funções - NÃO MODIFIQUE 
 *
 */

// le_vetor deve ler um vetor até receber o valor -100 ou chegar em MAX_ARR.
// O retorno da função deve ser o tamanho do vetor lido.
int le_vetor(int vetor[MAX_ARR]);

// selection_sort deve ordernar um vetor de tamanho MAX_ARR. 
// Recebe como parametros o vetor, seu tamanho e se a ordenação será crescente.
void selection_sort(int vetor[MAX_ARR], int tam_vetor, int crescente);

// bubble_sort deve ordernar um vetor de tamanho MAX_ARR. 
// Recebe como parametros o vetor, seu tamanho e se a ordenação será crescente.
void bubble_sort(int vetor[MAX_ARR], int tam_vetor, int crescente);

// troca_elementos deve receber um vetor e dois índices e trocar os troca 
// os elementos do vetor de lugar.
void troca_elementos(int vetor[MAX_ARR], int i, int j);

// Ganharam essa de brinde. =)
void exibe_vetor(int vetor[MAX_ARR], int tam_vetor);

int verifica_ordenacao(int vetor[MAX_ARR]);

int main (int argc, char *argv[])
{
  /* Declaração do Array */
  int metodo;
  int ordenacao;

  int a[MAX_ARR] = {};

  int tam = le_vetor(a);
  
  exibe_vetor(a,tam);
  

  
    //printf("Vetor já ordenado!\n");
    //exibe_vetor(a,tam);

  printf("Selecione o método de ordenação(1 - Selection, 2 - Bubble): " );
  scanf("%i",&metodo);

  switch (metodo)
  {
  case 1:
    printf("Ordenação crescente(1) ou decrescente(0): ");
    scanf("%i",&ordenacao);
    switch (ordenacao)
    {
    case 1:
      selection_sort(a,tam,ordenacao);
      exibe_vetor(a,tam);
      break;

    case 0:
      selection_sort(a,tam,ordenacao);
      exibe_vetor(a,tam);

      break;
    
    default:
      printf("Comando inválido.");
      break;
    }
    break;

  case 2:
    printf("Ordenação crescente(1) ou decrescente(0): ");
    scanf("%i",&ordenacao);
    switch (ordenacao)
    {
    case 1:
      bubble_sort(a,tam,ordenacao);
      exibe_vetor(a,tam);
      break;

    case 0:
      bubble_sort(a,tam,ordenacao);
      exibe_vetor(a,tam);

      break;
    
    default:
      printf("Comando inválido.");
      break;
    }

    break;  

  default:
    printf("Número de método inválido, saindo do programa");
    break;
  }

  return 0;
}

void troca_elementos(int vetor[MAX_ARR], int i, int j) {
  int aux;
  aux = vetor[i];
  vetor[i] = vetor[j];
  vetor[j] = aux;
}

void selection_sort(int vetor[MAX_ARR], int tam_vetor, int crescente) {
  int aux,i,j;
  for (i = 0; i < tam_vetor - 1; i++)
  {
    for (j = (i + 1); j < tam_vetor - 1; j++)
    {
      aux = vetor[i];
      if ((vetor[j] < aux) && (crescente == 1))
      {
        troca_elementos(vetor,i,j);
      }
      if ((vetor[j] > aux) && (crescente == 0))
      {
        troca_elementos(vetor,i,j);
      }
    }
  }
  
}

void bubble_sort(int vetor[MAX_ARR], int tam_vetor, int crescente) {
  int aux;

  for (int i = tam_vetor - 1; i >= 1; i--)
  {
    for (int j = 0; j < (i - 1); j++)
    {
      if((vetor[j] > vetor[j + 1] && crescente == 1) || (vetor[j] < vetor[j + 1] && crescente == 0))
      {
        aux = vetor[j];
        vetor[j] = vetor[j+1];
        vetor[j+1] = aux;
      }
    } 
  }
}

int le_vetor(int vetor[MAX_ARR]) {
  int i = 0, entrada;
  printf("Digite os Valores: ");
  do 
  {
    scanf(" %i", &entrada);
    vetor[i++] = entrada;
  } while (entrada != -100);
  return i;
}

void exibe_vetor(int vetor[MAX_ARR], int tam_vetor) {
  printf("[");
  for (int i = 0; i < (tam_vetor - 1); i++) {
    printf("%i", vetor[i]);
    if ( i < tam_vetor - 2 ) printf(", ");
  }
  printf("]\n");
}