function solution(n) {
    var answer = [];
    var arr;
    answer = n.toString().split("");
    answer = answer.reverse();
    for(var i = 0;i<answer.length;i++){
        answer[i] = Number(answer[i]);
    }
    
    return answer;
}