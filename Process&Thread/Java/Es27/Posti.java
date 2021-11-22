public class Posti {

    private int postiDisponibili;

    public Posti() {
        this.postiDisponibili = 100;
    }

    public Posti(int postiDisponibili) {
        this.postiDisponibili = postiDisponibili;
    }

    public int getPostiDisponibili() {
        return this.postiDisponibili;
    }

    public void setPostiDisponibili(int i) {
        this.postiDisponibili = i;
    }

    public synchronized void prenota(int postiRichiesti) {

        //synchronized (this) {
        if (postiRichiesti <= this.postiDisponibili) {
            try {
                Thread.sleep(5000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            this.postiDisponibili -= postiRichiesti;
            System.out.println("Prenotato " + postiRichiesti + " posti; posti rimanenti = " + postiDisponibili);
        } else {
            System.out.println("Non sono disponibili abbastanza posti per soddisfare la richiesta ");
        }
        //}
    }

}
