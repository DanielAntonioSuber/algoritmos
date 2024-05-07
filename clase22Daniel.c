#include <stdio.h>
#include <stdlib.h>

struct Dato {
    char nombre[30];
    int edad;
};

struct Nodo {
    struct Dato dato;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

struct Nodo *crearNodo(struct Dato dato);
void agregarIzq(struct Dato dato, struct Nodo **ptrRef11, struct Nodo **ptrRef22);
void agregarDer(struct Dato dato, struct Nodo **ptrRef11, struct Nodo **ptrRef22);
struct Dato eliminarIzq(struct Nodo **ptrRef11, struct Nodo **ptrRef22);
struct Dato eliminarDer(struct Nodo **ptrRef11, struct Nodo **ptrRef22);
struct Dato crearDato();
void imprimirDato(struct Dato *);
int menu();

int main() {
    struct Nodo *ptrRef1 = NULL;
    struct Nodo *ptrRef2 = NULL;
    struct Nodo **ptrRef11 = &ptrRef1;
    struct Nodo **ptrRef22 = &ptrRef2;
    int opt = 0;
    struct Dato dato;

    while (opt != 5)
    {
        switch (opt)
        {
        case 1:
            dato = crearDato();
            agregarIzq(dato, ptrRef11, ptrRef22);
            break;
        case 2:
            dato = crearDato();
            agregarDer(dato, ptrRef11, ptrRef22);
            break;
        case 3:
            dato = eliminarIzq(ptrRef11, ptrRef22);
            printf("El dato eliminado del lado izquierdo es \n");
            imprimirDato(&dato);
            break;
        case 4:
            dato = eliminarDer(ptrRef11, ptrRef22);
            printf("El dato eliminado del lado derecho es \n");
            imprimirDato(&dato);
            break;
        case 5:
            printf("Hasta luego. :)");
            break;
        default:
            break;
        }
    }
    



    return 0;
}

struct Nodo *crearNodo(struct Dato dato) {
    struct Nodo *ptrN = (struct Nodo *) malloc(sizeof(struct Nodo));
    ptrN->dato = dato;
    ptrN->ptrSig = NULL;
    ptrN->ptrAnt = NULL;

    return ptrN;
}

void agregarIzq(struct Dato dato, struct Nodo **ptrRef11, struct Nodo **ptrRef22) {
    struct Nodo *ptrN = crearNodo(dato);
    if (*ptrRef11 == NULL && *ptrRef22 == NULL) {
        *ptrRef11 = ptrN;
        *ptrRef22 = ptrN;
    } else {
        ptrN->ptrSig = *ptrRef11;
        (*ptrRef11)->ptrAnt = ptrN;
        *ptrRef11 = ptrN;
    }
}

void agregarDer(struct Dato dato, struct Nodo **ptrRef11, struct Nodo **ptrRef22) {
    struct Nodo *ptrN = crearNodo(dato);
    if (*ptrRef11 == NULL && *ptrRef22 == NULL) {
        *ptrRef11 = ptrN;
        *ptrRef22 = ptrN;
    } else {
        ptrN->ptrAnt = *ptrRef22;
        (*ptrRef22)->ptrSig = ptrN;
        *ptrRef22 = ptrN;
    }
}

struct Dato eliminarIzq(struct Nodo **ptrRef11, struct Nodo **ptrRef22) {
    struct Dato dato;
    if (*ptrRef11 != NULL) {
        struct Nodo *ptrBorr = *ptrRef11;
        dato = ptrBorr->dato;
        if (ptrBorr->ptrSig != NULL) {
            *ptrRef11 = ptrBorr->ptrSig;
            (*ptrRef11)->ptrAnt = NULL;
        } else {
            *ptrRef11 = NULL;
            *ptrRef22 = NULL;
        }
        free(ptrBorr);
    } else {
        printf("La pila esta vacia\n");
    }
    return dato;
}

struct Dato eliminarDer(struct Nodo **ptrRef11, struct Nodo **ptrRef22) {
    struct Dato dato;
    if (*ptrRef22 != NULL) {
        struct Nodo *ptrBorr = *ptrRef22;
        dato = ptrBorr->dato;
        if (ptrBorr->ptrAnt != NULL) {
            *ptrRef22 = ptrBorr->ptrAnt;
            (*ptrRef22)->ptrSig = NULL;
        } else {
            *ptrRef11 = NULL;
            *ptrRef22 = NULL;
        }
        free(ptrBorr);
    } else {
        printf("La pila esta vacia\n");
    }
    return dato;
}

void imprimirDato(struct Dato *dato) {
    printf("El nombre es %s", dato->nombre);
    printf("La edad es %s", dato->edad);
}

struct Dato crearDato() {
    struct Dato dato;
    printf("Escribe el nombre: ");
    fgets(dato.nombre, 30 ,stdin);
    printf("Escribe la edad: ");
    scanf("%d", &dato.edad);

    return dato;
}

int menu() {
    int opt = 0;
    printf("Menu de opciones");
    printf(" 1. Agregar en izquierda\n");
    printf(" 2. Agregar en derecha\n");
    printf(" 3. Eliminar en izquierda\n");
    printf(" 4. Eliminar en derecha\n");
    printf(" 5. Salir\n");
    printf("Escribe la opcion a elegir: ");
    scanf("%d", &opt);
    
    return opt;
}