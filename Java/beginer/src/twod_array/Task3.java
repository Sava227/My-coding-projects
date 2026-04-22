package twod_array;
import java.util.Random;

public class Task3 {
    public static void main(String[] args) {
        int size = 3;
        int[][] matrix = new int[size][size];
        int[][] transposed = new int[size][size];
        Random random = new Random();

        System.out.println("Original matrix:");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = random.nextInt(10);
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                transposed[j][i] = matrix[i][j];
            }
        }

        System.out.println("\nCorrected matrix:");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(transposed[i][j] + " ");
            }
            System.out.println();
        }
    }
}
