#include "funciones.h"

void limpiarCadena(char *cadena) {
    int len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n') 
        cadena[len - 1] = '\0';
    cadena[len] = '\0'; // Eliminar el salto de línea al final
}

int menu(){
    int opc;
    printf("\nSistema de Gestión de Biblioteca:\n");
    printf("=====================================\n");
    printf("1. Crear Libros\n");
    printf("2. Crear Autores\n");
    printf("3. Listar Libros\n");
    printf("4. Listar Autores\n");
    printf("5. Crear Prestamos\n");
    printf("6. Listar Prestamos\n");
    printf("7. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc);
    fflush(stdin); // Limpiar el buffer de entrada
    return opc;
}

void crearLibros(){
    struct Libro libros[] = {{1,"Cien años de soledad","Realismo mágico",1,1},
                            {2,"Don Quijote de la Mancha","Clásico",1,2},
                            {3,"El amor en los tiempos del cólera","Romance",1,1},
                            {4,"1984","Distopía",1,3},
                            {5,"Rebelión en la granja","Fábula política",1,3},
                            {6,"El Principito","Infantil",1,4},
                            {7,"Crónica de una muerte anunciada","Novela",1,1},
                            {8,"La casa de los espíritus","Realismo mágico",1,5},
                            {9,"Rayuela","Experimental",1,6},
                            {10,"Pedro Páramo","Realismo mágico",1,7},
                            {11,"La ciudad y los perros","Novela social",1,8},
                            {12,"Conversación en La Catedral","Novela política",1,8},
                            {13,"Cien sonetos de amor","Poesía",1,9},
                            {14,"Veinte poemas de amor","Poesía",1,9},
                            {15,"El túnel","Psicológica",1,10},
                            {16,"Sobre héroes y tumbas","Novela",1,10},
                            {17,"Ficciones","Cuentos",1,11},
                            {18,"El Aleph","Cuentos fantásticos",1,11},
                            {19,"La tregua","Romance",1,12},
                            {20,"Gracias por el fuego","Drama",1,12},
                            {21,"Los pasos perdidos","Novela",1,13},
                            {22,"El reino de este mundo","Realismo mágico",1,13},
                            {23,"La vorágine","Novela de la selva",1,14},
                            {24,"María","Romance",1,15},
                            {25,"Doña Bárbara","Novela criollista",1,16}};
    guardarLibros(libros, 25);
    printf("Libros creados y guardados correctamente.\n");
}

void imprimirLibros(struct Libro libros[], int numLibros){
    printf("\nCatálogo de Libros:\n");
    printf("=====================================\n");
    for (int i = 0; i < numLibros; i++) {
        printf("ID: %d, Título: %s, Género: %s, Disponible: %s\n", 
               libros[i].id, libros[i].titulo, 
               libros[i].genero, libros[i].disponible ? "Sí" : "No");
    }
}

void guardarLibros(struct Libro libros[], int numLibros){
    FILE *archivo = fopen("libros.dat", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar los libros.\n");
        return;
    }
    fwrite(libros, sizeof(struct Libro), numLibros, archivo);
    fclose(archivo);
}

int cargarLibros(struct Libro libros[], int *numLibros) {
    FILE *archivo = fopen("libros.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de libros.\n");
        return 0;
    }
    *numLibros = fread(libros, sizeof(struct Libro), 50, archivo);
    fclose(archivo);
    return 1;
}

void crearAutores(){
    struct Autor autores[] = {{1,"Gabriel García Márquez","Colombiana",1927},
                             {2,"Miguel de Cervantes","Española",1547},
                             {3,"George Orwell","Británica",1903},
                             {4,"Antoine de Saint-Exupéry","Francesa",1900},
                             {5,"Isabel Allende","Chilena",1942},
                             {6,"Julio Cortázar","Argentina",1914},
                             {7,"Juan Rulfo","Mexicana",1917},
                             {8,"Mario Vargas Llosa","Peruana",1936},
                             {9,"Pablo Neruda","Chilena",1904},
                             {10,"Ernesto Sabato","Argentina",1911},
                             {11,"Jorge Luis Borges","Argentina",1899},
                             {12,"Mario Benedetti","Uruguaya",1920},
                             {13,"Alejo Carpentier","Cubana",1904},
                             {14,"José Eustasio Rivera","Colombiana",1888},
                             {15,"Jorge Isaacs","Colombiana",1837},
                             {16,"Rómulo Gallegos","Venezolana",1884}};
    guardarAutores(autores, 16);
    printf("Autores creados y guardados correctamente.\n");
}

void imprimirAutores(struct Autor autores[], int numAutores){
    printf("\nLista de Autores:\n");
    printf("=====================================\n");
    for (int i = 0; i < numAutores; i++) {
        printf("ID: %d, Nombre: %s, Nacionalidad: %s, Año de Nacimiento: %d\n", 
               autores[i].id, autores[i].nombre, 
               autores[i].nacionalidad, autores[i].anioNacimiento);
    }
}

void guardarAutores(struct Autor autores[], int numAutores){
    FILE *archivo = fopen("autores.dat", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar los autores.\n");
        return;
    }
    fwrite(autores, sizeof(struct Autor), numAutores, archivo);
    fclose(archivo);
}

int leerAutores(struct Autor autores[], int *numAutores) {
    FILE *archivo = fopen("autores.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de autores.\n");
        return 0;
    }
    *numAutores = fread(autores, sizeof(struct Autor), 20, archivo);
    fclose(archivo);
    return 1;
}

void crearPrestamos(){
    struct Prestamo prestamos[] = {{1,1,"Ana García","2024-01-15","2024-02-15",1},
                                  {2,3,"Carlos López","2024-01-20","2024-02-20",1},
                                  {3,5,"María Rodríguez","2024-02-01","2024-03-01",1},
                                  {4,7,"Juan Pérez","2024-02-10","2024-03-10",0},
                                  {5,9,"Laura Martín","2024-02-15","2024-03-15",1},
                                  {6,11,"Diego Silva","2024-03-01","2024-04-01",1},
                                  {7,13,"Carmen Ruiz","2024-03-05","2024-04-05",0},
                                  {8,15,"Roberto Díaz","2024-03-10","2024-04-10",1}};
    guardarPrestamos(prestamos, 8);
    printf("Prestamos creados y guardados correctamente.\n");
}

void imprimirPrestamos(struct Prestamo prestamos[], int numPrestamos){
    printf("\nLista de Prestamos:\n");
    printf("=====================================\n");
    for (int i = 0; i < numPrestamos; i++) {
        printf("ID: %d, Libro ID: %d, Usuario: %s, Fecha Prestamo: %s, Estado: %s\n", 
               prestamos[i].id, prestamos[i].libroId, 
               prestamos[i].nombreUsuario, prestamos[i].fechaPrestamo,
               prestamos[i].activo ? "Activo" : "Devuelto");
    }
}

void guardarPrestamos(struct Prestamo prestamos[], int numPrestamos){
    FILE *archivo = fopen("prestamos.dat", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar los prestamos.\n");
        return;
    }
    fwrite(prestamos, sizeof(struct Prestamo), numPrestamos, archivo);
    fclose(archivo);
}

int leerPrestamos(struct Prestamo prestamos[], int *numPrestamos) {
    FILE *archivo = fopen("prestamos.dat", "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de prestamos.\n");
        return 0;
    }
    *numPrestamos = fread(prestamos, sizeof(struct Prestamo), 30, archivo);
    fclose(archivo);
    return 1;
}
