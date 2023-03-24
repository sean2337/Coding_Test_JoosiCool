

function solution(number, k) {
    //stack
    var stack = [];
    var len = number.length;
    number = number.split("").reverse();
    //number에 있는거 하나씩 뺄꺼고 뺄때마다 k-1해줄껀데 0이 될때까지 반복
    while(number.length!==0&&k>0){
        // arr빼서 stack에 넣기
        stack.push(number.pop());
        //값이 앞에꺼가 더 크다면 
        while(k>0&&stack[stack.length-1]<number[number.length-1]){
            stack.pop();
            k = k-1;
        }
    }

    if(k!==0){
        stack = stack.slice(0,-k);
    }
    
    return stack.join("")+ number.reverse().join("");

}