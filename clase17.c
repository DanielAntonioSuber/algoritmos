#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

struct Nodo* crearNodo(int elem);
void meterEstruct(struct Nodo *ptrRef, int elem);
void recorrerEstructIzqaDer(struct Nodo *ptrRef);
void recorrerEstructDeraIzq(struct Nodo *ptrRef);
void eliminarEstruct(struct Nodo *ptrRef);
int menu();

int main() {
    struct Nodo *miptrRef = NULL;
    int mielem;

    for (;;) {
        switch (menu()) {
            case 1:
                miptrRef = crearNodo(-1000);
                break;
            case 2:
                printf("\nIngrese un entero: ");
                scanf("%d", &mielem);
                meterEstruct(miptrRef, mielem);
                break;
            case 3:
                eliminarEstruct(miptrRef);
                break;
            case 4:
                recorrerEstructIzqaDer(miptrRef);
                break;
            case 5:
                recorrerEstructDeraIzq(miptrRef);
                break;
            case 6:
                exit(0);
        }
    }
}

struct Nodo* crearNodo(int elem) {
    struct Nodo *ptrN;
    ptrN = (struct Nodo*)malloc(sizeof(struct Nodo));
    ptrN->ptrSig = NULL;
    ptrN->ptrAnt = NULL;
    ptrN->dato = elem;
    return ptrN;
}

void meterEstruct(struct Nodo *ptrRef, int elem) {
    struct Nodo *ptrN;
    ptrN = crearNodo(elem);
    if ((ptrRef->ptrSig == NULL) && (ptrRef->ptrAnt == NULL)) {
        ptrRef->ptrSig = ptrN;
        ptrN->ptrAnt = ptrRef;
    } else {
        ptrN->ptrSig = ptrRef->ptrSig;
        ptrRef->ptrSig->ptrAnt = ptrN;
        ptrRef->ptrSig = ptrN;
        ptrN->ptrAnt = ptrRef;
    }
}

void recorrerEstructIzqaDer(struct Nodo *ptrRef) {
    struct Nodo *ptrRec, *ptrRet;
    putchar('\n');
    ptrRec = ptrRef->ptrSig;
    ptrRet = ptrRef; //!
    while (ptrRec != NULL) {
        ptrRec = ptrRec->ptrSig;
        ptrRet = ptrRet->ptrSig; //!
        printf("%d\n", ptrRet->dato); //!
    }
}

void recorrerEstructDeraIzq(struct Nodo *ptrRef) {
    struct Nodo *ptrRec, *ptrRet, *ptrRInv;
    putchar('\n');
    ptrRec = ptrRef->ptrSig;
    ptrRet = ptrRef; //!
    while (ptrRec != NULL) {
        ptrRec = ptrRec->ptrSig;
        ptrRet = ptrRet->ptrSig; //!
    }

    ptrRInv = ptrRet;
    while (ptrRInv != ptrRef) {
        printf("%d\n", ptrRInv->dato);
        ptrRInv = ptrRInv->ptrAnt;
    }
}

void eliminarEstruct(struct Nodo *ptrRef) {
    struct Nodo *ptrBorr;
    if (ptrRef->ptrSig != NULL) {
        ptrBorr = ptrRef->ptrSig;
        ptrRef->ptrSig = ptrBorr->ptrSig;
        if (ptrBorr->ptrSig != NULL) {
            ptrBorr->ptrSig->ptrAnt = ptrRef;
        }
        free(ptrBorr);
        printf("\n");
    } else {
        printf("La pila esta vacia :(\n");
    }
}

int menu() {
    int opcion;
    printf("1. Crear Nodo\n");
    printf("2. Meter Nodo\n");
    printf("3. Eliminar Nodo\n");
    printf("4. Recorrer izquierda a derecha\n");
    printf("5. Recorrer derecha a izquierda\n");
    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
