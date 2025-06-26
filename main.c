#include <stdio.h>
#include "funciones.h"

int main() {

    struct Libro libros[50];
    struct Autor autores[20];
    struct Prestamo prestamos[30];
    int numLibros = 0;
    int numAutores = 0;
    int numPrestamos = 0;

    int opc;
    do
    {
        opc = menu();
        switch (opc)
        {
            case 1:
                crearLibros();
                printf("Libros creados correctamente.\n");
                break;
            case 2:
                crearAutores();
                printf("Autores creados correctamente.\n");
                break;
            case 3:
                if(cargarLibros(libros, &numLibros)) {
                    imprimirLibros(libros, numLibros);
                } else {
                    printf("No se pudieron cargar los libros.\n");
                }
                break;
            case 4:
                if(leerAutores(autores, &numAutores)) {
                    imprimirAutores(autores, numAutores);
                } else {
                    printf("No se pudieron cargar los autores.\n");
                }
                break;
            case 5:
                crearPrestamos();
                printf("Prestamos creados correctamente.\n");
                break;
            case 6:
                if(leerPrestamos(prestamos, &numPrestamos)) {
                    imprimirPrestamos(prestamos, numPrestamos);
                } else {
                    printf("No se pudieron cargar los prestamos.\n");
                }
                break;
            case 7:
                printf("Saliendo del sistema de biblioteca.\n");
                break;
            default:
                printf("Opción no válida. Por favor, intente de nuevo.\n");
                break;
        }

    } while (opc!= 7);
    
    
    return 0;
}
