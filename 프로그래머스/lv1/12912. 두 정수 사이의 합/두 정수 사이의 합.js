function solution(a, b) {
    var answer = 0;
    var start = (a>=b)? b : a;
    var end = (a<=b)? b:a;
    
    for(var i = start;i<=end;i++){
        answer +=i;
    }
    return answer;
}