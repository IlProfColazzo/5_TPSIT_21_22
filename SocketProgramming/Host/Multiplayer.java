import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Locale;

public class Multiplayer {


    public static void main(String[] args) throws IOException {
        InputStreamReader input = new InputStreamReader(System.in);
        BufferedReader tastiera = new BufferedReader(input);
        Socket socket = null;

        String HoC = "";
        boolean valida = false;
        while (!valida) {
            System.out.println("Vuoi hostare o connetterti ad un host?, inserire Host o Connettimi");
            HoC = tastiera.readLine().toLowerCase();

            if (HoC.equals("host")) {
                Server s = new Server(7000);
                s.waitConnection();
                socket = s.getSocket();
                valida = true;
            } else if (HoC.equals("hostami")) {
                Client c = new Client("127.0.0.1", 7000);
                c.connect();
                socket = c.getSocket();
                valida = true;
            } else {
                System.err.println("Comando non riconosciuto");
            }
        }

        DataOutputStream to = new DataOutputStream(socket.getOutputStream());
        BufferedReader from = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        if (HoC.equals("host")) {
            while (true) {
                System.out.println(receive(from));
            }
        } else if (HoC.equals("hostami")) {
            String str = "ciao";

            while (true) {
                send(str, to);
            }
        }

    }

    public static void send(String s, DataOutputStream to) {
        try {
            to.writeBytes(s + "\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static String receive(BufferedReader from) throws IOException {
        String stringFromClient = from.readLine();
        return stringFromClient;
    }
}
