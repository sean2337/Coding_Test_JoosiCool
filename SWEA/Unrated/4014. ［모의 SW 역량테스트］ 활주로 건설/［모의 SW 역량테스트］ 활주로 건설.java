import java.util.Scanner;

public class Solution {

    static int N, X;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        for (int tc = 1; tc <= T; tc++) {
            N = sc.nextInt();
            X = sc.nextInt();

            int[][] A = new int[N][N];
            int result = 0;

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    A[i][j] = sc.nextInt();
                }
                result += checkSlope(A[i]);
            }

            for (int i = 0; i < N; i++) {
                int[] temp = new int[N];
                for (int j = 0; j < N; j++) {
                    temp[j] = A[j][i];
                }
                result += checkSlope(temp);
            }

            System.out.println("#" + tc + " " + result);
        }
    }

    public static int checkSlope(int[] row) {
        int cnt = 1;
        for (int i = 1; i < N; i++) {
            if (row[i] == row[i - 1]) {
                cnt++;
            } else if (row[i] - row[i - 1] == 1 && cnt >= X) {
                cnt = 1;
            } else if (row[i - 1] - row[i] == 1 && cnt >= 0) {
                cnt = -X + 1;
            } else {
                return 0;
            }
        }
        if (cnt >= 0) {
            return 1;
        }
        return 0;
    }
}
