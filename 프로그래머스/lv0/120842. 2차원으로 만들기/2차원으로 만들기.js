function solution(num_list, n) {
    var answer = [[]];
    var plusArr = [];
    for(var i =0;i<num_list.length;i++){
        //3개씩 자르는 역할.
        plusArr.push(num_list[i]);
        if((i+1)%n === 0){
            answer.push(plusArr);
            var plusArr = [];
        }
    }

    answer.shift();

    return answer;
}
