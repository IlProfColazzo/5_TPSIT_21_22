import java.util.Scanner;

public class Test {

    public static void main(String[] args) throws InterruptedException {

        Auto auto = new Auto();
        
        Game game1 = new Game(auto,'A');
        Game game2 = new Game(auto,'A');
        Game game3 = new Game(auto,'D');
        Game game4 = new Game(auto,'D');

        game1.start();
        game2.start();
        game3.start();
        game4.start();

    }
}
