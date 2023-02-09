function solution(arr) {
    var answer = 1;
    var maxNum = Math.max(...arr);
    var divArr = new Array(maxNum+1).fill(0);
   
    // 최대 약수 구하기
    for(var arrIndex = 0;arrIndex<arr.length;arrIndex++){
        for(var i = 2; i<=arr[arrIndex];i++){
            var divCount = 0;
            while(true){
                if(arr[arrIndex]%i===0){
                    arr[arrIndex] = arr[arrIndex] / i;
                    divCount++
                }
                else{
                    if(divCount>divArr[i]) divArr[i] = divCount;
                    break;
                }
            }
        }
    }

    //구한 약수 최소공배수에 곱하기
    for(var i =1;i<divArr.length;i++){
        for(var mul = 0; mul<divArr[i];mul++){
            answer *= i;
        }
    } 
    return answer;
}