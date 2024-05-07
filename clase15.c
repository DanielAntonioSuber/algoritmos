#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAM 5

struct Persona {
  char nombre[30];
  int edad;
  char sexo;
};

struct Pila {
  struct Persona arreglo[5];
  struct Persona *ptrc;
};

void meterPila(struct Pila *ptrP, struct Persona *ptrDato);
void sacarPila(struct Pila *ptrP, struct Persona *ptrDato);
int estaPilaLlena(struct Pila *ptrP);
int estaPilaVacia(struct Pila *ptrP);
int menu();

int main() {
  struct Pila pila, *miPtrP;
  struct Persona dato;

  miPtrP = &pila;
  miPtrP -> ptrc = miPtrP -> arreglo;

  for(;;) {
    switch (menu())
    {
    case 1:
      if(estaPilaLlena(miPtrP)) {
        printf("La pila esta llena\n");
      } else {
        printf("Ingresa el nombre: ");
        fgets(dato.nombre,30,stdin);
        printf("Ingrese la edad: ");
        scanf("%d", dato.edad);
        printf("Ingresa el sexo: ");
        dato.sexo = getchar();
        meterPila(miPtrP, &dato);
      }
      break;
    case 2:
      sacarPila(miPtrP, &dato);
      printf("Los datos recuperados son %s, %d, %c\n", dato.nombre, dato.edad, dato.sexo);
      break;
    
    default:
      break;
    }
  }
  
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


void meterPila(struct Pila *ptrp, struct Persona *ptrDato) {
  strcpy( ptrp -> ptrc -> nombre, ptrDato -> nombre);
  ptrp -> ptrc -> edad = ptrDato -> edad;
  ptrp -> ptrc -> sexo = ptrDato -> sexo;

  ptrp -> ptrc++;
}

void sacarPila(struct Pila *ptrP, struct Persona *ptrDato) {
  ptrP -> ptrc--;

  strcpy(  ptrDato -> nombre, ptrP -> ptrc -> nombre);
  ptrDato -> edad = ptrP -> ptrc -> edad  ;
  ptrDato -> sexo = ptrP -> ptrc -> sexo;
  }

int estaPilaLlena(struct Pila *ptrP) {
  return ptrP -> ptrc == &ptrP -> arreglo[TAM];
}

int estaPilaVacia(struct Pila *ptrP) {
  return ptrP -> ptrc == ptrP -> arreglo;
}

