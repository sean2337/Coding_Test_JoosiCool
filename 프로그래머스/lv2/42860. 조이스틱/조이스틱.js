function solution(name) {
    var answer = 0;
    var min = name.length-1;

    for(var i = 0;i<name.length;i++){
        var plus = name.charCodeAt(i);
        // 위 아래 과정
        if(plus<78){
            answer+= (plus % 65);
        }
        else{
            answer += (91-plus);
        }

        // 좌 우 과정
        var nextIndex = i + 1;
        while(nextIndex<name.length && name.charCodeAt(nextIndex)===65){
            nextIndex +=1;
        }
        //i + 2 * (name.length - idx),
        min = Math.min(min, (i*2) + name.length - nextIndex, i + 2 * (name.length - nextIndex));
    }

    answer+= min;

    return answer;
}