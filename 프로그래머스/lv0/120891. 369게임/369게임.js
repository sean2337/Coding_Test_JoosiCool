function solution(order) {
    var answer = 0;
    while(true){
        if(order/10<1)
        {
            if(order===3||order===6||order===9){
            answer++;
            }
                break;
        }
            
        
        if(order%10===3||order%10===6||order%10===9){
            answer++;
        }
        
        order = Math.floor(order/10);
    }
    
    
    return answer;
}