//배열 값에 들어갔을때 모두 안나눠져야 true리턴
function divNotFunction(num,array){
    for(var i = 0;i<array.length;i++){
        if(array[i]%num===0){
            return false;
        }
    }
    return true;
}

// 배열 값에 들어갔을때 배열안에 모두 나눠져야 true리턴
function divFunction(num,array){
    for(var i = 0;i<array.length;i++){
        if(array[i]%num!==0){
            return false;
        }
    }
    return true;
}




function solution(arrayA, arrayB) {
    
    arrayA = arrayA.sort((a,b)=>a-b);  
    arrayB = arrayB.sort((a,b)=>a-b);    
    
    var answer1=0,answer2=0;
    
    for(var i = arrayA[0];i>=2;i--){
        if(divFunction(i,arrayA)){
            if(divNotFunction(i,arrayB)){
                answer1 = i;
                break;
            }
        }
    }
    
    for(var i = arrayB[0];i>=2;i--){
        if(divFunction(i,arrayB)){
            if(divNotFunction(i,arrayA)){
                answer2 = i;
                break;
            }
        }
    }
    
    
    
    return answer1>answer2? answer1 :answer2;
}