function solution(n) {
    var answer = 0;
    n = n.toString().split("");
    n.sort(function(a,b){
        if(a>b){
            return -1;
        }
        else{
            return 1;
        }
    })
    
    answer = n.join("");
    answer = Number(answer);

    
    return answer;
}