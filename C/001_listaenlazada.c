#include "./estructuras/lista.h"
#include <stdlib.h>
#include <string.h>

Nodo* CrearNodo(Libro* libro) {
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
    strncpy(nodo->libro.titulo, libro->titulo, 50);
    strncpy(nodo->libro.autor, libro->autor, 50);
    strncpy(nodo->libro.isbn, libro->isbn, 13);
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo) {
    free(nodo);
}

void InsertarInicio(Lista* lista, Libro* libro) {
    Nodo* nuevo_libro = CrearNodo(libro);
    nuevo_libro->siguiente = lista->cabeza;
    lista->cabeza = nuevo_libro;
    lista->longitud++;
}

void InsertarFinal(Lista* lista, Libro* libro) {
    Nodo* nuevo_libro = CrearNodo(libro);

    if(lista->cabeza == NULL) {
        lista->cabeza = nuevo_libro;
    } else {
        Nodo* puntero = lista->cabeza;
        while (puntero->siguiente) {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nuevo_libro;
    }
    lista->longitud++;
}

void InsertarDespues(int n, Lista* lista, Libro* libro) {
    Nodo* nuevo_libro = CrearNodo(libro);
    if(lista->cabeza == NULL) {
        lista->cabeza = nuevo_libro;
    } else {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;
        while (posicion < n && puntero->siguiente) {
            puntero = puntero->siguiente;
            posicion++;
        }

        nuevo_libro->siguiente = puntero->siguiente;
        puntero->siguiente = nuevo_libro;
    }
    lista->longitud++;
}

Libro* Obtener(int n, Lista* lista) {
    if (lista->cabeza == NULL) {
        return NULL;
    } else {
        int posicion = 0;
        Nodo* puntero = lista->cabeza;
        while (posicion < n && puntero->siguiente){
            puntero = puntero->siguiente;
            posicion++;
        }

        if (posicion != n) {
            return NULL;
        } else {
            return &(puntero->libro);

        }
    }
}

int Contar(Lista* lista) {
    //Versión comun que recorre la lista de libros.
    // if (lista->cabeza == NULL) { 
    //     return 0;
    // } else {
    //     int contador = 0;
    //     Nodo* puntero = lista->cabeza;
    //     while (puntero->siguiente) {
    //         puntero = puntero->siguiente;
    //         contador++;
    //     }
    //     return contador;
    // }

    return lista->longitud;
}

void EliminarPrincipio(Lista* lista) {
    if (lista->cabeza) {
        Nodo* actual_cabeza = lista->cabeza;
        lista->cabeza = actual_cabeza->siguiente;
        DestruirNodo(actual_cabeza);
        lista->longitud--;
    }
}

void EliminarFinal(Lista* lista) {
    if (lista->cabeza) {
        // Primera versión.
        Nodo* puntero = lista->cabeza;
        // Nodo* puntero_temp = NULL;
        // while (puntero->siguiente) {
        //     puntero_temp = puntero;
        //     puntero = puntero->siguiente;
        // }
        // puntero_temp->siguiente = NULL;
        // DestruirNodo(puntero);
        // lista->longitud--;
        if (lista->cabeza->siguiente) {
            while (puntero->siguiente->siguiente) {
                puntero = puntero->siguiente;
            }

            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        } else {
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        }
    }
}

void EliminarLista(Lista* lista) {
    Nodo* puntero = lista->cabeza;
    while (puntero->siguiente) {
        Nodo* temp = puntero;
        puntero = puntero->siguiente;
        DestruirNodo(temp);
    }
    
}

void EliminarElemento(int n, Lista* lista) {
    if (lista->cabeza) {
        if (n == 0) {
            Nodo* eliminado = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;
        } else if (n < lista->longitud) {
            int posicion = 0;
            Nodo* puntero = lista->cabeza;
            //Primera version
            // Nodo* puntero_temp = NULL;

            // while (posicion < n && puntero->siguiente){
            //     puntero_temp = puntero;
            //     puntero = puntero->siguiente;
            //     posicion++;
            // }
            // if (posicion != n) {
            //     return;
            // } else {
            //     puntero_temp->siguiente = puntero->siguiente;
            //     DestruirNodo(puntero);
            //     lista->longitud--;
            // }

            while (posicion < (n-1)) {
                puntero = puntero->siguiente;
                posicion++;
            }
            Nodo* eliminado = puntero->siguiente;
            puntero->siguiente = eliminado->siguiente;
            DestruirNodo(eliminado);
            lista->longitud--;
            
        }
        
    }
}

void ImprimirLista(Lista* lista) {
    if (lista->cabeza) {
        Nodo* puntero = lista->cabeza;
        int contador = 0;
        while (contador < lista->longitud) {
            printf("%s -> ", puntero->libro.titulo);
            puntero = puntero->siguiente;
            contador++;
        }
    }
}

int main() {
    int num_libros = 5;
    Libro* libros = malloc(num_libros* sizeof(Libro));

    for (int i=0; i<num_libros; i++) {
        snprintf(libros[i].titulo, sizeof(libros[i].titulo), "Titulo %d", i+1);
        snprintf(libros[i].autor, sizeof(libros[i].titulo), "Autor %d", i+1);
        snprintf(libros[i].isbn, sizeof(libros[i].titulo), "ISBN %d", i+1);
    }
    Lista* lista = malloc(sizeof(Lista));
    lista->cabeza = CrearNodo(&libros[0]);
    lista->longitud = 1;
    for (int i=1; i<num_libros; i++) {
        Nodo* libro = CrearNodo(&libros[i]);
        InsertarFinal(lista, &libro->libro);
    }
    ImprimirLista(lista);

    Libro* libro_prueba = malloc(sizeof(Libro));
    strcpy(libro_prueba->titulo, "El Gran Gatsby");
    strcpy(libro_prueba->autor, "F. Scott Fitzgerald");
    strcpy(libro_prueba->isbn, "1234567890");

    //INSERTAR AL INICIO PRUEBA
    printf("\nProbando agregar al inicio\n");
    InsertarInicio(lista, libro_prueba);
    ImprimirLista(lista);

    //INSERTAR AL FINAL PRUEBA
    printf("\nProbando agregar al final\n");
    InsertarFinal(lista, libro_prueba);
    ImprimirLista(lista);

    //INSERTAR DESPUES
    printf("\nProbando agregar en medio\n");
    InsertarDespues(3, lista, libro_prueba);
    ImprimirLista(lista);

    //OBTENER
    printf("\nObteniendo libro posicion %d\n", 3);
    Libro* num_3 = Obtener(3, lista);
    printf("%s\n", num_3->titulo);
    printf("%s\n", num_3->autor);
    printf("%s\n", num_3->isbn);

    //CONTAR
    printf("\nEl numero de elementos en la lista es de: %d\n", lista->longitud);

    //ELIMINAR INICIO
    printf("\nEliminando el inicio\n");
    EliminarPrincipio(lista);
    ImprimirLista(lista);

    //ELIMINAR FINAL
    printf("\nEliminando el final\n");
    EliminarFinal(lista);
    ImprimirLista(lista);

    //ELIMINAR ELEMENTO
    printf("\nEliminando libro posicion %d\n", 3);
    EliminarElemento(3, lista);
    ImprimirLista(lista);

    EliminarLista(lista);

    free(libros);
    free(lista);
    free(libro_prueba);
    return 0;
}