class MioThread implements Runnable {

    public MioThread() {

    }

    public void run() {
        for (int i = 10; i >= 1 ; i--) {
            System.out.println("..."+i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }
}
