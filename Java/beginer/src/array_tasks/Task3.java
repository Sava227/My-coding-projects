package array_tasks;

public class Task3 {
    public static void main(String[] args) {
        char[] Array = new char[7];
        Array[0] = 'i';
        Array[1] = 't';
        Array[2] = 'g';
        Array[3] = 'e';
        Array[4] = 'n';
        Array[5] = 'i';
        Array[6] = 'o';

        System.out.print("Before: ");
        System.out.println(Array);

        Array[6] = 'k';

        System.out.print("After: ");
        System.out.println(Array);
    }
}
