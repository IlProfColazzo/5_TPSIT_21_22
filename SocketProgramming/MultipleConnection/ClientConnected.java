import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class ClientConnected extends  Thread{
    private Socket client;
    private DataOutputStream toClient;
    private BufferedReader fromClient;

    @Override
    public void run() {

        /*
         *
         * Insert here your protocol and algorithm
         *
         * */

        close();
    }

    public ClientConnected(Socket client) {
        this.client = client;
        try {
            this.fromClient = new BufferedReader(new InputStreamReader(this.client.getInputStream()));
            this.toClient = new DataOutputStream(this.client.getOutputStream());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void send(String s) {
        try {
            toClient.writeBytes(s+"\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    private String receive() {
        String stringFromClient="";
        try {
            stringFromClient = fromClient.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return stringFromClient;
    }

    private void close() {
        try {
            this.fromClient.close();
            this.toClient.close();
            this.client.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
