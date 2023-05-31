function solution(name, yearning, photo) {
    var answer = [];
    var map = new Map();
    //key,value (이름, 그리움 값)
    for(var i = 0;i<name.length;i++){
        map.set(name[i],yearning[i]);
    }
    var plusAnswer= 0;
    photo.forEach((element)=>{
        var plusAnswer= 0;
        for(var i = 0;i<element.length;i++){
            if(map.has(element[i])){
                plusAnswer+=map.get(element[i]);
            }
        }
        answer.push(plusAnswer);
    })
    
    
    
    return answer;
}