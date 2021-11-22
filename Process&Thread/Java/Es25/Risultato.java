public class Risultato {
    private int risultato;

    public Risultato() {
        this.risultato = 0;
    }

    public void accumola(int value) {
        this.risultato += value;
    }

    public int getRisultato() {
        return risultato;
    }
}
