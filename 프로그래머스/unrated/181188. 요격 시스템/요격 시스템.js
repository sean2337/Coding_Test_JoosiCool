

function solution(targets) {
    var answer = 1;
    var prev = -1;
    // 오름차순으로 정렬
    targets = targets.sort((a,b)=>b[0]-a[0]);
    
    let [start,end] = targets.shift();
    
    for(var i = 0;i<targets.length;i++){
        let [sX,eX] = targets[i];
        if(start>=eX){
            answer++;
            start = sX;
        }
    }
    
    return answer;
}