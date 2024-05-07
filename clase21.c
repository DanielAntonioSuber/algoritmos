#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
  int dato;
  struct Nodo *ptrSig;
  struct Nodo *ptrAnt;
};

struct Nodo *crearNodo(int dato);
int desencolar(struct Nodo **ptrRef11, struct Nodo **ptrRef22);
void encolar(int dato, struct Nodo **ptrRef11, struct Nodo **ptrRef22);
int menu();

int main()
{
  struct Nodo **ptrRef11, **ptrRef22;
  struct Nodo *ptrRef1, *ptrRef2;
  int opt = 0;
  int dato = 0;

  ptrRef1 = NULL;
  ptrRef2 = NULL;

  ptrRef11 = &ptrRef1;
  ptrRef22 = &ptrRef2;

  while(opt != 3) {
    int opt = menu();

    switch (opt)
    {
    case 1:
      printf("Escribe el dato: ");
      scanf("%d", &dato);
      encolar(dato, ptrRef11, ptrRef22);
      break;
    case 2:
      dato = desencolar(ptrRef11, ptrRef22);
      printf("\nEl dato es %d\n\n", dato);
      break;
    case 3: 
      exit(1);
    default:
      printf("Elige la opcion correcta\n");
      break;
    }
  }

  return 0;
}

struct Nodo *crearNodo(int dato)
{
  struct Nodo *ptrN;
  ptrN = (struct Nodo *)malloc(sizeof(struct Nodo));
  ptrN->ptrSig = NULL;
  ptrN->ptrAnt = NULL;
  ptrN->dato = dato;
  return ptrN;
}

void encolar(int dato, struct Nodo **ptrRef11, struct Nodo **ptrRef22)
{
  struct Nodo *ptrN = crearNodo(dato);
  if (*ptrRef11 == NULL && *ptrRef22 == NULL)
  {
    *ptrRef11 = ptrN;
    *ptrRef22 = ptrN;
    ptrN->ptrAnt = NULL;
    ptrN->ptrSig = NULL;
  }
  else
  {
    (*ptrRef11)->ptrAnt = ptrN;
    ptrN->ptrAnt = NULL;
    ptrN->ptrSig = *ptrRef11;
    *ptrRef11 = ptrN;
  }
}

int desencolar(struct Nodo **ptrRef11, struct Nodo **ptrRef22)
{
   struct Nodo *ptrBorr = NULL;
  if (*ptrRef22 != NULL)
  {
    ptrBorr = *ptrRef22;
    int dato = ptrBorr->dato;
    *ptrRef22 = ptrBorr->ptrAnt;
    if (*ptrRef22 != NULL)
    {
      (*ptrRef22)->ptrSig = NULL;
    }
    free(ptrBorr);
    return dato;
  }
  else
  {
    printf("La cola esta vacia");
    exit(0);
  }
}

int menu() {
  int opt;
  printf("Menu de opciones\n");
  printf(" 1. Encolar\n");
  printf(" 2. Desencolar\n");
  printf(" 3. Salir\n");

  printf("Escribe la opcion: ");
  scanf("%d", &opt);

  return opt;
}