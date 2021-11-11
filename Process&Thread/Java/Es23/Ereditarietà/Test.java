public class Test {
    public static void main (String[] args) throws InterruptedException {

        String nomiNani[] = {"Brontolo", "Cucciolo", "Dotto", "Eolo", "Gongolo", "Mammolo",  "Pisolo"};
        Nano nani[] = new Nano[7];
        

        for (int i = 0; i < nani.length; i++) {
            nani[i] = new Nano(nomiNani[i]); //creo un oggetto Nano
        }

        //avvio tutti i Thread
        for (int i = 0; i < nani.length; i++) {
            nani[i].start();
        }

        //attendo tutti i Thread
        for (int i = 0; i < nani.length; i++) {
            nani[i].join();
        }

    }
}
