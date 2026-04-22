package array_tasks;
import java.util.Random;

public class Task1 {
    public static void main(String[] args) {
        int[] Array = new int[10];
        Random random = new Random();

        for (int i = 0; i < 10; i++) {
            Array[i] = random.nextInt(11);
        }

        System.out.println("Array elements: ");
        for (int i = 0; i < 10; i++) {
            System.out.print(Array[i] + " ");
        }
    }
}
