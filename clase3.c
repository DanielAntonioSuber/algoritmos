#include <stdio.h>

int main() {
  char palabra[20];
  char *ptr1, *ptr2;
  int esPalindromo = 1;

  for(ptr2 = palabra; *ptr2 = '\0'; ptr2 = ptr2 + 1);
  ptr2--;

  for(ptr1 = palabra; ptr1 < ptr2; ptr1 = ptr1 + 1) {
    if(*ptr1 != *ptr2) {
      esPalindromo = 0;
      break;
    }
  }

  if(esPalindromo == 1)
    printf("Es palindromo");
  else
    printf("No es palindromo");

  return 0;
}