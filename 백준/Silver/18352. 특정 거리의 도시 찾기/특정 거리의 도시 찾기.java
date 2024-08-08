import java.util.*;

public class Main {
    static final int MAXN = 300004;
    static List<Integer>[] vec = new ArrayList[MAXN];
    static int[] visited = new int[MAXN];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int K = sc.nextInt();
        int X = sc.nextInt();

        for (int i = 0; i < N + 1; i++) {
            vec[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            int num1 = sc.nextInt();
            int num2 = sc.nextInt();
            vec[num1].add(num2);
        }

        List<Integer> resultVec = new ArrayList<>();
        Queue<Integer> que = new LinkedList<>();
        que.add(X);
        visited[X] = 1;

        while (!que.isEmpty()) {
            int queSize = que.size();
            for (int i = 0; i < queSize; i++) {
                int current = que.poll();

                for (int n : vec[current]) {
                    if (visited[n] != 0) continue;
                    visited[n] = visited[current] + 1;
                    if (visited[n] - 1 == K) resultVec.add(n);
                    que.add(n);
                }
            }
        }

        Collections.sort(resultVec);
        if (resultVec.isEmpty()) {
            System.out.println(-1);
        } else {
            StringBuilder result = new StringBuilder();
            for (int r : resultVec) {
                result.append(r).append("\n");
            }
            System.out.print(result);
        }

        sc.close();
    }
}