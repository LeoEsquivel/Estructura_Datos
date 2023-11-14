#ifndef cola_h
#define cola_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pedido.h"

typedef struct NodoPedido {
    Pedido* pedido;
    struct NodoPedido* siguiente;
} NodoPedido;

typedef struct Cola {
    NodoPedido* primero;
    NodoPedido* ultimo;
} Cola;

NodoPedido* crearNodo(Pedido* pedido) {
    NodoPedido* nodo_pedido = (NodoPedido*) malloc(sizeof(NodoPedido));
    nodo_pedido->pedido = pedido;
    nodo_pedido->siguiente = NULL;
    return nodo_pedido;
}

void destruirNodo(NodoPedido* pedido) {
    pedido->pedido = NULL;
    pedido->siguiente = NULL;
    free(pedido);
}

Cola* crearCola() {
    Cola* cola = (Cola*) malloc(sizeof(Cola));
    cola->primero = cola->ultimo = NULL;
    return cola;
}

void encolar(Cola* cola, Pedido* pedido) {
    NodoPedido* nuevo_pedido = crearNodo(pedido);
    if (!cola->primero) {
        cola->primero = cola->ultimo = nuevo_pedido;
    } else {
        cola->ultimo->siguiente = nuevo_pedido;
        cola->ultimo = nuevo_pedido;
    }
}

Pedido* consultar(Cola* cola) {
    if (cola->primero) {
        return cola->primero->pedido;
    } else {
        return NULL;
    }
}

void eliminar(Cola* cola) {
    if (cola->primero) {
        NodoPedido* eliminado = cola->primero;
        cola->primero = eliminado->siguiente;
        destruirNodo(eliminado);  

        if (!cola->primero) {
            cola->ultimo = NULL;
        }  
    }
}

void destruirCola(Cola* cola) {
    while (cola->primero) {
        eliminar(cola);
    }
    free(cola);
}

Pedido* despachar(Cola* cola) {
    if (cola->primero) {
        NodoPedido* pedido = cola->primero;
        cola->primero = pedido->siguiente;
        pedido->siguiente = NULL;
        return pedido->pedido;        
    }
}

#endif