#include <stdio.h>

struct Persona {
  char nombre[30];
  int edad;
  float estatura;
  char sexo;
};

struct Datos {
  struct Persona arreglo[5];
  struct Persona *ptr;
  struct Persona **ptr2;
};

int main() {
  struct Datos datos;
  struct Datos *ptrE, **ptrE2;

  ptrE = &datos;
  ptrE2 = &ptrE;

  datos.ptr = datos.arreglo;
  datos.ptr2 = &datos.ptr;

  for ((*ptrE2)->ptr2 = &(*ptrE2)->ptr; ((*ptrE2)->ptr) < ((*ptrE2)->arreglo + 5); (*ptrE2)->ptr++) {
      printf("Escribe el nombre: ");
      gets((*(*ptrE2)->ptr2)->nombre); 
      printf("Ingresa la edad: ");
      scanf("%d", &(*(*ptrE2)->ptr2)->edad); 
      printf("Ingresa la talla: ");
      scanf("%f", &(*(*ptrE2)->ptr2)->estatura); 
      printf("Ingresa el sexo: ");
      scanf(" %c", &(*(*ptrE2)->ptr2)->sexo);
      fflush(stdin);
      fflush(stdin);
  }

  datos.ptr = datos.arreglo;
  datos.ptr2 = &datos.ptr;

  for ((*ptrE2)->ptr2 = &(*ptrE2)->ptr; ((*ptrE2)->ptr) < ((*ptrE2)->arreglo + 5); (*ptrE2)->ptr++) {
    printf("El nombre: %s\n", (*(*ptrE2)->ptr2)->nombre);
    printf("La edad es: %d\n", (*(*ptrE2)->ptr2)->edad);
    printf("La estatura es: %f\n", (*(*ptrE2)->ptr2)->estatura);
    printf("El sexo es: %c\n", (*(*ptrE2)->ptr2)->sexo);
    printf("En la posicion %d y en la memoria %ld\n\n", (int) ((*(*ptrE2)->ptr2) - (*ptrE2)->arreglo), (*(*ptrE2)->ptr2)); 
  }
  
  return 0;     
}
