function solution(number) {
    var answer = 0;
    for(var one = 0;one<number.length-2;one++){
        for(var two = one+1;two<number.length-1;two++){
            for(var three = two + 1;three<number.length;three++){
                if(number[one]+number[two]+number[three]===0){
                    answer++;
                }
            }
            
        }
    }
    
    return answer;
}