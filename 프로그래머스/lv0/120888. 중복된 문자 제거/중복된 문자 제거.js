function solution(my_string) {
    var answer = '';
    var check = [];
    
    for(var i=0;i<my_string.length;i++){
        if(check.indexOf(my_string[i])==-1){
            check.push(my_string[i]);
            answer += my_string[i];
        }
    }

    return answer;
}

