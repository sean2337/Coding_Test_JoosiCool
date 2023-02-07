function solution(s)
{
    var stack = [s[0]];
    
    for(var index = 1; index<s.length;index++)
    {
        //stack에 마지막 요소와 넣을 값이 같다면 마지막 요소 제거
        if(stack[stack.length-1]===s[index]){
            stack.pop();
        }
        else{
            stack.push(s[index]);
        }
    }
    
    if(stack.length === 0){
        return 1;
    }
    else{
        return 0;
    }
    
    
}