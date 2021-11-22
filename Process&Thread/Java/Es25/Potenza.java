public class Potenza extends Thread {

    private Risultato r;
    private int esponente;

    public Potenza(Risultato r, int esponente) {
        this.r = r;
        this.esponente = esponente;
    }

    @Override
    public void run() {
        r.accumola((int) Math.pow(2, this.esponente));
    }
}
