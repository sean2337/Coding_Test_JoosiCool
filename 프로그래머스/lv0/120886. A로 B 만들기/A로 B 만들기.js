function solution(before, after) {
    var answer = 0;
    before = before.split("").sort().join("");
    after = after.split("").sort().join("");

    if(before.length != after.length){
        answer = 0;
        return answer;
    }

    if(before === after){
        answer = 1;
    }
    return answer;
}
