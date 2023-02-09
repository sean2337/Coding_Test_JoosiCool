function solution(n,a,b)
{
    var answer = 0;

    while(true){
        //짝수면
        if(a%2===0) a = a/2;
        else{ a= (a+1)/2}
        if(b%2===0) b = b/2;
        else{b=(b+1)/2}
        answer++;
        if(a===b) break;
    }

    return answer;
}