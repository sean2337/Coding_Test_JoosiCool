import java.util.Scanner;

public class Main {
    static final int maxN = 214;
    static final int INF = (int) 1e9;
    static int[][] arr = new int[maxN][maxN];
    static int[][] visited = new int[maxN][maxN];
    static int K, yLen, xLen;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static int[] horseDX = {-1, -2, -2, -1, 1, 2, 2, 1};
    static int[] horseDY = {-2, -1, 1, 2, 2, 1, -1, -2};

    public static void DFS(int y, int x, int horseMoveCnt) {
        if (y == yLen - 1 && x == xLen - 1) {
            return;
        }

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (ny < 0 || nx < 0 || nx >= xLen || ny >= yLen || arr[ny][nx] != 0) continue;

            if (visited[ny][nx] <= visited[y][x] + 1) continue;
            visited[ny][nx] = visited[y][x] + 1;

            DFS(ny, nx, horseMoveCnt);
        }

        if (horseMoveCnt > 0) {
            for (int k = 0; k < 8; k++) {
                int ny = y + horseDY[k];
                int nx = x + horseDX[k];

                if (ny < 0 || nx < 0 || nx >= xLen || ny >= yLen || arr[ny][nx] != 0) continue;

                if (visited[ny][nx] <= visited[y][x] + 1) continue;
                visited[ny][nx] = visited[y][x] + 1;

                DFS(ny, nx, horseMoveCnt - 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        K = sc.nextInt();
        xLen = sc.nextInt();
        yLen = sc.nextInt();

        for (int y = 0; y < yLen; y++) {
            for (int x = 0; x < xLen; x++) {
                arr[y][x] = sc.nextInt();
            }
        }

        for (int y = 0; y < yLen; y++) {
            for (int x = 0; x < xLen; x++) {
                visited[y][x] = INF;
            }
        }

        visited[0][0] = 1;
        DFS(0, 0, K);

        if (visited[yLen - 1][xLen - 1] != INF) {
            System.out.println(visited[yLen - 1][xLen - 1] - 1);
        } else {
            System.out.println(-1);
        }
    }
}
