function solution(brown, yellow) {
    var answer = [];
    var totalArea = brown + yellow;
    
    for(var i =3;i<=Math.sqrt(brown+yellow);i++){
        if(totalArea%i===0){
            if((i-2)*(totalArea/i-2) === yellow){
                answer[0] = i>totalArea/i? i : totalArea/i;
                answer[1] = i<totalArea/i? i : totalArea/i;
            }
        }
    }
    
    
    return answer;
}