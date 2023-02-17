function solution(priorities, location) {
    var answer = 0;
    var maxValue = Math.max(...priorities);
    while(true){
        var num = priorities.shift();
        location--;
        if(location===-1&&num===maxValue){
            return ++answer;
        }
        //최댓값과 같다면
        else if(num===maxValue){
            answer++;
            maxValue = Math.max(...priorities);
        }
        //최댓값이 아니라면 뒤로 이동
        else{
            priorities.push(num);
        }   
        
        if(location===-1){
            location = priorities.length-1;
        }
    }
}