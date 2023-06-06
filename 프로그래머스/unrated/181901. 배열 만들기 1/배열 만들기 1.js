function solution(n, k) {
    var answer = [];
    var plusNum =k;
    while(n>=plusNum){
        answer.push(plusNum);
        plusNum+=k;
    }
    return answer;
}