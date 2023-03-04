function solution(numbers, target) {
    var answer = 0;
    var length = numbers.length;
    
    function DFS(len,sum){
        if(len===length){
            if(sum === target){
                answer++;
            }
        }
        else{
            return DFS(len+1,sum+numbers[len]),DFS(len+1,sum-numbers[len]);
        }
    }
    DFS(0,0);
    return answer;
}