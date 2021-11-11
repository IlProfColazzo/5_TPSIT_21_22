class MioThread extends Thread {

    private  int numero;

    public MioThread(int numero) {
        this.numero = numero;
    }

    public void run() {
        for (int i = 0; i <= 10 ; i++) {
            System.out.println(numero + " * " + i + " = " + (numero*i));
        }

    }
}
