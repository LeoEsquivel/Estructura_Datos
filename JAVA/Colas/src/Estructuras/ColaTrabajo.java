package Estructuras;

public class ColaTrabajo implements ColaProceso {

    private class NodoProceso {
        public Trabajo trabajo;
        public NodoProceso siguiente;

        public NodoProceso(Trabajo trabajo) {
            this.trabajo = trabajo;
            this.siguiente = null;
        }
    }

    private NodoProceso cabeza, ultimo;

    @Override
    public void encolar(Trabajo t) {
        NodoProceso trabajo = new NodoProceso(t);
        if(cabeza == null) {
            cabeza = ultimo = trabajo;
        } else {
            ultimo.siguiente = trabajo;
            ultimo = trabajo;    
        }
    }

    @Override
    public void eliminar() {
        if (cabeza != null) {
            NodoProceso trabajo_done = cabeza;
            cabeza = trabajo_done.siguiente;
            trabajo_done.siguiente = null;
            if (cabeza == null) {
                ultimo = null;
            }
        }
    }

    @Override
    public Trabajo obtener() {
        if (cabeza == null) {
            return null;
        } else {
            return cabeza.trabajo;
        }
    }

    @Override
    public Trabajo despachar() {
        if (cabeza == null) return null;

        NodoProceso trabajo_done = cabeza;
        cabeza = trabajo_done.siguiente;
        trabajo_done.siguiente = null;
        if (cabeza == null) {
            ultimo = null;
        }
        return trabajo_done.trabajo;
            
    }
    
}
