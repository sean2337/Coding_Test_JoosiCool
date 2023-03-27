function solution(n) {
    var answer = [];
    for(var i = 0;i<n;i++){
        answer.push(new Array(i+1).fill(0));
    }

    var row = -1;
    var col = 0;
    var num = 1;
    for(var i = n;i>0;i-=3){
        for(var j = 0;j<i;j++){
            answer[++row][col] = num++;
        }
        for(var j = 0;j<i-1;j++){
            answer[row][++col] = num++;
        }
        for(var j = 0;j<i-2;j++){
            answer[--row][--col] = num++;
        }

    }
    
    return answer.flat();
}