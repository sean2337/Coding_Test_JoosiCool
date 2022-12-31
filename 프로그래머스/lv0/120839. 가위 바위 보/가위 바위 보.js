function solution(rsp) {
    var answer = '';
    for(var i=0;i<rsp.length;i++){
        //가위라면
        if(rsp[i] === '2'){
            answer += '0';
            continue;
        }
        if(rsp[i] === '0'){
            answer += '5';
            continue;
        }
        if(rsp[i] === '5'){
            answer += '2';
        }
        
    }
    return answer;
}