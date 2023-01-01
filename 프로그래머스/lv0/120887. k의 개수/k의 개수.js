function solution(i, j, k) {
    var answer = 0;
    var stringY;
    for(var y = i; y<=j; y++){
        stringY = y.toString();
        stringY.split("");
        for(var ck=0;ck<stringY.length;ck++){
            if(k=== Number(stringY[ck]))
                answer++;
        }
    }
    return answer;
}