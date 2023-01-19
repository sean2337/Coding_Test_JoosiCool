function solution(s) {
    var answer = '';
    
    //공백기준으로 배열을 만듬
    var numArr = s.split(" ");
    //최대값 = max, 최소값 = min
    var max = Number(numArr[0]);
    var min = Number(numArr[0]);
    
    //numArr의 요소를 하나씩 체크하면서 max, min 정해줌.
    numArr.forEach(element=>{
        if(Number(element)>max)
            max = Number(element);
        if(Number(element)<min)
            min = Number(element);  
    })
    
    //답 입력
    answer = min + " " + max;
    
    
    return answer;
}