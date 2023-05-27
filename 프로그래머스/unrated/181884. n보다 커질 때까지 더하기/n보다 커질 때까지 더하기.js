function solution(numbers, n) {
    var answer = 0;
    numbers.forEach(element=>{
        if(answer>n){
            return answer;
        }
        answer+=element;
    })
    return answer;
}