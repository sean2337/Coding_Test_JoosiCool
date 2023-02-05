function solution(n) {
    var answer = n;
    //n을 이진수로 변화해서 nTwo에 저장해둔다.
    var nTwo = n.toString(2);
    var count = nTwo.length - nTwo.replaceAll(1,"").length;
    var answerTwo;
    //answer의 1의 개수와 입력값의 1의 개수가 같을때까지 아래 반복
    while(answer++){
        answerTwo = answer.toString(2);
        if(count === answerTwo.length - answerTwo.replaceAll(1,"").length){
            break;
        }
    }
    return answer;
}