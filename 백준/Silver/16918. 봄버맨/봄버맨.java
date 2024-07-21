import java.util.Scanner;


public class Main {

    static int R,C,N;
    // 0: 폭탄 X, 2: 폭탄O(1번째), 4: 폭탄O(2번째) 
    static int[][] bombArr = new int[204][204];
    static int dx[] = {-1,1,0,0};
    static int dy[] = {0,0,1,-1};

    // 특정 타켓을 기준으로 폭탄을 터트리는 함수
    static int[][] bomb(int target){
        int[][] newBombArr = new int[R][C];

        // 새로운 배열에 기존 배열의 값을 복사
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                newBombArr[y][x] = bombArr[y][x];
            }
        }

        // 타겟을 기준으로 상하좌우를 0으로 설정
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (bombArr[y][x] == target) {
                    newBombArr[y][x] = 0;
                    for (int k = 0; k < 4; k++) {
                        int nX = x + dx[k];
                        int nY = y + dy[k];
                        if (nX < 0 || nY < 0 || nX >= C || nY >= R) continue;
                        newBombArr[nY][nX] = 0;
                    }
                }
            }
        }
        return newBombArr;
    }


    // 특정 타켓으로 폭탄을 채우는 함수
    static void bombFill(int target){
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (bombArr[y][x] == 0) {
                 bombArr[y][x] = target;
                }
            }
        }
    }


    public static void main(String[] args){

        Scanner scanner = new Scanner(System.in);

        R = scanner.nextInt();
        C = scanner.nextInt();
        N = scanner.nextInt();
        scanner.nextLine();
        //초기 폭탄 위치 4로 초기화
        for(int y = 0 ;y<R;y++){
            String s = scanner.next();
            for(int x = 0; x< C;x++){
                if(s.charAt(x) == 'O'){
                    bombArr[y][x] = 2;
                }
            }
        }

        // N번 로직 실행
        for(int i = 1;i<N;i++){
            // 4 터트리기
            if(i%4==0){
                bombArr = bomb(4);
            }
            // 4 채우기
            else if(i%4==1){
                bombFill(4);
            }
            // 2 터트리기
            else if(i%4==2){
                bombArr = bomb(2);
            }
            // 2 채우기
            else{
                bombFill(2);
            }
        }

        StringBuilder builder = new StringBuilder();
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (bombArr[y][x] == 0) {
                    builder.append('.');
                }
                else{
                    builder.append('O');
                }
            }
            builder.append("\n");
        }

        System.out.println(builder);
     
        scanner.close();
    }
}