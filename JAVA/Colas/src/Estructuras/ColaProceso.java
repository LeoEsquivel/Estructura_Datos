package Estructuras;

public interface ColaProceso {
    
    void encolar(Trabajo t);

    void eliminar();

    Trabajo obtener();

    Trabajo despachar();
}
