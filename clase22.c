#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dato {
  int edad;
  char nombre[30];
};

struct Nodo {
  struct Dato dato;
  struct Nodo *ptrDer, *ptrIzq;
};

struct Dato *crearDato(int , char[30]);
struct Nodo *crearNodo(struct Dato *);
void apilar(struct Dato *,  int, struct Nodo **, struct Nodo **);
struct Dato desapilar(int, struct Nodo **, struct Nodo **);


int main(){

  return 0;
}

struct Dato *crearDato(int edad, char nombre[30]){
  struct Dato datoN;
  datoN.edad = edad;
  datoN.nombre[0]= nombre;

  return &datoN;
}

struct Nodo *crearNodo(struct Dato *dato){
  struct Nodo *ptrN = (struct Nodo *)malloc(sizeof(struct Nodo));

  ptrN->dato = *dato;
  ptrN->ptrIzq = NULL;
  ptrN->ptrDer = NULL;

  return ptrN;
}

void apilar(struct Dato *dato, int op, struct Nodo **ptrRef11, struct Nodo **ptrRef22){
  struct Nodo *ptrN = crearNodo(dato);

  if(*ptrRef11 == NULL && *ptrRef22 == NULL){
    *ptrRef11 = ptrN;
    *ptrRef22 = ptrN;
  }else{
    if(op = 1){
      (*ptrRef11)->ptrIzq = ptrN;
      ptrN->ptrDer = *ptrRef11;
      *ptrRef11 = ptrN;
    }else{
      (*ptrRef22)->ptrDer = ptrN;
      ptrN->ptrIzq = *ptrRef22;
      *ptrRef22 = ptrN;
    }
  }
}

struct Dato desapilar(int op, struct Nodo **ptrRef11, struct Nodo **ptrRef22){
  struct Nodo *ptrBas = NULL;

  if(*ptrRef11 != NULL && *ptrRef22 != NULL){
    if(op = 3){
      ptrBas = *ptrRef11;
      struct Dato dato = ptrBas->dato;
      *ptrRef11 = ptrBas->ptrDer;
      if(ptrBas->ptrDer != NULL){
        (*ptrRef11)->ptrIzq = NULL;
      }
      free(ptrBas);
      return dato;
    }
  }else{
    printf("\nLa cola esta vacia");
    exit(0);
  }
}
