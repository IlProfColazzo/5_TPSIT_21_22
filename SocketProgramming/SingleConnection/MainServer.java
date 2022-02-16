public class MainServer {


    public static void main(String[] args){


        Server s = new Server (7000);

        while(true) {
            s.waitConnection();
            /*
             *
             * Insert here your protocol and algorithm
             *
             * */
            s.close();
        }

    }


}