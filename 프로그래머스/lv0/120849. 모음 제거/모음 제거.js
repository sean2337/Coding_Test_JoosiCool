function solution(my_string) {
    var answer = '';
    var moum = "aeiou";
    
    for(var i=0;i<my_string.length;i++){
        if(moum.indexOf(my_string[i])==-1){
            answer+=my_string[i];
        }
    }
    
    return answer;
}