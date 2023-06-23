function solution(babbling) {
    var answer = 0;
    var canArr = ["aya", "ye", "woo", "ma"];

    
    
    //해당하는 것을 그 인덱스로 변경
    for(var i = 0;i<babbling.length;i++){
        canArr.forEach((element,idx)=>{
            babbling[i]=babbling[i].replaceAll(element,idx+1);
        })
    }
    

    
    for(var i = 0;i<babbling.length;i++){
        var check = babbling[i];
        
        // 모두 숫자라면
        if(!!Number(babbling[i])){
            
            var check_Dul = false;
            var before = check[0];
            for(var checkIndex = 1;checkIndex<check.length;checkIndex++){
                if(before === check[checkIndex]){
                    check_Dul = true;   
                    break;
                }   
                else{
                    before = check[checkIndex];
                }
            }
            
            if(check_Dul === false){
                answer++;
            }
            
        }
    }
     
    return answer;
}