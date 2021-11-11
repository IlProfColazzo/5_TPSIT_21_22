class Nano implements Runnable {

    private  String nome;

    public Nano(String nome) {
        this.nome = nome;
    }

    public void run() {
        System.out.println("Ciao, sono il nano "+this.nome);

    }
}
