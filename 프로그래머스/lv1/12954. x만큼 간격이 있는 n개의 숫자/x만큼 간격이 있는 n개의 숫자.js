function solution(x, n) {
    var answer = [];
    var plus= x;
    while(n--){
        answer.push(x);
        x = x +plus;
    }
    
    
    return answer;
}