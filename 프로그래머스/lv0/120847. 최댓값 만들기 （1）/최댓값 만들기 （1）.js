function solution(numbers) {
    var answer = 0;
    numbers.sort(function(a,b){
        if(a>b)
            return -1;
        else if(a==b)
            return 0;
        else{
            return 1;
        }
    })
    
    answer = numbers[0] * numbers[1];
    
    return answer;
}