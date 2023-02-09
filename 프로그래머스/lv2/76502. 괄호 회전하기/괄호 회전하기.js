function solution(s) {
    var answer = 0;
    var len = s.length;
    
    while(true){
        var stack = [];
        var popChar;
        var check = true;
        for(var i = len; i<s.length;i++){
            if(s[i]==="\("||s[i]==="\{"||s[i]==="\["){
                stack.push(s[i]);
            }
            else{
                popChar = stack.pop();
                if(s[i]===")"){
                    if(popChar!=="("){
                        check= false;
                        break;
                    }
                }
                else  if(s[i]==="}"){
                    if(popChar!=="{"){
                        check= false;
                        break;
                    }
                }
                else  if(s[i]==="]"){
                    if(popChar!=="["){
                        check= false;
                        break;
                    }
                }
            }
        }
        
        for(var k = 0;k<len;k++){
            if(s[k]==="("||s[k]==="{"||s[k]==="["){
                stack.push(s[k]);
            }
            else{
                popChar = stack.pop();
                if(s[k]===")"){
                    if(popChar!=="("){
                        check= false;
                        break;
                    }
                }
                else  if(s[k]==="}"){
                    if(popChar!=="{"){
                        check= false;
                        break;
                    }
                }
                else  if(s[k]==="]"){
                    if(popChar!=="["){
                        check= false;
                        break;
                    }
                }
            }
            
        }
        if(check === true && stack.length===0) answer++;
        
        len--;
        if(len===0) return answer;
    }
}
