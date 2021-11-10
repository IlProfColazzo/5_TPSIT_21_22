public class MioThread extends Thread{

    private int id;
    private Posti postiDisponibili;
    private int postiRichiesti;

    public MioThread(int id,Posti postiDisponibili, int postiRichiesti){
        this.id=id;
        this.postiDisponibili=postiDisponibili;
        this.postiRichiesti = postiRichiesti;
    }


    @Override
    public void run(){
        if(postiRichiesti<=postiDisponibili.getPostiDisponibili())
        {
            postiDisponibili.dec(postiRichiesti);
            System.out.println("Prenotato: "+postiRichiesti);
        }
    }
}
