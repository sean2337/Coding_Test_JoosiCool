function solution(s) {
    var answer = [];
    var arr =[];
    s = s.split("");
    for(var i =0; i<s.length;i++)
    {
        //답 배열에 없다면..
        if(answer.indexOf(s[i])===-1){
            // 스펠링 배열에 없다면 -> answer에 추가, 스펠링에 추가
            if(arr.indexOf(s[i])===-1){
                answer.push(s[i]);
                arr.push(s[i]);
            }
            // 스펠링 배열에 있다면 X
        }
        else{
            answer.splice(answer.indexOf(s[i]),1);
            arr.push(s[i]);
        }
        
    }
    
    answer = answer.sort().join("");
    
    return answer;
}

