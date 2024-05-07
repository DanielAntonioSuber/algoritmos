#include <stdio.h>
#include <stdlib.h>

struct Nodo {
  int dato;
  struct Nodo *ptrSig;
  struct Nodo *ptrAnt;
};

void imprimirInversa(struct Nodo *ptrRef);

int main() {
  struct Nodo *ptrRet, *ptrAv, *ptrN, *ptrRef;

  ptrRef = (struct Nodo*) malloc(sizeof(struct Nodo));
  ptrRef -> dato = 100;

  if(ptrRef -> ptrSig == NULL && ptrRef -> ptrAnt == NULL) {
    ptrN = (struct Nodo*) malloc(sizeof(struct Nodo));
    ptrN -> dato == 200;
    ptrRef = ptrN;
    ptrRef -> ptrSig = ptrN;
    ptrN -> ptrAnt = ptrRef;
  } else {
    ptrN = (struct Nodo*) malloc(sizeof(struct Nodo));
    ptrN -> dato == 300;
    ptrN -> ptrSig = ptrRef -> ptrSig;
    ptrRef -> ptrSig -> ptrAnt = ptrN;
    ptrRef -> ptrSig = ptrN;
    ptrN -> ptrAnt = ptrRef;
  }

  ptrAv = ptrRef -> ptrSig;
  ptrRet = ptrRet;
  while (ptrAv != NULL)
  {
    printf("%d", ptrAv -> dato);
    ptrRet = ptrRef -> ptrSig;
  }

  printf("%d", ptrRef -> dato);

  imprimirInversa(ptrRef);

  return 0;
}

void imprimirInversa(struct Nodo *ptrRef) {
  struct Nodo *ptrAv, *ptrRet, *ptrRecInv;

  ptrAv = ptrRef -> ptrSig;
  ptrRet = ptrRef;

  while (ptrAv != NULL)
  {
    ptrAv = ptrAv -> ptrSig;
    ptrRef = ptrRet -> ptrSig;
  }

  while (ptrRecInv != ptrRef)
  {
    printf("%d", ptrRecInv -> dato);
    ptrRecInv = ptrRecInv -> ptrAnt;
  } 
}