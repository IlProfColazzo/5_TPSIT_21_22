public class Test {
    public static void main (String[] args) throws InterruptedException {

        String nomiNani[] = {"Brontolo", "Cucciolo", "Dotto", "Eolo", "Gongolo", "Mammolo",  "Pisolo"};
        Nano nani[] = new Nano[7];
        Thread tri[] = new Thread[7];

        for (int i = 0; i < nani.length; i++) {
            nani[i] = new Nano(nomiNani[i]); //creo un oggetto Nano
            tri[i] = new Thread(nani[i]); //creo un oggetto Thread
        }

        //avvio tutti i Thread
        for (int i = 0; i < tri.length; i++) {
            tri[i].start();
        }

        //attendo tutti i Thread
        for (int i = 0; i < tri.length; i++) {
            tri[i].join();
        }

    }
}
