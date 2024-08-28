import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static final int MAXN = 2004;
    static ArrayList<Integer>[] vec = new ArrayList[MAXN];
    static boolean[] visited = new boolean[MAXN];
    static int maxLen = -1;

    static {
        for (int i = 0; i < MAXN; i++) {
            vec[i] = new ArrayList<>();
        }
    }

    public static void DFS(int human, int cnt) {
        maxLen = Math.max(maxLen, cnt);
        if (maxLen >= 5) {
            System.out.println(1);
            System.exit(0); 
        }
        for (int nextH : vec[human]) {
            if (visited[nextH]) continue;

            visited[nextH] = true;
            DFS(nextH, cnt + 1);
            visited[nextH] = false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            // 양방향 간선
            vec[a].add(b);
            vec[b].add(a);
        }

        for (int human = 0; human < N; human++) {
            for (int i = 0; i < N; i++) {
                visited[i] = false;
            }
            visited[human] = true;
            DFS(human, 1);
            visited[human] = false;
        }
        System.out.println(0);
        sc.close();
    }
}