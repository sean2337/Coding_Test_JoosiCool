import java.util.Scanner;

public class Main {

	static char[] chars;
	static int N, M;
	static StringBuilder output = new StringBuilder();
	
	
	public static void makePermutation(int nthChoice, char[] choosed, boolean[] visited) {
		// 기저상황
		if (nthChoice >= M) {
			for(int i = 0; i<choosed.length; i++) {
				output.append(choosed[i]).append(' ');
			}
			output.append('\n');
			return;
		}

		// 재귀 상항
		for (int i = 0; i < chars.length; i++) {
			if (!visited[i]) {
				visited[i] = true;
				choosed[nthChoice] = chars[i];
				makePermutation(nthChoice + 1, choosed, visited);
				visited[i] = false;
			}
		}

	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		// 1. 인풋 받아오기
		N = scanner.nextInt();
		String input = "";
		for(int i = 1; i<= N; i++) {
			input += i;
		}
		chars = input.toCharArray();
		M = scanner.nextInt();
		
		// 2. 순열 함수 실행
		makePermutation(0, new char[M], new boolean[chars.length]);
		System.out.println(output);
		scanner.close();
	}
}