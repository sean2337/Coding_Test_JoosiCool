// O(W*H*(K+1))
// => 200 X 200 X 31
// 1,240,000 => OK

import java.util.*;

class Point {
    int x, y, dist, k;

    Point(int x, int y, int dist, int k) {
        this.x = x;
        this.y = y;
        this.dist = dist;
        this.k = k;
    }
}

public class Main {
    static final int INF = (int) 1e9;
    static final int MAX = 200;
    static int K, W, H;
    static int[][] arr = new int[MAX][MAX];
    static boolean[][][] visited = new boolean[MAX][MAX][31];
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int[] horseDX = {-2, -1, 1, 2, 2, 1, -1, -2};
    static int[] horseDY = {-1, -2, -2, -1, 1, 2, 2, 1};

    public static int bfs() {
        Queue<Point> q = new LinkedList<>();
        q.offer(new Point(0, 0, 0, 0));
        visited[0][0][0] = true;

        while (!q.isEmpty()) {
            Point cPoint = q.poll();

            if (cPoint.x == W - 1 && cPoint.y == H - 1) {
                return cPoint.dist;
            }

            for (int i = 0; i < 4; i++) {
                int nx = cPoint.x + dx[i];
                int ny = cPoint.y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < W && ny < H && arr[ny][nx] == 0 && !visited[ny][nx][cPoint.k]) {
                    visited[ny][nx][cPoint.k] = true;
                    q.offer(new Point(nx, ny, cPoint.dist + 1, cPoint.k));
                }
            }

            if (cPoint.k < K) {
                for (int i = 0; i < 8; i++) {
                    int nx = cPoint.x + horseDX[i];
                    int ny = cPoint.y + horseDY[i];

                    if (nx >= 0 && ny >= 0 && nx < W && ny < H && arr[ny][nx] == 0 && !visited[ny][nx][cPoint.k + 1]) {
                        visited[ny][nx][cPoint.k + 1] = true;
                        q.offer(new Point(nx, ny, cPoint.dist + 1, cPoint.k + 1));
                    }
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        K = sc.nextInt();
        W = sc.nextInt();
        H = sc.nextInt();

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        int result = bfs();
        System.out.println(result);
    }
}
