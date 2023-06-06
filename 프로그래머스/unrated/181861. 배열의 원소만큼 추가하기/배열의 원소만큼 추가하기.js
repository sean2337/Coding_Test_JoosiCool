function solution(arr) {
    var answer = [];
    arr.forEach(element=>{
        var newArr = new Array(element).fill(element);
        answer.push(...newArr);
    })
    return answer;
}