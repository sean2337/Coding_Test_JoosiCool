import java.util.*;

public class Main {
    static final int MAX_V = 10004;
    static int V, E, A, B, C;
    static int[] parents = new int[MAX_V];

    static class Edge {
        int start, end, weight;

        Edge(int start, int end, int weight) {
            this.start = start;
            this.end = end;
            this.weight = weight;
        }
    }

    static void make() {
        for (int i = 0; i < MAX_V; i++) {
            parents[i] = i;
        }
    }

    static int findSet(int a) {
        if (parents[a] == a) return a;
        return parents[a] = findSet(parents[a]);
    }

    static boolean unionFun(int a, int b) {
        int aRoot = findSet(a);
        int bRoot = findSet(b);

        if (aRoot == bRoot) return false;

        if (aRoot < bRoot) {
            parents[bRoot] = aRoot;
        } else {
            parents[aRoot] = bRoot;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Edge> vec = new ArrayList<>();
        make();

        V = scanner.nextInt();
        E = scanner.nextInt();
        for (int i = 0; i < E; i++) {
            A = scanner.nextInt();
            B = scanner.nextInt();
            C = scanner.nextInt();
            vec.add(new Edge(A, B, C));
        }
        vec.sort(Comparator.comparingInt(edge -> edge.weight));

        int cnt = 0;
        long cost = 0;
        for (Edge edge : vec) {
            if (unionFun(edge.start, edge.end)) {
                cost += edge.weight;
                cnt++;
                if (cnt == V - 1) break;
            }
        }
        System.out.println(cost);
        scanner.close();
    }
}