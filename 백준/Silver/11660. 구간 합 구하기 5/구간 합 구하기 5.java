import java.util.Scanner;

public class Main {
    
    static int[][] arr = new int[1030][1030];
    static int[][] sum = new int[1030][1030];
    static StringBuilder output = new StringBuilder();
    
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long N = scanner.nextInt();
        long M = scanner.nextInt();

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                arr[i][j] = scanner.nextInt();
                sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= M; i++) {
            int b = scanner.nextInt();
            int a = scanner.nextInt();
            int d = scanner.nextInt();
            int c = scanner.nextInt();

            output.append(sum[d][c] - sum[d][a - 1] - sum[b - 1][c] + sum[b - 1][a - 1]).append('\n');     
        }
        System.out.println(output);
        scanner.close();
    }
}