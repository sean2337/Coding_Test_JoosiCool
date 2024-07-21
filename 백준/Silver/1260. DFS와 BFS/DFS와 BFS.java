import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;


public class Main {

    static public Vector<Integer>vec[] = new Vector[1004];
    static public boolean visited[] = new boolean[1004];
    static StringBuilder rnt = new StringBuilder();

    // 방문 배열 초기화
    static public void clearVisited(){
        visited = new boolean[1004];
    }

    // 벡터 초기화
    static public void clearVec(){
        for (int i = 0; i < 1004; i++) {
            vec[i] = new Vector<>();
        }
    }

    // DFS 코드
    static public void DFS(int cur){
        visited[cur] = true;
        rnt.append(cur).append(" "); 
        for(int i = 0; i < vec[cur].size(); i++){
            int next = vec[cur].get(i);
            if(!visited[next]){
                DFS(next);
            }
        }
    }

    //BFS 코드
    static public void BFS(int cur){
        rnt.append(cur);
        //큐 생성하여 BFS 실행
        Queue<Integer> que = new LinkedList<>();
        que.offer(cur);
        visited[cur] = true;
        
        while(!que.isEmpty()){
            int queSize = que.size();
            for(int i = 0; i<queSize;i++){
                cur = que.poll();
                for(int vecIdx = 0; vecIdx< vec[cur].size(); vecIdx++){
                    int next = vec[cur].get(vecIdx);
                    if(visited[next]) continue;
                    que.offer(next);
                    visited[next] = true;
                    rnt.append(" ").append(next);
                }
            }
        }
    }

    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);
        
        clearVec();
        
        // 정점, 간선 개수 입력 받기
        int vertexN = scanner.nextInt();
        int edgeN = scanner.nextInt();
        int startVertex = scanner.nextInt();
        
        // 배열에 입력값 받기
        int start, end;
        while(edgeN-- > 0){
            start = scanner.nextInt();
            end = scanner.nextInt();

            // 양방향 그래프
            vec[start].add(end);
            vec[end].add(start);
        }

         // 각 정점의 인접 리스트 정렬
        for (int i = 1; i <= vertexN; i++) {
            Collections.sort(vec[i]);
        }

        //DFS 실행
        DFS(startVertex);
        rnt.append("\n");
        clearVisited();
        //BFS 실행
        BFS(startVertex);
        System.out.println(rnt);
        scanner.close();
    }
}