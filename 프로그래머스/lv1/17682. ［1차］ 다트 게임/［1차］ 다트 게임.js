function solution(dartResult) {
    var answer = 0;
    var answerArr = [];
    var plusNum;
    for(var i = 0;i<dartResult.length;i++){
        if(dartResult[i]==='S'){
            if(dartResult[i-2]==='1'&&dartResult[i-1]==='0'){
                plusNum = 10;
            }
            else{
                plusNum = Number(dartResult[i-1]);
            }
            if(dartResult[i+1]==='#'){
                answerArr.push(-plusNum);
                continue;
            }
            answerArr.push(plusNum);
        }
        else if(dartResult[i]==='D'){
            if(dartResult[i-2]==='1'&&dartResult[i-1]==='0'){
                plusNum = 10;
            }
            else{
                plusNum = Number(dartResult[i-1]);
            }
            if(dartResult[i+1]==='#'){
                answerArr.push(-plusNum * plusNum);
                continue;
            }
            answerArr.push(plusNum * plusNum);
        }
        else if(dartResult[i]==='T'){
            if(dartResult[i-2]==='1'&&dartResult[i-1]==='0'){
                plusNum = 10;
            }
            else{
                plusNum = Number(dartResult[i-1]);
            }
            if(dartResult[i+1]==='#'){
                answerArr.push(-plusNum * plusNum * plusNum);
                continue;
            }
            answerArr.push(plusNum * plusNum * plusNum);
        }
        if(dartResult[i]==='*'){
            if(answerArr.length===1){
                answerArr[0] = answerArr[0] *2;
            }
            else{
                answerArr[answerArr.length-2] = answerArr[answerArr.length-2] *2;
                answerArr[answerArr.length-1] = answerArr[answerArr.length-1] *2;
            }
        }
    }

   
    answerArr.forEach(Element=>{
        answer+=Element;
    })


    return answer;
}
console.log(solution("1D2S#10S"))