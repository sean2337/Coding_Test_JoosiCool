function factorial(n){
    var result =1;
    if(n===0||n===1){
        return 1;
    }
    for(var i=2;i<n+1;i++){
        result *=i;
    }
    return result;
}

function solution(balls, share) {
    var answer = 0;
    // n= ball, m = share
    answer = Math.round(factorial(balls) /(factorial(balls-share)*factorial(share)));
    
    return answer;
}