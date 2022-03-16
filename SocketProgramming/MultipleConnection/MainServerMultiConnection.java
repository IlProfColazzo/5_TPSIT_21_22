public class MainServerMultiConnection {

    public static void main(String[] args) {
        ServerMultiConnection s = new ServerMultiConnection(42521);
        s.runAndWait();
    }
}
