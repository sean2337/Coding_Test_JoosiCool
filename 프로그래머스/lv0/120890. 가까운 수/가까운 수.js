function solution(array, n) {
    var answer = array[0];
    var abs;
    var min = Math.abs(array[0] - n);
    for(var i =1;i<array.length;i++){
        abs = Math.abs(array[i] - n);
        if(abs===min){
            if(answer>array[i])
                answer = array[i];
        }
        if(abs<min){
            min = abs;
            answer = array[i];
        }
    }
    return answer;
}