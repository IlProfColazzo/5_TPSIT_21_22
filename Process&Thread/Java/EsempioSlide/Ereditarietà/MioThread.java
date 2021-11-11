class MioThread extends Thread {
    int id;

    public MioThread(int n) {
        System.out.println("My thread created");
        this.id = n;
    }

    public void run() {
        System.out.println("I'm thread"+this.id);
    }
}
