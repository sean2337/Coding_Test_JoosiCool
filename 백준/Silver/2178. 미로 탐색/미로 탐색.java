import java.util.*;

public class Main {

    static int N, M, cx, cy, nx, ny;
    static String inputLine;

    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, 1, -1 };

    static int[][] visited;
    static char[][] arr;

    static class Point {
        int x, y;

        Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        sc.nextLine();
        
        visited = new int[N][M];
        arr = new char[N][M];
        
        for (int y = 0; y < N; y++) {
            inputLine = sc.nextLine();
            for (int x = 0; x < M; x++) {
                arr[y][x] = inputLine.charAt(x);
            }
        }

        Queue<Point> que = new LinkedList<>();
        que.add(new Point(0, 0));
        visited[0][0] = 1;

        while (!que.isEmpty()) {
            Point current = que.poll();
            cy = current.y;
            cx = current.x;

            for (int k = 0; k < 4; k++) {
                nx = cx + dx[k];
                ny = cy + dy[k];

                if (nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx] > 0 || arr[ny][nx] == '0') continue;

                visited[ny][nx] = visited[cy][cx] + 1;

                if (ny == N - 1 && nx == M - 1) {
                    System.out.println(visited[ny][nx]);
                    sc.close();
                    return;
                }

                que.add(new Point(ny, nx));
            }
        }
        sc.close();
    }
}