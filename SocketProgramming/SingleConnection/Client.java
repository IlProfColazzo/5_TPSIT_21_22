import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class Client {

    private String nameServer;
    private int portServer;
    private Socket mySocket;
    private DataOutputStream toServer;
    private BufferedReader fromServer;


    public Client(String nomeServer, int portaServer) {
        this.nameServer = nomeServer;
        this.portServer = portaServer;
    }

    public void connect() {
        try {

            mySocket = new Socket(nameServer, portServer);
            toServer = new DataOutputStream(mySocket.getOutputStream());
            fromServer = new BufferedReader(new InputStreamReader(mySocket.getInputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void send(String s) {

        try {
            toServer.writeBytes(s+"\n");
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public String receive() {
        String stringFromServer="";
        try {
            stringFromServer = fromServer.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return stringFromServer;
    }

    public void close() {
        try {
            fromServer.close();
            toServer.close();
            mySocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}