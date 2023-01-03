function solution(chicken) {
    var answer = 0;
    while(true){
        if(chicken<10){
            return answer;
        }
        
        chicken = chicken -10;
        answer++;
        chicken = chicken +1;
        
    
    }
    return answer;
}