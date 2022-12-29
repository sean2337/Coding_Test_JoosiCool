function solution(array) {
    var answer = 0;
  array.forEach((element) => {
    let num = String(element).split("");
    num.forEach((check) => {
      if (check === "7") {
        answer++;
      }
    });
  });
    return answer;
}