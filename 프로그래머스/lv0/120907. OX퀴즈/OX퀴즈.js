function solution(quiz) {
  var answer = [];
  var arr;

  for (var i = 0; i < quiz.length; i++) {
    arr = quiz[i].split(" ");

    if (arr[1] == "+") {
      if (Number(arr[0]) + Number(arr[2]) === Number(arr[4])) {
        answer.push("O");
      } else {
        answer.push("X");
      }
    }

    if (arr[1] == "-") {
      if (Number(arr[0]) - Number(arr[2]) === Number(arr[4])) {
        answer.push("O");
      } else {
        answer.push("X");
      }
    }
  }

  return answer;
}
