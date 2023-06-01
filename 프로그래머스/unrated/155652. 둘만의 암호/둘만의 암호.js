function solution(s, skip, index) {
    var alpabetArr= ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'];
    
    var answer = '';
    
    skip = skip.split("");
     alpabetArr = alpabetArr.filter((element)=>{
         if(skip.includes(element)){
             return false;
         }
         else{
             return true;
         }
     })
    
    s.split("").forEach(element=>{
        var eleIndex = alpabetArr.indexOf(element);
        eleIndex += index;
        while(eleIndex>=alpabetArr.length){
            eleIndex -= alpabetArr.length;
        }
        answer+=alpabetArr[eleIndex];
    })
    
    
    return answer;
}