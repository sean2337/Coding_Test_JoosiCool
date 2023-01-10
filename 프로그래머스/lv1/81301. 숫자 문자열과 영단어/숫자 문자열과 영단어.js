function solution(s) {
    var answer;
    //String 숫자 배열 생성
    var numArr = ["zero","one","two","three","four","five","six","seven","eight","nine"];
    
    //하나씩 있는지 체크 후에 있으면 그 숫자로 변환 -> replace함수 사용
    for(var i = 0;i<numArr.length;i++){
        s = s.replaceAll(numArr[i],i);
    }
    
    answer = Number(s);
    return answer;
}