import java.util.Scanner;

public class Main {
    static int N;
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, 1, -1 };
    static int[][] visited;
    static char[][] arr;

    static boolean isRorG(int y, int x) {
        return arr[y][x] == 'R' || arr[y][x] == 'G';
    }

    static void DFS(int y, int x, int caseIdx) {
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx] == 1) continue;
            if (caseIdx == 0) {
                if (isRorG(y, x) != isRorG(ny, nx)) continue;
            } else {
                if (arr[y][x] != arr[ny][nx]) continue;
            }
            visited[ny][nx] = 1;
            DFS(ny, nx, caseIdx);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        sc.nextLine();

        arr = new char[N][N];
        visited = new int[N][N];

        for (int y = 0; y < N; y++) {
            String inputLine = sc.nextLine();
            for (int x = 0; x < N; x++) {
                arr[y][x] = inputLine.charAt(x);
            }
        }

        int cnt1 = 0, cnt2 = 0;

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (visited[y][x] == 0) {
                    cnt1++;
                    visited[y][x] = 1;
                    DFS(y, x, 0);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = 0;
            }
        }

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (visited[y][x] == 0) {
                    cnt2++;
                    visited[y][x] = 1;
                    DFS(y, x, 1);
                }
            }
        }

        System.out.println(cnt2 + " " + cnt1);
        sc.close();
    }
}