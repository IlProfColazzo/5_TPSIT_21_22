public class TwoThreadsTest {
    public static void main (String[] args) {
        MioThread t1 = new MioThread(1);
        MioThread t2 = new MioThread(2);
        t1.start();
        t2.start();
    }
}
