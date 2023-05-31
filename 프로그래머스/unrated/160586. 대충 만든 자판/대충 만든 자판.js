function solution(keymap, targets) {
    var answer = [];
    var keyHashMap = new Map();
    keymap.forEach(element=>{
        element = element.split("");
        for(var i = 0;i<element.length; i++){
            if(!keyHashMap.has(element[i])){
                keyHashMap.set(element[i],i+1);
            }
            else if(keyHashMap.get(element[i])>i+1){
                keyHashMap.set(element[i],i+1);
            }
        }
    })
    
    
    
    
    
    targets.forEach((target)=>{
        var count = 0;
        target = target.split("");
        for(var i = 0;i<target.length;i++){
            if(!keyHashMap.has(target[i])){
                count = -1;
                break;
            }
            else{
                count+=keyHashMap.get(target[i]);
            }
        }
        answer.push(count);  
    })
    
    
    return answer;
}