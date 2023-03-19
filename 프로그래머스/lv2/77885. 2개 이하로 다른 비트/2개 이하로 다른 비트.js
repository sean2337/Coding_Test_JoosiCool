function solution(numbers) {
    var answer = [];
    numbers.forEach((element)=>{
        //짝수라면
        if(element%2===0){
            answer.push(element+1)
        }
        //홀수라면
        else{
            var bianryNum = element.toString(2);
            for(var i = bianryNum.length-1;i>=0;i--){
                if(bianryNum[i]==='0'){
                    answer.push(element+2**(bianryNum.length-i-1)-2**(bianryNum.length-i-2));
                    break;
                }
                if(i===0){
                    answer.push(element+2**(bianryNum.length-i)-2**(bianryNum.length-i-1));
                }
            }

        }

    })
    return answer;
}