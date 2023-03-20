

function solution(numbers) {
    //숫자 쪼개기
    numbers = numbers.split("");
    //Set함수로 중복 제거
    var output = new Set();
    //완전 탐색 순열 함수 
    function Permutation(leftoverArr,arr,output){
        //leftoverArr => 잔여 배열 남은거, arr = > 담긴 배열
        if(leftoverArr.length===0){
            output.add(Number(arr.join("")));
            return;
        }
        if(output.size!==0){
            output.add(Number(arr.join("")));
        }
        leftoverArr.forEach((element,index)=>{
            const leftover = [...leftoverArr.slice(0,index), ...leftoverArr.slice(index+1)];
            Permutation(leftover,[...arr,element],output);
        })
    }

    Permutation(numbers,[],output);
    var answer = output.size;
    for (let item of output){
        if(item===1||item===0){
            answer--;
            continue;
        }
        var divCheck = 0;
        for(var div = 2;div<=item;div++){
            if(item%div===0){
                divCheck++;
            }
          	//만약 나눠지는 수가 1보다 크다면 소수가 아니라 판단 소수 개수를 하나 줄이고 break
            if(divCheck>1){
                answer--;
                break;
            }
        }
    }

    return answer;
}