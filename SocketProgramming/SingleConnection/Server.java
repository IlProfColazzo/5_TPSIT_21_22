import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    private int portServer;
    private Socket client;
    private ServerSocket server;
    private DataOutputStream toClient;
    private BufferedReader fromClient;


    public Server(int portServer) {
        this.portServer = portServer;
        try {
            this.server = new ServerSocket(this.portServer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void waitConnection() {
        try {
            System.out.println("Waiting for a connection...");
            client = server.accept();
            System.out.println("Client connected..."+client.getInetAddress()+"...");
            toClient = new DataOutputStream(client.getOutputStream());
            fromClient = new BufferedReader(new InputStreamReader(client.getInputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void send(String s) {
        try {
            toClient.writeBytes(s+"\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public String receive() {
        String stringFromClient="";
        try {
            stringFromClient = fromClient.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return stringFromClient;
    }

    public void close() {
        try {
            toClient.close();
            fromClient.close();
            client.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}