#include "./estructuras/colas.h"

int main() {
    //Crea la cola;
    Cola* cola = crearCola();

    //Crear pedido
    Pedido* pedido = (Pedido*) malloc(sizeof(Pedido));
    pedido->id_cliente = 123;

    //Crear una linea de pedido
    LineaPedido linea;
    linea.id_producto = 456;
    linea.cantidad = 2;
    linea.precio_unidad = 12.34;

    //Crear nodo linea/pedido
    NodoLineaPedido* nodo_linea = (NodoLineaPedido*) malloc(sizeof(NodoLineaPedido));
    nodo_linea->linea = linea;
    nodo_linea->lista_productos = nodo_linea;

    encolar(cola, pedido);    

    //Consultar
    Pedido* consulta = consultar(cola);
    if (consulta != NULL) {
        printf("Primer pedido en la cola\n ID CLIENTE: %d\n", consulta->id_cliente);
    }

    //Despachar
    Pedido* despachado = despachar(cola);
    if (despachado != NULL) {
        printf("Pedido despachado\n ID CLIENTE: %d\n", despachado->id_cliente);
    }

    //Destruir cola
    destruirCola(cola);
}