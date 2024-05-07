struct Dato {
  int arreglo[5];
  int *ptr;
};

int main() {
  struct Dato dato;

  for(dato.ptr = dato.arreglo; dato.ptr < &dato.arreglo[5]; dato.ptr++) {
    printf("Ingrese el entero: ");
    scanf("%d", dato.ptr);
  }

  for(dato.ptr = dato.arreglo; dato.ptr < &dato.arreglo[5]; dato.ptr++) 
    printf("En la celda %d con el dato %d en la direccion %ld",(int) (dato.ptr - dato.arreglo), *dato.ptr, dato.ptr);

}