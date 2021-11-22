public class Calcolatrice extends Thread {

    private Operandi operandi;
    private char operatore;

    public Calcolatrice(Operandi operandi, char operatore) {
        this.operandi = operandi;
        this.operatore = operatore;
    }

    @Override
    public void run() {
        switch (operatore) {
            case '+':
                System.out.println("La somma vale: " + (operandi.getA() + operandi.getB()));
                break;
            case '-':
                System.out.println("La differenza vale: " + (operandi.getA() - operandi.getB()));
                break;
            case '*':
                System.out.println("Il prodotto vale: " + (operandi.getA() * operandi.getB()));
                break;
            case '/':
                System.out.println("Il quoziente vale vale: " + (operandi.getA() / operandi.getB()));
                break;
            default:
                System.out.println("Operatore non valido");
        }
    }
}
