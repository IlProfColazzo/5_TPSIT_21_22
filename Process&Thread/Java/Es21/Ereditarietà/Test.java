import  java.util.Random;
public class Test {
    public static void main (String[] args) {
        MioThread t1 = new MioThread(); //creo un thread
        t1.start(); //mando in esecuzione il thread
        Random r = new Random();
        int secondi = r.nextInt(100) + 16; //genero un numero da 16 a 116
        try {
            Thread.sleep(secondi * 1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
