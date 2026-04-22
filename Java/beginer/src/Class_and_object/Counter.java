package Class_and_object;

public class Counter {
    static int count = 0;

    public Counter() {
        this.count += 1;
    }

}

class MainCounter {
    static void main() {
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        Counter c3 = new Counter();

        System.out.println(Counter.count);

    }
}