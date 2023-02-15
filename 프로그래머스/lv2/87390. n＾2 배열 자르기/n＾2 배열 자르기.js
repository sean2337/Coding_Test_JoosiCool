function solution(n, left, right) {
    var answer = [];
    for (var i = left; i<=right;i++){
        if(i/n>=i%n){
            answer.push(Math.floor(i/n)+1);
        }
        else{
            answer.push(i%n+1);
        }
    }
    
    return answer;
}