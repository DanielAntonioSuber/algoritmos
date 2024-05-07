// Condicion inicial Fist In Fist Out
// esta la cola llean 
// Esta la cola vacia
#include <stdio.h>
#include <stdlib.h>
#define TAM 100

struct Cola {
  int arreglo[100];
  int *ptrM;
  int *ptrS;
};

int encolar(struct Cola *ptrc, int dato);

int main() {
  struct Cola cola, *ptrC;
  int miDato;
  ptrC = &cola;

  ptrC -> ptrM = ptrC -> arreglo;
  ptrC -> ptrS = ptrC -> arreglo;

  for(;;) {
    switch (menu())
    {
    case 1:
      if(estaColaLlena(miDato)) {
        printf("La cola esta llena\n");
      } else {
        printf("Ingresa el numero: ");
        encolar(ptrC, miDato);
      }
      break;
    case 2:
      printf("El dato recuperado es %d\n", desEncolar(ptrC));
      break;
    default:
      exit(1);
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

int encolar(struct Cola *ptrC, int dato) {
  *ptrC -> ptrM = dato;
  ptrC -> ptrM++;
}

int desEncolar(struct Cola *ptrC) {
  int varAux;
  varAux = *ptrC -> ptrS;
  ptrC -> ptrS++;

  return varAux;
}

int estaColaLlena(struct Cola *ptrC) {
  return ptrC -> ptrS == &ptrC -> arreglo[TAM];
}

int estaPilaVacia(struct Cola *ptrC) {
  return ptrC -> ptrM == ptrC -> ptrS;
}
