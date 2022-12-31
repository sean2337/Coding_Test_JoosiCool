function solution(age) {
    var answer = '';
    var check;
    while(true){
        if(age<10){
           check = (age%10);
            answer += String.fromCharCode(check+97);
            break;
         }
        check = (age%10);
        answer += String.fromCharCode(check+97);
        age = Math.floor(age/10);


    }

    answer = answer.split("").reverse().join("");
    
    return answer;
}