function solution(n) {
    var answer = -1;
    if(Math.sqrt(n)%1===0){
        answer = (Math.sqrt(n) + 1) * (Math.sqrt(n) + 1)
    }
    return answer;
}