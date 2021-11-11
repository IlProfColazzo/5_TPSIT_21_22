import java.util.Scanner;
public class Test {
    public static void main (String[] args) throws InterruptedException {
        Scanner in = new Scanner(System.in);
        System.out.print("Iserisci il primo numero: ");
        int num1 = in.nextInt();
        System.out.print("Iserisci il secondo numero: ");
        int num2 = in.nextInt();
        MioThread t1 = new MioThread(num1); //creo un oggetto MioThread
        MioThread t2 = new MioThread(num2); //creo un oggetto MioThread
        Thread r1 = new Thread(t1); //creo un oggetto Thread
        Thread r2 = new Thread(t2); //creo un oggetto Thread
        r1.start(); //mando in esecuzione il thread
        r2.start(); //mando in esecuzione il thread
        r1.join();
        r2.join();
    }
}
