

function solution(n) {
    
    var answer = [];
    
    function Hanoi(num, from, other, to){
    if(num === 0) {
        return;
    }else{
        // 받아온 원반 갯수보다 하나 적은 원반들을 목적지가 아닌 곳으로 재귀적으로 이동
        Hanoi(num - 1 , from, to, other);
        // 맨 아래 원반을 목적지로 이동시킴
        answer.push([from, to]);
        //다른 곳으로 옮겼던 원반들을 그 위에 얹음
        Hanoi(num - 1, other, from, to);
    }
}
    
    
    Hanoi(n,1,2,3);

    return answer;
}