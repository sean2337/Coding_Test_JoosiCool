function possibleFun(board,row){
    //전부터 같은 라인 혹은 대각선에 있는지 체크
    for(var i = 1;i<row;i++){
        // 같은 라인에 있는지 체크
        if(board[i]===board[row]){
            return false;
        }
        // 같은 대각선에 있는지 체크
        if(Math.abs(board[i]-board[row])===Math.abs(i-row)){
            return false;
        }
    }
    return true;

}


function solution(n) {
    var answer = 0;
    function dfs(board, row){
        if(row===n){
            answer++;
        }
        else{
             // row에 무슨 열에 값을 넣을껀지 정함
            for(var i = 1;i<=n;i++){
                board[row+1] = i;
                if(possibleFun(board,row+1)){
                    dfs(board,row+1);
                }
            }
        }
       
    }

    for(var i =1;i<=n;i++){
        var board = new Array(n+1).fill(0);
        board[1] = i;
        dfs(board,1);
    }

    return answer;
}
