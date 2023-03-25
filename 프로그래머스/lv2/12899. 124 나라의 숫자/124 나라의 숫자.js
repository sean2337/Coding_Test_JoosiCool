function solution(n) {
    var oneTwoFourArr = [4,1,2];
    var answer = '';
    while(true){
        //몫이 1이고 나머지가 0인경우 break;
        if((Math.floor(n/3)===1&&n%3===0)||(Math.floor(n/3)===0)){
            answer+=oneTwoFourArr[n%3];
            break;
        }
        answer+=oneTwoFourArr[n%3];
        if(Math.floor(n%3)===0){
            n = Math.floor(n/3)-1;
        }
        else{
            n = Math.floor(n/3);
        }      
    }
    return answer.split("").reverse().join("");
}