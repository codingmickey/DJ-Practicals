import java.io.*;
import java.net.*;

class Client {
    public static void main(String[] args) throws Exception {
        Socket cs = new Socket("localhost", 80);
        BufferedReader br = new BufferedReader(new InputStreamReader(cs.getInputStream()));
        String m = br.readLine();

        System.out.println("Message from server = " +m);
        cs.close();
    }
}