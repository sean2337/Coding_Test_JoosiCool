function solution(start, end) {
    var answer = [];
    while(start!==end+1){
        answer.push(start);
        start++;
    }
    return answer;
}