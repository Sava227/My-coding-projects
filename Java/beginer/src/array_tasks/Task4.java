package array_tasks;
import java.util.Random;

public class Task4 {
    public static void main(String[] args) {
        int Array[] = new int[100];
        Random random = new Random();

        for (int i = 0; i < 100; i++) {
            Array[i] = random.nextInt(101);
        }

        System.out.println("Normal array elements: ");
        for (int i = 0; i < 100; i++) {
            System.out.print(Array[i] + " ");
        }
        System.out.println();

        if (Array.length % 2 == 0) {
            for (int i = 0; i < Array.length; i += 2) {
                int temp = Array[i];
                Array[i] = Array[i + 1];
                Array[i + 1] = temp;
            }
            System.out.println("Swapped array: ");
            for (int i = 0; i < Array.length; i++) {
                System.out.print(Array[i] + " ");
            }
        }else{
                System.out.println("Array length is odd");
            }
        }
    }