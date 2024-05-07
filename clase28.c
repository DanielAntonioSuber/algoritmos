// Lista. Los nodos que se insertan es de acuerdo a un orden (ascendente o descendete) conforme a un campo de la structura denominado clave o llave (key)

// List con enlace esimple (orden ascendente)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Datos
{
    char nombre[30];
    int edad;
};

struct Nodo
{
    int clave;
    struct Datos datos;
    struct Nodo *ptrSig;
};

struct Nodo *crearNodo(int clave);
void meterNodo(struct Nodo *ptrRef, int clave);
void eliminarNodo(struct Nodo *ptrRef, int clave);
void imprimirLista(struct Nodo *ptrRef);
int menu();

int main()
{
    struct Nodo *ptrRef;
    int opt = 0;
    int clave = 0;
    ptrRef = crearNodo(-1000);

    while (opt != 4)
    {
        opt = menu();

        switch (opt)
        {
        case 1:
            printf("Escribe la clave que desea insertar: ");
            scanf("%d", &clave);
            meterNodo(ptrRef, clave);

            break;
        case 2:
            printf("Escribe la clave que desea eliminar: ");
            scanf("%d", &clave);
            eliminarNodo(ptrRef, clave);
            break;
        case 3:
            imprimirLista(ptrRef);
            break;

        default:
            break;
        }
    }
    return 0;
}

struct Nodo *crearNodo(int clave)
{
    struct Nodo *ptrN;
    ptrN = (struct Nodo *)malloc(sizeof(struct Nodo));
    ptrN->ptrSig = NULL;
    ptrN->clave = clave;
    return ptrN;
}

void meterNodo(struct Nodo *ptrRef, int clave)
{
    struct Nodo *ptrN = crearNodo(clave);

    if (ptrRef->ptrSig == NULL || ptrN->clave < ptrRef->ptrSig->clave)
    {
        ptrN->ptrSig = ptrRef->ptrSig;
        ptrRef->ptrSig = ptrN;
    }
    else
    {
        struct Nodo *ptrRet = ptrRef;
        struct Nodo *ptrAv = ptrRef->ptrSig;

        while (ptrAv != NULL && ptrN->clave > ptrAv->clave)
        {
            ptrRet = ptrAv;
            ptrAv = ptrAv->ptrSig;
        }

        ptrN->ptrSig = ptrAv;
        ptrRet->ptrSig = ptrN;
    }
}

// Mientras ptrAv != NULL => checamos ptrRet -> clave > ptrN -> clave && ptrN -> clave < ptrAv -> clave (para agregarlo) ptrN -> ptrSig = ptrAv; ptrRet -> ptrSig = ptrN;

// Para elimnar Nodo se tiene que realizar un match la clave dada
void eliminarNodo(struct Nodo *ptrRef, int clave)
{
    struct Nodo *ptrRet = ptrRef;
    struct Nodo *ptrAv = ptrRef->ptrSig;

    while (ptrAv != NULL)
    {
        if (ptrAv->clave == clave)
        {
            struct Nodo *ptrBas = ptrAv;
            ptrRet->ptrSig = ptrBas->ptrSig;

            free(ptrBas);
            return;
        }

        ptrRet = ptrRet->ptrSig;
        ptrAv = ptrAv->ptrSig;
    }
}

void imprimirLista(struct Nodo *ptrRef)
{
    struct Nodo *ptrAv;
    ptrAv = ptrRef->ptrSig;

    while (ptrAv != NULL)
    {
        printf("%d ", ptrAv->clave);
        ptrAv = ptrAv->ptrSig;
    }
    printf("\n");
}

int menu()
{
    int opt = 0;
    printf("Menu de opciones\n");
    printf(" 1. Meter nodo\n");
    printf(" 2. Eliminar nodo\n");
    printf(" 3. Imprimir lista\n");
    printf(" 4. Salir\n");
    printf("Escribe la opcion: ");
    scanf("%d", &opt);

    return opt;
}
