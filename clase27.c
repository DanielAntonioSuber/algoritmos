#include <stdio.h>
#include <stdlib.h>

int sucesor(int);

int sumaRecursiva(int, int);

int main() {
  int suma = sumaRecursiva(5, 4);

  printf("La suma es %d", suma);
}

int sucesor(int n) {
  return n + 1;
}

int sumaRecursiva(int n, int m) {
  if(n == 0)
    return m;

  return sumaRecursiva(n - 1, sucesor(m));
}

