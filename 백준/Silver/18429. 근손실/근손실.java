import java.util.Scanner;

public class Main {

	static int[] intArr = new int[9];
	static int N, K;
	static int rnt;

	public static void makePermutation(int nthChoice, int[] choosed, boolean[] visited) {
		// 기저상황
		if (nthChoice >= N) {
			int weight = 500;
			for (int i = 0; i < choosed.length; i++) {
				weight += (choosed[i] - K);
				if (weight < 500)
					return;
			}
			rnt++;
			return;
		}

		// 재귀 상항
		for (int i = 0; i < intArr.length; i++) {
			if (!visited[i]) {
				visited[i] = true;
				choosed[nthChoice] = intArr[i];
				makePermutation(nthChoice + 1, choosed, visited);
				visited[i] = false;
			}
		}

	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		K = scanner.nextInt();
		intArr = new int[N];
		for (int i = 0; i < N; i++) {
			intArr[i] = scanner.nextInt();
		}

		makePermutation(0, new int[N], new boolean[intArr.length]);
		System.out.println(rnt);
		scanner.close();
	}
}