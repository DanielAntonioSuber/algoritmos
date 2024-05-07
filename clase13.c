// Usaresmos el nodo de cabecera
// Programando estructuras de enlaces
#include <stdio.h>
#include <stdlib.h>


struct Nodo {
  int dato; 
  struct Nodo *ptrSig;
};

int main() {
  struct Nodo *ptrRef, *ptrN, *ptrRec, *ptrBas;
  ptrRef = NULL;

  ptrN = (struct Nodo*) malloc(sizeof(struct Nodo));
  printf("Ingresa el enterno: ");
  scanf("%d", &ptrN -> dato);
  ptrN -> ptrSig = NULL;
  ptrRef = ptrN;

  ptrN = (struct Nodo*) malloc(sizeof(struct Nodo));
  printf("Ingresa el entero: ");
  scanf("%d", &ptrN -> dato);
  ptrN -> ptrSig = NULL;

  ptrN -> ptrSig = ptrRef;
  ptrRef = ptrN;

  ptrN = (struct Nodo*) malloc(sizeof(struct Nodo));
  printf("Ingresa el entero: ");
  scanf("%d", &ptrN -> dato);
  ptrN -> ptrSig = NULL;

  ptrN -> ptrSig = ptrRef;
  ptrRef = ptrN;

  ptrN = (struct Nodo*) malloc(sizeof(struct Nodo));
  printf("Ingresa el entero: ");
  scanf("%d", &ptrN -> dato);
  ptrN -> ptrSig = NULL;

  ptrN -> ptrSig = ptrRef;
  ptrRef = ptrN;

  ptrRec = ptrRef;

  while (ptrRec != NULL)
  {
    printf("%d", ptrRec -> dato);
    ptrRec = ptrRec -> ptrSig;
  }

  ptrBas = ptrRef;
  printf("El dato es recuperado es %d", &ptrBas -> dato);
  ptrRec = ptrBas -> ptrSig;
  free(ptrBas);
  

  return 0;
}