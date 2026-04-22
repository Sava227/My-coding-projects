import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        /* System.out.println("Hello, World!");
        String hello = "Hello, World!";
        String str = input.nextLine(); */
        System.out.print("Please enter the number: ");
        int number = input.nextInt();   //single line comment
        // char ch = input.next().charAt(0);
        if (number != 1) System.out.println(number);        /*big comments*/

        int a = 13;
        int b = 435;
        int max = (a > b) ? a : b;
        System.out.println(max);

        System.out.println(max + number + " hello");

        //String name = "John";
        //int age = 30;
        //double salary = 5000.0;
        //System.out.printf("Name: %s, age: %d, Salary: %.2f\n", name, age, salary);    //%s string, $d int, %f double
        //System.out.println("hello");

        do {
            System.out.println(number);
            number--;
        }

        while (number < 0);

        /* for (int i = 0; i < 10; i++) {
            System.out.println(i);
        } */

        int[] numbers = {1, 2, 3, 4, 5};
        int[] numbers2 = new int[10];   //cant expand array
        for (int i = 0; i < 10; i++) {
            numbers2[i] = i + 1;
        }
        for (int i = 0; i < 10; i++) {
            System.out.println(numbers2[i]);
        };

        int[][] matrix = new int[5][5]; //2d array
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                matrix[i][j] = i + j;
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}