function solution(numbers, k) {
    var answer = 0;
    var arrLen = numbers.length;
    var location = 1;
    k--;
    while(k--){
        location +=2;
        if(location>arrLen){
            location = location - arrLen;
        }
    }
    answer = location;
    return answer;
}