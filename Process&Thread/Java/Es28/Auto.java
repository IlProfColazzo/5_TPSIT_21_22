public class Auto {

    private int velocitaAttuale;

    public Auto() {
        this.velocitaAttuale = 0;
    }

    public Auto(int velocitaAttuale) {
        this.velocitaAttuale = velocitaAttuale;
    }

    public synchronized void accelera(int velocitaUp) {
        if(this.velocitaAttuale + velocitaUp <= 180) {
            this.velocitaAttuale += velocitaUp;
            System.out.println("Accelerato, velocità attuale " + this.velocitaAttuale);
        }
    }

    public synchronized void decelera(int velocitaDown) {
        if (this.velocitaAttuale - velocitaDown >= 0) {
            this.velocitaAttuale -= velocitaDown;
            System.out.println("Decelerato, velocità attuale " + this.velocitaAttuale);
        }
    }
}
