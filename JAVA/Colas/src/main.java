import Estructuras.ColaTrabajo;
import Estructuras.Trabajo;

public class main {
    public static void main(String[] args) {
        
        ColaTrabajo cola = new ColaTrabajo();
        
        // Crear algunos trabajos
        Trabajo trabajo1 = new Trabajo("Revisar favoritos", "Leo", "AXT-12S");
        Trabajo trabajo2 = new Trabajo("Testing API", "Daniel", "Q2E-3S4");
        Trabajo trabajo3 = new Trabajo("Cenar", "Leo Esquivel", "T4M-U1L");

        //Encolar trabajos
        cola.encolar(trabajo1);
        cola.encolar(trabajo2);
        cola.encolar(trabajo3);

        while (cola.obtener() != null) {
            Trabajo trabajo = cola.despachar();
            System.out.println("Despachando el trabajo: " + trabajo.getTitulo() + ", Autor: " + trabajo.getAutor() + ", Impreso: " + trabajo.getImpreso());
        }
    }
}
