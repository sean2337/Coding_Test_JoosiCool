function solution(my_string) {
    var answer = '';
    answer = my_string.toLowerCase();
    answer = answer. split("");
    answer.sort(function(a,b){
        if(a>b){
            return 1;
        }
        else{
            return -1;
        }
    })

    answer = answer.join("");

    return answer;
}


console.log(solution("Bcad"));