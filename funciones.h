#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Libro {
    int id;
    char titulo[100];
    char genero[50];
    int disponible; // 1 disponible, 0 prestado
    int autorId;
};

struct Autor {
    int id;
    char nombre[100];
    char nacionalidad[50];
    int anioNacimiento;
};

struct Prestamo {
    int id;
    int libroId;
    char nombreUsuario[100];
    char fechaPrestamo[20];
    char fechaDevolucion[20];
    int activo; // 1 activo, 0 devuelto
};

// Función para limpiar cadenas
void limpiarCadena(char *cadena);

// Funciones del menú
int menu();

// Funciones para libros
void crearLibros();
void imprimirLibros(struct Libro libros[], int numLibros);
void guardarLibros(struct Libro libros[], int numLibros);
int cargarLibros(struct Libro libros[], int *numLibros);

// Funciones para autores
void crearAutores();
void imprimirAutores(struct Autor autores[], int numAutores);
void guardarAutores(struct Autor autores[], int numAutores);
int leerAutores(struct Autor autores[], int *numAutores);

// Funciones para prestamos
void crearPrestamos();
void imprimirPrestamos(struct Prestamo prestamos[], int numPrestamos);
void guardarPrestamos(struct Prestamo prestamos[], int numPrestamos);
int leerPrestamos(struct Prestamo prestamos[], int *numPrestamos);

#endif
