String.prototype.replaceAt = function(index, replacement) {
    if (index >= this.length) {
        return this.valueOf();
    }
 
    return this.substring(0, index) + replacement + this.substring(index + 1);
}

function solution(arr) {
    var answer = [0,0];
    const regex = /["0""1"]/g
    for(var i = 0;i<arr.length;i++){
        arr[i] = arr[i].join("");
    }
    //4
    var len = arr.length;
    var checkNum ="";
    while(true){
        //0 -> 4
        for(var i = 0;i<arr.length;i+=len){
            for(var k = 0;k<arr.length;k+=len){
                checkNum ="";
                if(arr[i][k]!=='0'&&arr[i][k]!=='1') continue;
                for(var l = 0;l<len;l++){
                    checkNum+=(arr[i+l].substr(k,len));
                }
              
                // 모두 같은 건지 체크
                for(var checkI=1;checkI<checkNum.length;checkI++){
                    if(checkNum[checkI] !== checkNum[0] ){
                        break;
                    }
                    //모두 같다면
                    if(checkI === checkNum.length-1){
                        answer[checkNum[0]]++;
                        //값 치환
                        for(var l = 0;l<len;l++){
                            for(var eraseI = k; eraseI<k+len;eraseI++){
                                arr[i+l] =arr[i+l].replaceAt(eraseI,"2");
                            }
                            
                        }
                    }

                }
                
            }
        }
        len = len/2;
        if(len<1) break;
    }

    //마지막 1한개 남은거 체크
    for(var i = 0;i<arr.length;i++){
        for(var k = 0;k<arr[i].length;k++){
            if(arr[i][k]==='0'||arr[i][k]==='1'){
                answer[arr[i][k]]++;
            }
        }
    }   
    return answer;
}