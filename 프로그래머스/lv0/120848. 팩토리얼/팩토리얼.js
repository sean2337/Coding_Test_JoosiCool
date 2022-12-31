function solution(n) {
    var answer = 0;
    var mul = 1;
    while(true){
        if(n<mul){
            answer--;
            break;
        }
        else{
            answer++;
            mul*=answer;
        }
    }
    
    return answer;
}