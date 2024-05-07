#include <stdio.h>

struct Persona {
  char nombre[30];
  int edad;
  float talla;
  char sexo;
};

int main() {
  struct Persona per1, per2;

  printf("Ingresa el nombre: ");
  gets(per1.nombre);

  printf("Ingresa la edad de per 1: ");
  scanf("%d", &per1.edad);

  printf("Ingresa la talla de per 1: ");
  scanf("%f", &per1.talla);

  printf("Ingresa el sexo de per1: ");
  per1.sexo = getChar();

  printf("El tamannio de persona es %d", sizeof(per1));

  return 0;
}