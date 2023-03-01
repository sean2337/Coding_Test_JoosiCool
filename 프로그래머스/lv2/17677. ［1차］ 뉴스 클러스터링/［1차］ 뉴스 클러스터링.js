function solution(str1, str2) {
    var answer = 0;
    const regExp = /[a-zA-Z]/g; 
    
    str1 = str1.split("");
    str2 = str2.split("");
    var str1Twice = [];
    var str2Twice = [];
    //str1 두개로 나누기
    for(var i = 0;i<str1.length-1;i++){
        //특수문자가 있다면
        if(str1[i]!=="_"&&str1[i+1]!=="_"){
            if((str1[i].search(regExp)!==-1)&&(str1[i+1].search(regExp)!==-1)){
                str1Twice.push((str1[i]+str1[i+1]).toUpperCase());
            }
        }
    }
        //str2 두개로 나누기
    for(var i = 0;i<str2.length-1;i++){
        //특수문자가 있다면
        if(str2[i]!=="_"&&str2[i+1]!=="_"){
            if((str2[i].search(regExp)!==-1)&&(str2[i+1].search(regExp)!==-1)){
                str2Twice.push((str2[i]+str2[i+1]).toUpperCase());
            }
        }
    }
    var union = str1Twice.length + str2Twice.length;

    //2 교집합 구하기
    var intersection = str1Twice.filter(function(word){
        if(str2Twice.indexOf(word)!==-1){
            str2Twice.splice(str2Twice.indexOf(word),1);
            return true;
        }
        else{
            return false;
        }
    }).length;
    //3 합집합 구하기
    union = union - intersection;
    if(union===0){
        return 65536;
    }
    answer = Math.floor(intersection/union * 65536);
    return answer;
}