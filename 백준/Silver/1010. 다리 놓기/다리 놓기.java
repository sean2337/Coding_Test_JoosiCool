import java.util.Scanner;

public class Main {
    static long combination(int N, int K) {
        if (K == 0 || K == N) return 1;
        K = Math.min(K, N - K);
        long result = 1;
        for (int i = 1; i <= K; i++) {
            result *= (N - i + 1);
            result /= i;
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            if (A > B) {
                System.out.println(combination(A, B));
            } else {
                System.out.println(combination(B, A));
            }
        }
        sc.close();
    }
}