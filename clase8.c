struct Dato {
  int arreglo[5];
  int i;
};

int main() {
  struct Dato dato;

  for(dato.i = 0; dato.i < 5; dato.i++) {
    printf("Ingrese el entero: ");
    scanf("%d", dato.arreglo[dato.i]);
  }

 for(dato.i = 0; dato.i < 5; dato.i++)
    printf("En la celda %d con el dato %d en la direccion %ld",(int) (dato.i), dato.arreglo[dato.i], &dato.arreglo[dato.i]);

}