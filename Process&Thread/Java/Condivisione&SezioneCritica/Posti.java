public class Posti {

    private int postiDisponibili;
    public Posti(int postiDisponibili){
        this.postiDisponibili=postiDisponibili;
    }

    public void dec(int postiRichiesti){
        this.postiDisponibili-=postiRichiesti;
    }

    public int getPostiDisponibili(){
        return this.postiDisponibili;
    }
}
