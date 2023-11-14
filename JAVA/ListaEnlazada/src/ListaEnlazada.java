import java.util.ArrayList;
import Estructuras.Libro;
import Estructuras.Lista;

public class ListaEnlazada {
    
    public static void main(String[] args) {
        ArrayList<Libro> libros = new ArrayList<>();


        for (int i=0; i<5; i++) {
            Libro libro = new Libro("Libro" + i, "Autor" + i, "ISBN" + i);
            libros.add(libro);
        }
        
        Lista lista = new Lista();

        //INSERTAR AL INICIO
        Libro libro_cabeza = libros.get(0);
        lista.insertarPrincipio(libro_cabeza);

        //INSERTAR AL FINAL
        for (int i=1; i<libros.size(); i++) {
            lista.insertarFInal(libros.get(i));
        }
        lista.imprimirLista();

        Libro libro_prueba = new Libro("El Gran Gatsby", "F. Scott Fitzgerald", "1234567890");

        //INSERTAR AL INICIO
        System.out.println("Probando agregar al inicio");
        lista.insertarPrincipio(libro_prueba);
        lista.imprimirLista();

        //INSERTAR DESPUES
        System.out.println("Probando agregar al inicio");
        lista.insertarDespues(3, libro_prueba);
        lista.imprimirLista();

        //OBTENER
        System.out.println("Obteniendo libro numero: " + 3);
        Libro libro_obtenido = lista.obtener(3);
        System.out.println(libro_obtenido.getTitulo());
        System.out.println(libro_obtenido.getAutor());
        System.out.println(libro_obtenido.getIsbn());

        // TAMANO DE LA LISTA
        System.out.println("El numero de elementos en la lista es de: " + lista.getLongitud());

        //ELIMINAR INICIO
        System.out.println("Eliminando inicio");
        lista.eliminarPrincipio();
        lista.imprimirLista();

        //ELIMINANDO FINAL
        System.out.println("Eliminando ultimo");
        lista.eliminarUltimo();
        lista.imprimirLista();

        //ELIMINANDO ENTRE
        System.out.println("Eliminando libro posicion: " + 3);
        lista.eliminarEntre(3);
        lista.imprimirLista();        

    }
}
