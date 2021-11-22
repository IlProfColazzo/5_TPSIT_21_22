import java.util.Scanner;

public class Test {

    public static void main(String[] args) throws InterruptedException {

        Posti postiDiponibili = new Posti();

        Scanner scanner = new Scanner(System.in);
        System.out.println("Di quanti posti necessita la prima prenotazione?");
        int postiPrimaPrenotazione = scanner.nextInt();
        System.out.println("Di quanti posti necessita la seconda prenotazione?");
        int postiSecondaPrenotazione = scanner.nextInt();

        Prenotazione prenotazione1 = new Prenotazione(postiDiponibili, postiPrimaPrenotazione);
        Prenotazione prenotazione2 = new Prenotazione(postiDiponibili, postiSecondaPrenotazione);

        prenotazione1.start();
        prenotazione2.start();

        prenotazione1.join();
        prenotazione2.join();

    }
}
