import java.util.Scanner;

public class Test {

    public static void main(String[] args) throws InterruptedException {

        Auto auto = new Auto();

        new Game(auto,'A').start();
        new Game(auto,'A').start();
        new Game(auto,'D').start();
        new Game(auto,'D').start();

    }
}
