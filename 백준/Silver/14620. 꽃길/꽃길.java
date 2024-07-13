import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	static int N;
	static int dx[] = {1,-1,0,0};
	static int dy[] = {0,0,1,-1};
	static int [][]arr = new int[12][12];
	static boolean[][] visited = new boolean[12][12];
	
	static void clearVisited() {
		for(int i = 0; i<N;i++) {
			Arrays.fill(visited[i],false);
		}
	}
	
	// x,y 기준으로 심을 수 있는지 체크해주는 함수
	static boolean isPossibleSeed(int x, int y) {
		if(visited[y][x] == true) return false;
		for(int i = 0; i<4;i++) {
			int nX = x + dx[i];
			int nY = y + dy[i];
			
			if(visited[nY][nX] == true) {
				return false;
			}
		}
		return true;
	}
	
	//비용 계산과 방문 처리해주는 함수
	static int doSeed(int x, int y) {
		int cost = arr[y][x]; 
		visited[y][x] = true;
		for(int i = 0; i<4;i++) {
			int nX = x + dx[i];
			int nY = y + dy[i];
			visited[nY][nX] = true;
			cost+=arr[nY][nX];
		}
		return cost;
	}
	
	

	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		
		N = scanner.nextInt();
		
		for(int i = 0;i<N;i++){
			for(int j = 0; j<N;j++) {
				arr[i][j] = scanner.nextInt();				
			}
		}
		
		int x1,y1,x2,y2,x3,y3;
		
		int minCost = Integer.MAX_VALUE;
		
		for(int i = 0;i<N*N;i++){
			for(int j = 0; j<i;j++) {
				for(int k = 0; k<j;k++) {
					// 점 3개 가져오기
					x1 = i % N; y1 = i / N;
					x2 = j % N; y2 = j / N;
					x3 = k % N; y3 = k / N;
					
					//양 모서리에 있는것은 제외
					if(x1 == 0 || y1 == 0 || x1==N-1 || y1 == N-1) continue;
					if(x2 == 0 || y2 == 0 || x2==N-1 || y2 == N-1) continue;
					if(x3 == 0 || y3 == 0 || x3==N-1 || y3 == N-1) continue;
					
					//로직을 위한 초기값 세팅
					clearVisited();
					int sumCost = 0;
					
					if(!isPossibleSeed(x1,y1)) continue;
					sumCost += doSeed(x1, y1);
					if(!isPossibleSeed(x2,y2)) continue;
					sumCost += doSeed(x2, y2);
					if(!isPossibleSeed(x3,y3)) continue;
					sumCost += doSeed(x3, y3);
						
					//3 지점의 방문처리와 비용 계산이 끝나면 최소 추정
					minCost = Math.min(minCost, sumCost);
				}				
			}
		}		
		System.out.print(minCost);
	}
}