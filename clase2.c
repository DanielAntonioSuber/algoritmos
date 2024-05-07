#include <stdio.h>
int main() {
  int arreglo[5];
  int *ptr1;
  int **ptr2;

  ptr1 = arreglo;

  for(ptr2 = &ptr1; *ptr2 < arreglo + 5; ptr1 = ptr1 + 1) {
    printf("Ingrese entero: ");
    scanf("%d", *ptr2);
  }
  ptr1 = arreglo;

  for(ptr2 = &ptr1; *ptr2 < arreglo + 5; ptr1 = ptr1 + 1) {
    printf("En la posicion %d en el valor %d y en la memoria %ld", (int)(*ptr2 - arreglo), **ptr2, *ptr2); 
  }

  return 0;
}