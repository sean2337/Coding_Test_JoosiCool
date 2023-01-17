function solution(food) {
    var answer = '';
    var list = [0];
    for(var i =food.length ;i>0;i--){    
        if(food[i]%2===1){
            food[i]--;
        }
        
        //결과 배열에 요소 넣기-> 한번씩 번갈아가면서 넣기
        for(var k=0;k<food[i]/2;k++){
                list.push(i);
                list.unshift(i);
        }   
    }

    answer = list.join("");
    
    return answer;
}