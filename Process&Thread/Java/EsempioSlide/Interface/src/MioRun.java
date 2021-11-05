class MioRun implements Runnable {
    int id;

    public MioRun(int n) {
        System.out.println("My thread created");
        this.id = n;
    }

    public void run() {
        System.out.println("I’m thread "+this.id);
    }
}
