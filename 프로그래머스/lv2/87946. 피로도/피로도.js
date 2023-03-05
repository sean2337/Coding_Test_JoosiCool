function solution(k, dungeons) {
    var answer = 0;
    var len = dungeons.length;
    //방문했는지 체크하는 배열 0-> 방문X 1-> 방문O
    var visit = new Array(len).fill(0);
    
    function dfs(sum,count){
        if(count>answer){
            answer = count;
        }
        for(var i = 0; i<len;i++){
            if(sum>=dungeons[i][0]&&visit[i]===0){
                visit[i] = 1;
                dfs(sum-dungeons[i][1],count+1)
                visit[i] = 0;
            }
            
        }
    }

    dfs(k,0);
    
    return answer;
}