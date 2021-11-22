import java.util.Scanner;

public class MainClass {

    public static void main(String[] args) throws InterruptedException {

        Scanner s = new Scanner(System.in);
        System.out.print("Dammi il valore di N: ");
        int N = s.nextInt();
        Risultato r = new Risultato();
        Potenza[] threads = new Potenza[N];
        for (int i = 0; i < N; i++) {
            threads[i] = new Potenza(r, i);
            threads[i].start();
        }
        for (Potenza t : threads) {
            t.join();
        }
        System.out.println("Il risultato vale: " + r.getRisultato());

    }
}
