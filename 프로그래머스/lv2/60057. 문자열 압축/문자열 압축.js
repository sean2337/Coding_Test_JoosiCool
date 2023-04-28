function solution(s) {

    function sliceStr(count,str){
        if(count>=str.length){
            return count;
        }
        var resultLen = str.length;

        var checkStr = "";
        var checkCount = 1;
        for(var i = 0;i<str.length;i+=count){
            if(i===0){
                checkStr = str.substr(i,count);
            }
            //이전 배열이 있었다면
            else{
                //만약 그 배열이 같다면
                if(checkStr === str.substr(i,count)){
                    resultLen -= checkStr.length;
                    checkCount++;
                }
                else{
                    //발견한게 처음이라면 숫자도 추가
                    if(checkCount !==1 ){
                        while(checkCount>=1){
                            resultLen++;
                            checkCount = Math.floor(checkCount /10);
                        }
                    }
                    // 다르다면 checkStr과 count 초기화
                    checkStr = str.substr(i,count);
                    checkCount = 1;
                }
            }        
        }

        if(checkCount !==1 ){
            while(checkCount>=1){
                resultLen++;
                checkCount = Math.floor(checkCount /10);
            }
        }
        return resultLen;

    }
    var answer = sliceStr(1,s);

    for(var i = 2;i<=s.length;i++){
        if(answer>sliceStr(i,s)){
            answer = sliceStr(i,s);
        }
    }

    return answer;
}