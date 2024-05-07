#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
  int dato;
  struct Nodo *ptrSig;
  struct Nodo *ptrAnt;
};

struct Nodo *crearNodo(int dato);
void encolar(int dato, struct Nodo *ptrRef1, struct Nodo *ptrRef2);
int desencolar(struct Nodo *ptrRef1, struct Nodo *ptrRef2);
void recorrerIzqDer(struct Nodo *ptrRef1, struct Nodo *ptrRef2);

int main()
{
  struct Nodo *ptrRef1, *ptrRef2;

  // Creacion de los nodos auxiliares
  ptrRef1 = crearNodo(-1000);
  ptrRef2 = crearNodo(-2000);

  // Enlace del los nodos
  ptrRef1->ptrSig = ptrRef2;
  ptrRef2->ptrAnt = ptrRef1;

  // Encolamiento
  encolar(1, ptrRef1, ptrRef2);
  encolar(2, ptrRef1, ptrRef2);
  encolar(3, ptrRef1, ptrRef2);

  // Recorrer la cola
  recorrerIzqDer(ptrRef1, ptrRef2);
  printf("\n");

  // Desencolamiento
  int dato = desencolar(ptrRef1, ptrRef2);
  printf("El dato desencolado es %d\n", dato);
  dato = desencolar(ptrRef1, ptrRef2);
  printf("El dato desencolado es %d\n", dato);
  dato = desencolar(ptrRef1, ptrRef2);
  printf("El dato desencolado es %d\n", dato);
}

int colaVacia(struct Nodo *ptrRef1, struct Nodo *ptrRef2) {
  return ptrRef1 -> ptrSig == ptrRef2;
}

void encolar(int dato, struct Nodo *ptrRef1, struct Nodo *ptrRef2)
{
  struct Nodo *ptrN = crearNodo(dato);

  if (ptrRef1->ptrSig == ptrRef2)
  {
    ptrRef1->ptrSig = ptrN;
    ptrRef2->ptrAnt = ptrN;
    ptrN->ptrAnt = ptrRef1;
    ptrN->ptrSig = ptrRef2;
  }
  else
  {
    ptrRef1->ptrSig->ptrAnt = ptrN;
    ptrN->ptrAnt = ptrRef1;
    ptrN->ptrSig = ptrRef1->ptrSig;
    ptrRef1->ptrSig = ptrN;
  }
}

int desencolar(struct Nodo *ptrRef1, struct Nodo *ptrRef2)
{
  struct Nodo *ptrBorr = ptrRef2->ptrAnt;
  int dato = ptrBorr->dato;

  ptrRef2->ptrAnt = ptrBorr->ptrAnt;
  ptrBorr->ptrAnt->ptrSig = ptrRef2;

  free(ptrBorr);

  return dato;
}

void recorrerIzqDer(struct Nodo *ptrRef1, struct Nodo *ptrRef2)
{
  struct Nodo *ptrRec;

  ptrRec = ptrRef1->ptrSig;
  while (ptrRec->ptrSig != NULL)
  {
    printf("%d\n", ptrRec->dato);
    ptrRec = ptrRec -> ptrSig;
  }
}

void recorrerDerIzq(struct Nodo *ptrRerf1, struct Nodo *ptrRef2) {
  struct Nodo ptrRef;
}

struct Nodo *crearNodo(int dato)
{
  struct Nodo *ptrN;
  ptrN = (struct Nodo *)malloc(sizeof(struct Nodo));
  ptrN->ptrSig = NULL;
  ptrN->ptrAnt = NULL;
  ptrN->dato = dato;
  return ptrN;
};
