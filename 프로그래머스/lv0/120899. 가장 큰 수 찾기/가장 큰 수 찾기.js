function solution(array) {
    var answer = [];
    var max =0;
    var index = 0;
    for(var i=0;i<array.length;i++){
        if(max<array[i]){
            max = array[i];
            index = i;
        }
    }
    answer[0] = max;
    answer[1] = index;    
    return answer;
}