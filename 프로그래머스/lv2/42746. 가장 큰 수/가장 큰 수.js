function solution(numbers) {
    var answer = '';
    // 정렬 시작
    numbers = numbers.sort((a,b)=>{
        a = a.toString();
        b = b.toString();
        if((b+a)<(a+b))return -1;
    })
    
    answer = numbers.join("");
    if(answer[0]==='0') return '0';
    
    return answer;
}

