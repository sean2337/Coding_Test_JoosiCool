function solution(s) {
    var hashMap = new Map();
    var newWords = [];
    s.forEach(element => {
        //있다면
        if(hashMap.has(element[1])){
            hashMap.set(element[1],hashMap.get(element[1])+1);
        } 
        //없다면
        else{
            hashMap.set(element[1],1);
            newWords.push(element[1]);
        }
    });
    var answer = 1;
    newWords.forEach(element=>{
        answer *= (hashMap.get(element)+1);
    })

    return --answer;
}