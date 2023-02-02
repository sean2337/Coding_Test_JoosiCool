function solution(s){
    //괄호를 담아줄 스택생성
    var stack=[];
    if(s[0]==="\)"){
        return false;
    }
    //배열로 쪼개서 하나씩 확인
    var element= s.split("").forEach((element)=>{
        // 시작괄호가 들어온다면 stack에 push
        if(element ==="\("){
            stack.push(element);
        }
        // 닫는 괄호가 온다면
        else{
            //stack 위에꺼를 하나빼서 시작괄호인지 체크 아니라면 false
            if(stack.pop()!=="\("){
                return false;  
             }
        }
    })
    //마지막에 스택에 남는 괄호가 있는지 체크
    if(stack.length ===0){
        return true;
    }
    else{
        return false;
    }
}