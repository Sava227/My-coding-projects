package twod_array;
import java.util.Random;

public class Task4 {
    public static void main(String[] args) {
        int rows = 3;
        int cols = 3;
        int[][] matrix = new int[rows][cols];
        Random random = new Random();

        System.out.println("Array:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = random.nextInt(100);
                System.out.print(matrix[i][j] + "\t");
            }
            System.out.println();
        }

        int min = matrix[0][0];
        int max = matrix[0][0];
        int minR = 0;
        int minC = 0;
        int maxR = 0;
        int maxC = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                    minR = i; minC = j;
                }
                if (matrix[i][j] > max) {
                    max = matrix[i][j];
                    maxR = i; maxC = j;
                }
            }
        }

        System.out.println("\nMin: " + min + "In pos [" + minR + "][" + minC + "]");
        System.out.println("Max: " + max + " in pos [" + maxR + "][" + maxC + "]");

        int count_between = Math.abs(max - min) - 1;
        if (count_between < 0) count_between = 0;

        System.out.println("Full numbers between them: " + count_between);
    }
}
