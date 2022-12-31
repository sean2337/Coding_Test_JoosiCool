function solution(n) {
    var answer = 0;
    
    var check;
    for(var i=1;i<=n;i++){
        check = 0;
        //약수 개수 체크
        for(var k=1;k<=i;k++){
            if(i%k===0){
                check++;
            }
        }
        
        if(check>2)
            answer++;
        
    }
    
    
    return answer;
}