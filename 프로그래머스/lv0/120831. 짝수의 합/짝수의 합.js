function solution(n) {
    var answer = 0;
    if(n%2==0){
        end = n;
    }
    else{
        end = n-1;
    }
    for(var i =2; i<=end;i=i+2){
        answer += i;
    }
    
    return answer;
}