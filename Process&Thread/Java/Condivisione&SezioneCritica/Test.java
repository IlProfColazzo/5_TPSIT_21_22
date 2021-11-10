import java.util.Random;

public class Test {

    public static void main(String[] args) throws InterruptedException {

        Posti postiDiponibili = new Posti(10);

        MioThread cassa1 = new MioThread(1,postiDiponibili,3);
        MioThread cassa2 = new MioThread(1,postiDiponibili,9);

        cassa1.start();
        cassa2.start();
        cassa1.join();
        cassa2.join();

        /*Eseguendo il programma diverse volte, potremmo avere un valore di posti residui negativo*/
        System.out.println("Posti residui: "+postiDiponibili.getPostiDisponibili());

    }
}
