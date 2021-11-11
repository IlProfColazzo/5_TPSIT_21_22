public class OneThreadTest {
    public static void main (String[] args) {
        MioRun r = new MioRun(10);
        Thread t = new Thread(r);
        t.start();
    }
}
