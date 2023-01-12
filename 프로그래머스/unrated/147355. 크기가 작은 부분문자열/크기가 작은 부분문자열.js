function solution(t, p) {
    var answer = 0;
    var cutLen = p.length;
    var cutArr = [];
    
    // 문자열 잘라서 cutArr에 넣기
    for(var i =0;i<t.length-cutLen+1;i++){
        cutArr.push(t.substr(i,cutLen));
    }
    

    // 각각이 p보다 같거나 작다면 답 +1
    cutArr.forEach(element=>{
        if(Number(element)<=Number(p)){
            answer++;
        }
    })

    return answer;
}

console.log(solution("3141592","271"))