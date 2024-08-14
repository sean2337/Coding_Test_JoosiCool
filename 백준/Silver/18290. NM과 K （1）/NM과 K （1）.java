import java.util.Scanner;

public class Main {

	static int[] arr;
	static int[][] numArr;
	static int maxNM, N, M, K;
	static int maxValue = Integer.MIN_VALUE;

	static void combination(int cnt, int start) {
		if (cnt == K) {
			// 1. 인접하지 않은지 체크
			for (int first = 0; first < K; first++) {
				for (int second = first + 1; second < K; second++) {
					int sx = arr[first] % M;
					int sy = arr[first] / M;
					int ex = arr[second] % M;
					int ey = arr[second] / M;

					int xDis = Math.abs(sx - ex);
					int yDis = Math.abs(sy - ey);
					// 인접한 경우 무시
					if ((xDis == 1 && yDis == 0) || (xDis == 0 && yDis == 1)) {
						return;
					}
				}
			}

			// 2. 인접하지 않으면 최댓값 체크
			int checkSum = 0;
			for (int i = 0; i < K; i++) {
				int sx = arr[i] % M;
				int sy = arr[i] / M;
				checkSum += numArr[sy][sx];
			}

			maxValue = Math.max(maxValue, checkSum);
			return;
		}

		for (int i = start; i < maxNM; i++) {
			arr[cnt] = i;
			combination(cnt + 1, i + 1);
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		N = scanner.nextInt();
		M = scanner.nextInt();
		K = scanner.nextInt();
		maxNM = N * M;

		arr = new int[K];
		numArr = new int[N][M];

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				numArr[y][x] = scanner.nextInt();
			}
		}

		combination(0, 0);
		System.out.println(maxValue);

		scanner.close();
	}
}