import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Solution {
    
    public static final int[] DX = {-1, 1, 0, 0, -1, -1, 1, 1};
    public static final int[] DY = {0, 0, -1, 1, -1, 1, -1, 1};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        for (int tc = 1; tc <= t; tc++) {
            int n = scanner.nextInt();
            char[][] board = new char[n][n];
            for (int i = 0; i < n; i++) {
                board[i] = scanner.next().toCharArray();
            }

            int[][] mineCount = new int[n][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == '.') {
                        int tmp = 0;
                        for (int d = 0; d < 8; d++) {
                            int ni = i + DX[d];
                            int nj = j + DY[d];
                            if (ni >= 0 && ni < n && nj >= 0 && nj < n && board[ni][nj] == '*') {
                                tmp++;
                            }
                        }
                        mineCount[i][j] = tmp;
                    } else {
                        mineCount[i][j] = -1;
                    }
                }
            }

            int cnt = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mineCount[i][j] == 0) {
                        cnt++;
                        Queue<int[]> queue = new LinkedList<>();
                        queue.offer(new int[]{i, j});
                        mineCount[i][j] = -1;

                        while (!queue.isEmpty()) {
                            int[] current = queue.poll();
                            int ni = current[0];
                            int nj = current[1];

                            for (int d = 0; d < 8; d++) {
                                int dx = ni + DX[d];
                                int dy = nj + DY[d];
                                if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
                                    if (mineCount[dx][dy] == 0) {
                                        mineCount[dx][dy] = -1;
                                        queue.offer(new int[]{dx, dy});
                                    } else if (mineCount[dx][dy] > 0) {
                                        mineCount[dx][dy] = -1;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mineCount[i][j] > 0) {
                        cnt++;
                    }
                }
            }

            System.out.println("#" + tc + " " + cnt);
        }
        scanner.close();
    }
}