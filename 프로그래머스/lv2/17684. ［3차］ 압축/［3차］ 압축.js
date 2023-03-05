//모음 관련 배열 생성
var dicArr =[" ",'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'];


function solution(msg) {
    var answer = [];
    
    for(var i = 0;i<msg.length;i++){
        for(var sl = 1;sl<msg.length-i+1;sl++){
            // 사전에 있다면
            
            if(dicArr.indexOf(msg.substr(i,sl))===-1){
                dicArr.push(msg.substr(i,sl));
                answer.push(dicArr.indexOf(msg.substr(i,sl-1)));
                i = i + (sl-2);
                break;
            }
            //전부 다 있다면?
            if(sl===msg.length-i){
                answer.push(dicArr.indexOf(msg.substr(i,sl)));
                return answer;
            }
        }
    }
    return answer;
}
