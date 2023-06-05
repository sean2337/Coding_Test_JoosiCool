function solution(num_str) {
    var answer = 0;
    num_str.split("").forEach((element)=>answer+=Number(element));
    return answer;
}