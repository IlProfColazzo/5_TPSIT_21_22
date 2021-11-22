public class Auto {

    private int velocitaAttuale;

    public Auto() {
        this.velocitaAttuale = 0;
    }

    public Auto(int velocitaAttuale) {
        this.velocitaAttuale = velocitaAttuale;
    }

    public void accelera(int velocitaUp) {
        this.velocitaAttuale += velocitaUp;
        System.out.println("Accelerato, velocità attuale " + this.velocitaAttuale);
    }

    public void decelera(int velocitaDown) {
        this.velocitaAttuale -= velocitaDown;
        System.out.println("Decelerato, velocità attuale " + this.velocitaAttuale);
    }

}
