#include <stdio.h>

int main() {
  int arreglo[5];
  int *ptr;

  for(ptr = arreglo; ptr < arreglo + 5; ptr = ptr + 1) {
      printf("Ingrese entero: ");
      scanf("%d", ptr);
  }
  
  for(ptr = arreglo; ptr < arreglo + 5; ptr = ptr + 1) {
    printf("En la posicion %d en el valor %d y en la memoria %ld", (int)(ptr - arreglo), *ptr, ptr);
  }
}