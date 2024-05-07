#include <stdio.h>


int multipliacionRecursiva(int, int);

int main() {
  int m, n;
  m = n = 0;

 
  printf("Escribe el primer numero: ");
  scanf("%d", &n);

  printf("Escribe el segundo numero: ");
  scanf("%d", &m);

   int producto = multipliacionRecursiva(m, n);

  printf("El producto es %d", producto);
}

int multipliacionRecursiva(int m, int n) {
  if(n == 0)
    return 0;
  
  if(n == 1)
    return m;

  return multipliacionRecursiva(m, n - 1) + m;
}