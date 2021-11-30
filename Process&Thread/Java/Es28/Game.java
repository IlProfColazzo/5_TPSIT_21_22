import java.util.Random;

public class Game extends Thread {

    private Auto auto;
    private char ad;

    public Game(Auto auto, char ad) {
        this.auto = auto;
        this.ad = ad;
    }


    @Override
    public void run() {
        int upperbound = 31;
        Random rand = new Random();
        if (ad == 'A') {
            while (true) {
                int velocita = rand.nextInt(upperbound);
                this.auto.accelera(velocita);
            }
        } else if (ad == 'D') {
            while (true) {
                int velocita = rand.nextInt(upperbound);
                this.auto.decelera(velocita);
            }
        } else {
            System.out.println("Valore non consentito");
        }
    }
}
