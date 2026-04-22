package array_tasks;
import java.util.Scanner;
import java.util.Random;

public class Task2 {
    public static void main(String[] args) {
        int Array[] = new int[10];
        Random random = new Random();

        for (int i = 0; i < 10; i++) {
            Array[i] = random.nextInt(11);
        }

        Scanner scan = new Scanner(System.in);
        System.out.print("Please enter the number for sarch: ");

        int target = scan.nextInt();
        boolean found = false;

        for (int i = 0; i < Array.length; i++) {
            if (Array[i] == target) {
                found = true;
                break;
            }
        }

        if (found==true) {
            System.out.println("The number is in the array");
        } else {
            System.out.println("The number is not in the array");
        }

        System.out.println("Array elements: ");
        for (int i = 0; i < 10; i++) {
            System.out.print(Array[i] + " ");
        }
    }
}
