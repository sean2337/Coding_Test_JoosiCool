import java.util.Scanner;

public class Main {

    static StringBuffer output = new StringBuffer();
    static String[][] arr;
    static String[][] copyArr;
    static int N;
    static int bx1, bx2, bx3, by1, by2, by3;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, 1, -1};

    public static boolean isX(int y, int x) {
        return arr[y][x].equals("X");
    }

    public static boolean isSuccess() {

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (copyArr[y][x].equals("T")) {
                    for (int k = 0; k < 4; k++) {
                        int cx = x, cy = y;

                        while (true) {
                            cy += dy[k];
                            cx += dx[k];

                            // 경계 밖을 넘어가는 경우
                            if (cy >= N || cy < 0 || cx >= N || cx < 0)
                                break;
                            if (copyArr[cy][cx].equals("O")) break;
                            // 학생을 만났을때
                            if (copyArr[cy][cx].equals("S")) return false;
                        }
                    }
                }
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        scanner.nextLine();  

        arr = new String[N][N];
        for (int y = 0; y < N; y++) {
            String s = scanner.nextLine();
            arr[y] = s.split(" ");
        }

        // 3중 for문을 통해 조합 구하기
        for (int block1 = 0; block1 < N * N; block1++) {
            for (int block2 = block1; block2 < N * N; block2++) {
                for (int block3 = block2; block3 < N * N; block3++) {
                    bx1 = block1 % N;
                    by1 = block1 / N;
                    bx2 = block2 % N;
                    by2 = block2 / N;
                    bx3 = block3 % N;
                    by3 = block3 / N;

                    // 3곳에 벽을 세울 수 없는 경우 패스
                    if (!isX(by1, bx1) || !isX(by2, bx2) || !isX(by3, bx3))
                        continue;

                    // 벽 세우기
                    copyArr = new String[N][N];
                    for (int i = 0; i < N; i++) {
                        copyArr[i] = arr[i].clone();
                    }
                    copyArr[by1][bx1] = "O";
                    copyArr[by2][bx2] = "O";
                    copyArr[by3][bx3] = "O";

                    if (isSuccess()) {
                        System.out.println("YES");
                        return;
                    }

                }
            }
        }
        System.out.println("NO");
        scanner.close();
    }
}