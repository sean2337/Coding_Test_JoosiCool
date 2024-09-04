import java.util.*;

public class Solution {
    static final int maxN = 8;
    static int N, K;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static int[][] arr = new int[maxN][maxN];
    static boolean[][] visited = new boolean[maxN][maxN];
    static int maxLength;

    public static void DFS(int y, int x, int length, boolean isCut) {
        maxLength = Math.max(maxLength, length);

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;

            if (arr[ny][nx] < arr[y][x]) {
                visited[ny][nx] = true;
                DFS(ny, nx, length + 1, isCut);
                visited[ny][nx] = false;
            } else if (!isCut && arr[ny][nx] - K < arr[y][x]) {
                int originalHeight = arr[ny][nx];
                arr[ny][nx] = arr[y][x] - 1;
                visited[ny][nx] = true;
                DFS(ny, nx, length + 1, true);
                visited[ny][nx] = false;
                arr[ny][nx] = originalHeight;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            N = sc.nextInt();
            K = sc.nextInt();
            int maxHeight = 0;
            List<int[]> peaks = new ArrayList<>();

            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    arr[y][x] = sc.nextInt();
                    maxHeight = Math.max(maxHeight, arr[y][x]);
                }
            }

            for (int y = 0; y < N; y++) {
                for (int x = 0; x < N; x++) {
                    if (arr[y][x] == maxHeight) {
                        peaks.add(new int[]{y, x});
                    }
                }
            }

            maxLength = 0;

            for (int[] p : peaks) {
                for (int i = 0; i < N; i++) {
                    Arrays.fill(visited[i], false);
                }
                int startY = p[0];
                int startX = p[1];
                visited[startY][startX] = true;
                DFS(startY, startX, 1, false);
            }

            System.out.println("#" + t + " " + maxLength);
        }
        sc.close();
    }
}