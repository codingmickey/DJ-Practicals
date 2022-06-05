import java.io.*;
import java.net.*;

class Server {
    public static void main(String[] args) throws Exception {
        String msg;
        ServerSocket ss = new ServerSocket(80);
        while (true) {
            Socket s1 = ss.accept();
            String week[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
            int i = (int) (Math.random() * week.length);
            msg = week[i];
            PrintStream ps = new PrintStream(s1.getOutputStream());
            ps.println(msg);
        }
    }
}