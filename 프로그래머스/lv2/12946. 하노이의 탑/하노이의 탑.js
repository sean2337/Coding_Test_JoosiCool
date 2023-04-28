function solution(n) {
    var answer = [];
    
    function Hanoi(num,from,to,other){
        if(num==0)return;
        
        Hanoi(num-1,from,other,to);
        answer.push([from,to]);
        Hanoi(num-1,other,to,from);
    }
    
    Hanoi(n,1,3,2);
    
    return answer;
}