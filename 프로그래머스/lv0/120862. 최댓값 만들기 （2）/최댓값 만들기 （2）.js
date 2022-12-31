function solution(numbers) {
    var answer = 0;
    var arr = [];
    for(var i=0;i<numbers.length-1;i++){
        for(var k=i+1;k<numbers.length;k++){
            arr.push(numbers[i]*numbers[k]);
        }
    }
    
    answer = Math.max(...arr);
    
    return answer;
}