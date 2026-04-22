package twod_array;

public class Task2 {
    public static void main(String[] args) {
        int size = 5;
        char[][] matrix = new char[size][size];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j || i + j == size - 1) {
                    matrix[i][j] = 'X';
                } else {
                    matrix[i][j] = ' ';
                }
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}