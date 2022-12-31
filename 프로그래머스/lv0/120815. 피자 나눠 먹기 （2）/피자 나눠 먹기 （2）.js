function solution(n) {
    var answer = 0;
    while(true){
        answer++;
        if(((answer*6)%n)===0){
            break;
        }
    }  
    return answer;
}