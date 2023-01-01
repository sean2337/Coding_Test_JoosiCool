function solution(num, k) {
    var answer = -1;
    var index =0;
    var stringNum = num.toString();
    k = k.toString();
    for(var i = 0;i<stringNum.length;i++){
        index++;
        if(stringNum[i]===k){
            answer = index;
            break;
        }
    }
    
    return answer;
}

