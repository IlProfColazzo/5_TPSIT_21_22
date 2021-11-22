import java.util.Scanner;

public class Input extends Thread{
    private  Operandi operandi;

    public Input(Operandi operandi) {
        this.operandi = operandi;
    }

    @Override
    public void run() {
        Scanner s = new Scanner(System.in);
        System.out.print("Dammi il valore del primo operando: ");
        int a = s.nextInt();
        operandi.setA(a);
        System.out.print("Dammi il valore del secondo operando: ");
        int b = s.nextInt();
        operandi.setB(b);
    }
}
