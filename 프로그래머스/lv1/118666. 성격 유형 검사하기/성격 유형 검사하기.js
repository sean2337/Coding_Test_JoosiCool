function solution(survey, choices) {
    var answer = '';
    // 해시 테이블 만들기
    var map = new Map();
    map.set("R",0);map.set("C",0);map.set("J",0);map.set("A",0);
    map.set("T",0);map.set("F",0);map.set("M",0);map.set("N",0);
    
    //점수계산 시작
    for(var i = 0;i<survey.length;i++){
        var score = choices[i];
        let [front,back] = survey[i].split("");
        if(score>4){
            var value = map.get(back);
            map.set(back,value + score - 4 );
        }
        else if(score<4){
            var value = map.get(front);
            map.set(front,value + 4- score );
        }
    }
    
    if(map.get("R") >= map.get("T")){
        answer+="R";
    }
    else{
        answer+="T";
    }
    
    if(map.get("C") >= map.get("F")){
        answer+="C";
    }
    else{
        answer+="F";
    }
    
    
    if(map.get("J") >= map.get("M")){
        answer+="J";
    }
    else{
        answer+="M";
    }
    
    
    if(map.get("A") >= map.get("N")){
        answer+="A";
    }
    else{
        answer+="N";
    }
    

    return answer;
}