#include <stdio.h>
#include <stdlib.h>

// Creamos la estructura Nodo para el arbol
struct Nodo {
  int contenido;
  struct Nodo *ptrIzq, *ptrDer;
};

// Prototipos de las funciones de recorrido del arbol
void inorden(struct Nodo *);
void postorden(struct Nodo *);
void preorden(struct Nodo *);

// Declaramos la funcion menu
int menu();

// Declaramos la funcion de insertarNodo y crearNodo
struct Nodo *crearNodo(int);
void insertarNodo(struct Nodo **, int);

// Declaramos la funcion ejecutarAlgo
void ejecutarAlgo(struct Nodo *);

int main() {
  struct Nodo *ptrRaiz;
  int opt = 0;
  int contenido = 0;

  while (opt != 5) {
    opt = menu();
    switch (opt) {
      case 1:
        printf("Escribe el contenido: ");
        scanf("%d", &contenido);
        insertarNodo(&ptrRaiz, contenido);
      break;
      case 2:
        preorden(ptrRaiz);
      break;
      case 3:
        inorden(ptrRaiz);
      break;
      case 4:
        postorden(ptrRaiz);
      break;
      case 5:
        printf("Hasta luego. :)\n");
      break;
      default:
        printf("Elije una opcion corrrecta\n");
      break;
    }
  }

  return 0;
}

// Definimos la funcion menu
int menu() {
  int opt = 0;
  printf("Menu de opciones\n");
  printf(" 1. Insertar nodo\n");
  printf(" 2. Recorrido preorden\n");
  printf(" 3. Recorrido inorden\n");
  printf(" 4. Recorrido postorden\n");
  printf(" 5. Salir\n");
  printf("Escribe una opcion: ");
  scanf("%d", &opt);

  return opt;
}

// Definimos la funcion crearNodo
struct Nodo *crearNodo(int contenido) {
  struct Nodo *ptrN = (struct Nodo *) malloc(sizeof(struct Nodo));
  ptrN->contenido = contenido;
  ptrN->ptrIzq = NULL;
  ptrN->ptrDer = NULL;
}

// Definimos la funcion insertarNodo
void insertarNodo(struct Nodo **ptrRaiz, int contenido) {
  if(*ptrRaiz == NULL) {
    *ptrRaiz = crearNodo(contenido);
  } else if( ((*ptrRaiz)->contenido) > contenido ) {
    insertarNodo( &((*ptrRaiz)->ptrIzq), contenido );
  } else {
    insertarNodo ( &((*ptrRaiz)->ptrDer), contenido);
  }
}

// Definimos la funcion ejecutarAlgo
void ejecutarAlgo(struct Nodo *ptr) {
  printf("El contenido es %d\n", ptr->contenido);
}

// Definimos las funciones de recorrido
void inorden(struct Nodo *ptr) {
  if(ptr != NULL) {
    inorden(ptr->ptrIzq);
    ejecutarAlgo(ptr);
    inorden(ptr->ptrDer);
  }
}

void postorden(struct Nodo *ptr) {
  if(ptr != NULL) {
    postorden(ptr->ptrIzq);
    postorden(ptr->ptrDer);
    ejecutarAlgo(ptr);
  }
}

void preorden(struct Nodo *ptr) {
  if(ptr != NULL) {
    ejecutarAlgo(ptr);
    preorden(ptr->ptrIzq);
    preorden(ptr->ptrDer);
  }
}
