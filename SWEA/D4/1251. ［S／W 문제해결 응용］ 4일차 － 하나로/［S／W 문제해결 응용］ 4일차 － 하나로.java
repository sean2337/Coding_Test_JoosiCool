// 프림 알고리즘의 시간복잡도: O((V+E)*log(V)) => Edge가 많은 dense Graph가 유리
// 크루스칼 알고리즘의 시간복잡도 : O(E*log E) => Edge가 적은 Sparse Graph가 유리

// => 선택: 이번 문제는 각 점마다 거리를 구하기 때문에 Edge가 매우 많음
// Edge 수: (1000 * 999) / 2 = 약 10^6 개, Vertex 수 : 10^3개
// 시간복잡도 계산시: 프림 알고리즘이 유리 (선택)

import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution {
    public static int N, T;
    public static double E;
    public static long[][] distanceArr;
    public static boolean[] visited;
    public static long[] minDisArr;
    public static long[] xArr, yArr;

    // 테스트 케이스 들어가기 전 초기화 함수
    public static void clear() {
        visited = new boolean[N];
        minDisArr = new long[N];
        distanceArr = new long[N][N];
        xArr = new long[N];
        yArr = new long[N];
        
        for (int i = 0; i < N; i++) {
            minDisArr[i] = Long.MAX_VALUE;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        T = scanner.nextInt();

        for (int t = 1; t <= T; t++) {
            N = scanner.nextInt();
            clear();

            // x값과 y값 배열에 받기
            for (int i = 0; i < N; i++) {
                xArr[i] = scanner.nextLong(); 
            }
            
            for (int i = 0; i < N; i++) {
                yArr[i] = scanner.nextLong();
            }

            // 거리 계산
            E = scanner.nextDouble();
            for (int first = 0; first < N; first++) {
                for (int second = 0; second < N; second++) {
                    distanceArr[first][second] = (long) (Math.pow(xArr[first] - xArr[second], 2) + Math.pow(yArr[first] - yArr[second], 2)); 
                }
            }

            // 프림 알고리즘 수행을 통한 최소 스패닝 트리 구하기
            long result = 0;
            minDisArr[0] = 0;

            for (int i = 0; i < N; i++) {
                long min = Long.MAX_VALUE;
                int minVertex = -1;

                for (int j = 0; j < N; j++) {
                    if (!visited[j] && minDisArr[j] < min) {
                        min = minDisArr[j];
                        minVertex = j;
                    }
                }

                if (minVertex == -1) break;
                visited[minVertex] = true;
                result += min;

                for (int j = 0; j < N; j++) {
                    if (!visited[j] && distanceArr[minVertex][j] < minDisArr[j]) {
                        minDisArr[j] = distanceArr[minVertex][j];
                    }
                }
            }
            System.out.println("#" + t + " " + Math.round(result * E));
        }
        scanner.close();
    }
}