#include <stdio.h>

struct Persona {
  char nombre[30];
  int edad;
  float estatura;
  char sexo;
};

struct Dato {

  struct Persona arreglo[5];
  struct Persona *ptr;
};

int main() {
  struct Dato dato;

  for(dato.ptr = dato.arreglo; dato.ptr < &dato.arreglo[5]; dato.ptr++) {
    printf("Escribe el nombre: ");
    gets(dato.ptr -> nombre);
    printf("Ingresa la edad: ");
    scanf("%d", &dato.ptr -> edad);
    printf("Ingresa la talla: ");
    scanf("%d", &dato.ptr -> estatura);
    printf("Ingresa el sexo: ");
    dato.ptr->sexo = getChar();
  }
}