import java.io.IOException;

public class MainClient {

    public static void main(String[] args) throws IOException {
        Client c = new Client("127.0.0.1", 7000);
        c.connect();
        /*
        *
        * Insert here your protocol and algorithm
        *
        * */

        c.close();

    }

}