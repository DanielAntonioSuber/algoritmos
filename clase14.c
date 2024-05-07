#include <stdio.h>
#include <stdlib.h>
#define TAM 5

struct Pila {
  int arreglo[TAM];
  int *ptrc;
};

void meterPila(struct Pila *ptrP, int dato);
int sacarPila(struct Pila *ptrP);
int estaPilaLlena(struct Pila *ptrP);
int estaPilaVacia(struct Pila *ptrP);
int menu();

int main() {
  struct Pila pila, *miPtrP;
  miPtrP = &pila;
  miPtrP -> ptrc = miPtrP -> arreglo;
  int miDato;

  for(;;) {
    switch (menu()) {
    case 1:
      if(estaPilaLlena(miPtrP)) {
        printf("La pila esta llena\n");
      } else {
        printf("Ingrese un entero: ");
        scanf("%d", &miDato);
        meterPila(miPtrP, miDato);
      }
      break;
    case 2: 
      printf("El dato recuperado es %d", sacarPila(miPtrP));
      break;
    case 3:
      exit(0);
    default:
      break;
    }
  }

  return 0;
}

int menu() {
  int opt = 0;

  printf("Menu de opciones\n");
  printf(" 1. Meter dato\n");
  printf(" 2. Sacar dato\n");
  printf(" 3. Salida\n");
  printf("Escribe la opcion: ");
  scanf("%d", &opt);

  return opt;
}

void meterPila(struct Pila *ptrP, int dato) {
  *ptrP -> ptrc = dato;
  ptrP -> ptrc++;
}

int sacarPila(struct Pila *ptrP) {
  ptrP -> ptrc--;
  return (*ptrP -> ptrc);
}

int estaPilaLlena(struct Pila *ptrP) {
  return  ptrP -> ptrc == &ptrP -> arreglo[TAM]; 
}
int estaPilaVacia(struct Pila *ptrP) {
  return ptrP -> ptrc == ptrP -> arreglo; 
}