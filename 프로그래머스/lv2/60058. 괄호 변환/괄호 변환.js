//문자열을 넣으면 올바른 괄호인지 알려주는 함수
function correctBracket(bracket){
    bracket = bracket.split("");
    var stack = [];
    if(bracket[0]===")") return false;
    for(var i = 0;i<bracket.length;i++){
        if(bracket[i]===")"){
            if(stack[stack.length-1]==="("){
                stack.pop();
            }
            else{
                return false;
            }
        }
        else{
            stack.push(bracket[i]);
        }
    }
    if(stack.length===0) return true;
    else return false;
}


function algolithm(input){
    var arr = "";
    //1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
    if(input.length===0){
        return "";
    }
    //2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
    var count = 0;
    var index;
    //자를 기준 찾기
    for(var i = 0;i<input.length;i++){
        if(input[i]==="("){
            count++;
        }
        else{
            count--
        }
        if(count===0){
            index = i;
            break;
        }
    }
    //그 기준으로 u,v분리
    var u = input.substring(0,index+1);
    var v = input.substring(index+1);
    //3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
    if(correctBracket(u)===true){
       
        //3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
        arr +=u;
         arr+=algolithm(v);
        return arr;
    }
    //4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
    else{
        //4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
        arr+="(";
        // 4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
        arr+=algolithm(v);
        // 4-3. ')'를 다시 붙입니다. 
        arr+=")";
        //4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
        for(var uIndex = 1;uIndex<u.length-1;uIndex++){
            if(u[uIndex]==="("){
                arr+=")";
            }
            else{
                arr+="(";
            }
        }
        return arr;
    }
    
    
}

function solution(p) {
    return algolithm(p);
}