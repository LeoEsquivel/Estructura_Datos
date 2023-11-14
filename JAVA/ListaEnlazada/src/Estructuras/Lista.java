package Estructuras;

public class Lista {
    
    private Nodo cabeza = null;
    private int longitud = 0;

    private class Nodo {
        public Libro libro;
        public Nodo siguiente = null;
        
        public Nodo(Libro libro) {
            this.libro = libro;
        }
    }

    public int getLongitud() { return longitud; }

    public void insertarPrincipio(Libro libro) {
        Nodo nodo = new Nodo(libro);
        nodo.siguiente = cabeza;
        cabeza = nodo;
        longitud++;
    }

    public void insertarFInal(Libro libro) {
        Nodo nodo = new Nodo(libro);
        Nodo puntero = cabeza;
        while (puntero.siguiente != null) {
            puntero = puntero.siguiente;
        }
        puntero.siguiente = nodo;
        longitud++;
    }

    public void insertarDespues(int n, Libro libro) {
        Nodo nuevo_libro = new Nodo(libro);
        if (cabeza == null) {
            cabeza = nuevo_libro;
        } else {
            Nodo puntero = cabeza;
            int posicion = 0;
            while (posicion < n && puntero.siguiente != null) {
                puntero = puntero.siguiente;
                posicion++;
            }
            nuevo_libro.siguiente = puntero.siguiente;
            puntero.siguiente = nuevo_libro;
        }
        longitud++;
    }

    public Libro obtener(int n) {
        if (cabeza == null) {
            return null;
        } else {
            Nodo puntero = cabeza;
            int posicion = 0;
            while (posicion < n && puntero.siguiente != null) {
                puntero = puntero.siguiente;
                posicion++;
            }

            if (posicion != n) {
                return null;
            } else {
                return puntero.libro;
            }
        }
    }

    public int contarLibros() {
        return longitud;
    }
    
    public boolean estaVacia() {
        return cabeza == null;
    }

    public void eliminarPrincipio() {
        if (cabeza != null) {
            Nodo actual_cabeza = cabeza;
            cabeza = actual_cabeza.siguiente;
            actual_cabeza.siguiente = null;
            longitud--;
        }
    }

    public void eliminarUltimo() {
        if (cabeza != null) {
            if(cabeza.siguiente == null) {
                cabeza = null;
            } else {
                Nodo puntero = cabeza;
                while (puntero.siguiente.siguiente != null) {
                    puntero = puntero.siguiente;
                }
                puntero.siguiente = null;
                longitud--;
            }
        }
    }

    public void eliminarEntre(int n) {
        if (cabeza == null) return;

        if (n < longitud) return; 

        if (n == 0) {
            eliminarPrincipio();
        } else {
            Nodo puntero = cabeza;
            int posicion = 0;
            while (posicion < (n-1) && puntero.siguiente != null) {
                puntero = puntero.siguiente;
                posicion++;
            }
            
            if (posicion != n) {
                return;
            } else {
                Nodo temp = puntero.siguiente;
                puntero.siguiente = temp.siguiente;
                temp.siguiente = null; 
                longitud--;
            }
        }
    }

    public void imprimirLista() {
        if (cabeza != null) {
            Nodo puntero = cabeza;
            int contador = 0;
            while (contador < longitud) {
                System.out.println(puntero.libro.getTitulo() + " -> ");
                puntero = puntero.siguiente;
                contador++;
            }
        }
    }

}
