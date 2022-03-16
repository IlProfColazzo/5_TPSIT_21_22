import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerMultiConnection {

    private int portServer;
    private ServerSocket server;

    public ServerMultiConnection(int portServer) {
        this.portServer = portServer;
    }

    public void runAndWait() {
        ClientConnected client=null;
        try {
            this.server = new ServerSocket(this.portServer);
            while(true) {
                System.out.println("Waiting for a connection...");
                Socket s = this.server.accept();
                System.out.println("Client connected..."+s.getInetAddress()+"...");
                client = new ClientConnected(s);
                client.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return;
    }
}
