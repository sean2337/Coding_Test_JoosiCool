function solution(s) {
    var answer = [-1];
    var compareArr = [];
    s=s.split("");
    var plus;
    // i는 비교하는 대상의 인덱스 값
    for(var i =1;i<s.length;i++){
        plus = -1;
        compareArr = s.slice(0,i);
        for(var k = 0;k<compareArr.length;k++){
            if(compareArr[k]===s[i]){
                plus= i-k;
            }
        }
         answer.push(plus);
    }
    return answer;
}