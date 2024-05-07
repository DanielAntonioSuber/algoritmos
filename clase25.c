#include <stdio.h>
#include <stdlib.h>

int potenciaRecursiva(int, int);

int main()
{
  int m, n = 0;

  printf("Escribe el numero de la base: ");
  scanf("%d", &m);
  printf("Escribe el numero de la potencia: ");
  scanf("%d", &n);

  int resultado = potenciaRecursiva(n, m);

  printf("El resultado es %d", resultado);
}

int potenciaRecursiva(int n, int m)
{
  if (n == 0)
    return 1;

  if (n > 0)
  {
    if (n == 1)
      return m;

    return potenciaRecursiva(n - 1, m) * m;
  } else {
    printf("El numero no es valido\n");
    exit(0);
  }
}