// Usaresmos el nodo de cabecera
// Programando estructuras de enlaces
#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
  int dato;
  struct Nodo *ptrSig;
};

struct Nodo *crearNodo(int dato);
void meterNodo(struct Nodo **ptrRef2, int dato);
void recorrer(struct Nodo **ptrRef2);

int main()
{
  struct Nodo *miPtrRef1, **miPtrRef2;
  miPtrRef1 = NULL;

  miPtrRef2 = &miPtrRef1;

  meterNodo(miPtrRef2, 10);
  meterNodo(miPtrRef2, 1);
  meterNodo(miPtrRef2, 5);
  meterNodo(miPtrRef2, 8);

  recorrer(miPtrRef2);
}

struct Nodo *crearNodo(int dato1)
{
  struct Nodo *ptrN;
  ptrN = (struct Nodo *)malloc(sizeof(struct Nodo));
  ptrN->dato = dato1;
  ptrN->ptrSig = NULL;

  return ptrN;
}

void meterNodo(struct Nodo **ptrRef2, int dato)
{
  struct Nodo *ptrN;
  ptrN = crearNodo(dato);
  if(*ptrRef2 == NULL) {
    *ptrRef2 = ptrN;
  } else {
    ptrN -> ptrSig = *ptrRef2;
    *ptrRef2 = ptrN;
  }
}

void recorrer(struct Nodo **ptrRef2)
{
  struct Nodo *ptrRec;

  ptrRec = (*ptrRef2 ) -> ptrSig;
  printf("%d\n", (*ptrRef2) -> dato);
  while (ptrRec != NULL)
  {
    printf("%d\n", ptrRec->dato);
    ptrRec = ptrRec->ptrSig;
  }
}

void eliminarNodo(struct Nodo **ptrRef2, char *ptrDato)
{
  
}
