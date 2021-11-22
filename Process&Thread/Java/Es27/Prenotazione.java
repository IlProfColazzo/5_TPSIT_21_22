public class Prenotazione extends Thread{

    private Posti postiDisponibili;
    private int postiRichiesti;

    public Prenotazione(Posti postiDisponibili, int postiRichiesti){
        this.postiDisponibili=postiDisponibili;
        this.postiRichiesti = postiRichiesti;
    }


    @Override
    public void  run(){
        this.postiDisponibili.prenota(postiRichiesti);
    }
}
