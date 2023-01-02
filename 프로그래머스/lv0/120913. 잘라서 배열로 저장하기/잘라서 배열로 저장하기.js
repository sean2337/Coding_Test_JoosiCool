function solution(my_str, n) {
    var answer = [];
    if(my_str.length===1){
        answer.push(my_str);
        return answer;
    }
    my_str = my_str.split("");
    if(n===1){
        return my_str;
    }
    var plusArr = "";
    for(var i = 0; i<my_str.length;i++){
        plusArr += my_str[i];
        if((i+1)%n===0 &&(i!=0)){
            answer.push(plusArr);
            plusArr = [];
        }
    }
    
    if(plusArr!=""){
            answer.push(plusArr);
    }
    return answer;
}