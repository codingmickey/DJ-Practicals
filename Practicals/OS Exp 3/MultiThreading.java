class Passenger extends Thread {
    int seats_req;
    String name;

    Passenger(int s, String n, Reservation r) {
        super(r);
        seats_req = s;
        name = n;
    }
}

class Reservation implements Runnable {
    int seats_aval = 2;

    public void run() {
        Passenger p = (Passenger) Thread.currentThread();
        book(p.seats_req, p.name);
    }

    // for synchronization change below function to synchronized
    synchronized void book(int req, String n) {
        System.out.println(n);
        if (req <= seats_aval) {
            System.out.println("seats avaliable: " + seats_aval);
            seats_aval -= req;
            System.out.println(req + " tickets booked for " + n);
        } else {
            System.out.println("seats avaliable: " + seats_aval);
            System.out.println("Tickets not avaliable!!");
        }
    }
}

public class MultiThreading {
    public static void main(String[] args) {
        Reservation r = new Reservation();
        Passenger p1 = new Passenger(2, "Kartik", r);
        Passenger p2 = new Passenger(2, "Meet", r);
        p1.start();
        p2.start();
    }
}
