import java.util.Scanner;

public class Main {
    static final int maxN = 1004;
    static int N;
    static int[][] arr = new int[maxN][3];
    static int[][] costArr = new int[maxN][3];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            costArr[i][0] = sc.nextInt();
            costArr[i][1] = sc.nextInt();
            costArr[i][2] = sc.nextInt();
        }

        arr[0][0] = costArr[0][0];
        arr[0][1] = costArr[0][1];
        arr[0][2] = costArr[0][2];

        for (int i = 1; i < N; i++) {
            arr[i][0] = Math.min(arr[i - 1][1], arr[i - 1][2]) + costArr[i][0];
            arr[i][1] = Math.min(arr[i - 1][0], arr[i - 1][2]) + costArr[i][1];
            arr[i][2] = Math.min(arr[i - 1][0], arr[i - 1][1]) + costArr[i][2];
        }

        int minResult = Math.min(arr[N - 1][0], arr[N - 1][1]);
        minResult = Math.min(minResult, arr[N - 1][2]);

        System.out.println(minResult);
        sc.close();
    }
}