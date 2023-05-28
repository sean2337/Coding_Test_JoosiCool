function solution(num_list, n) {
    var answer = 0;
    num_list.forEach((element)=>{
        if(element===n){
            answer =1;
        }
    })
    return answer;
}