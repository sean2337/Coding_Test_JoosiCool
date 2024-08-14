import java.util.Scanner;

public class Main {

    static int[] arr;
    static int N, M;
    static StringBuilder output = new StringBuilder();

    static void combination(int cnt, int start) {
        if (cnt == M) {
            output.append(arr[0]);
            for (int i = 1; i < M; i++) {
                output.append(' ').append(arr[i]);
            }
            output.append('\n');
            return;
        }

        for (int i = start; i <= N; i++) {
            arr[cnt] = i;
            combination(cnt + 1, i + 1);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        N = scanner.nextInt();
        M = scanner.nextInt();
        arr = new int[M];  

        combination(0, 1);
        System.out.println(output);

        scanner.close();
    }
}