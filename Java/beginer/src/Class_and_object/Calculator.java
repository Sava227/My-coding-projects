package Class_and_object;

public class Calculator {

    public static int sum(int a, int b) {
        return a + b;
    }

    public static int subtract(int a, int b) {
        return a - b;
    }

    public static int multiply(int a, int b) {
        return a * b;
    }
}

class mainCalculator {
    public static void main() {
        System.out.println(Calculator.sum(4, 8));
        System.out.println(Calculator.subtract(10, 3));
        System.out.println(Calculator.multiply(5, 6));
    }
}