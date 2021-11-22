import java.util.Scanner;

public class MainClass {

    public static void main(String[] args) throws InterruptedException {


        Operandi operandi = new Operandi();
        Input threadInput = new Input(operandi);
        threadInput.start();
        threadInput.join(); //è necessario attendere la terminazione della lettura prima di procedere
        Calcolatrice somma = new Calcolatrice(operandi,'+');
        Calcolatrice differenza = new Calcolatrice(operandi,'-');
        Calcolatrice prodotto = new Calcolatrice(operandi,'*');
        Calcolatrice rapporto = new Calcolatrice(operandi,'/');
        somma.start();
        differenza.start();
        prodotto.start();
        rapporto.start();


    }
}
