function solution(s) {
    var answer = '';
    answer = s.split("").sort(function(a,b){
        if(a>b){
            return -1;
        }
        else{
            return 1;
        }
    }).join("");
    return answer;
}