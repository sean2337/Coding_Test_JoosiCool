function solution(number, limit, power) {
    var answer = 0;
    var divArr= [];
    //1부터 number까지 약수 구해서 divArr에 넣기
    for(var i =1;i<=number;i++){
        //i가 약수개수 구해야 할 수
        var divCount = 0;
        for(var div=1;div*div<=i;div++){
            if(i%div===0){
                divCount++;
                if(div*div<i){
                    divCount++;
                }
            }
        }
        //약수 개수가 limit보다 작거나 같으면 그냥 사면 됌.
        if(divCount<=limit){
           answer+=divCount
        }
        //그러나 크다면, power값으로 구매햐야된다.
        else{
            answer+=power;
        }

    }
    
    
    return answer;
}