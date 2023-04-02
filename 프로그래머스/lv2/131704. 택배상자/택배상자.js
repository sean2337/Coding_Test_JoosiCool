function solution(order) {
    var answer = 0;
    var assistantArr = [];
    var orderLen = order.length;
    order = order.reverse();
    for(var i = 1;i<=orderLen+1;i++){
         while(true){
            if(assistantArr.length===0){
                break;
            }
            if(assistantArr[assistantArr.length-1]===order[order.length-1]){
                order.pop();
                assistantArr.pop();
                answer++;
            }
             else{
                break;
             }
        }
        if(order[order.length-1]===i){
            //있다면 order앞에를 빼줌.
            order.pop();
            answer++;
            continue;
        }
        else{
            assistantArr.push(i);
        }
    }   
    return answer;
}