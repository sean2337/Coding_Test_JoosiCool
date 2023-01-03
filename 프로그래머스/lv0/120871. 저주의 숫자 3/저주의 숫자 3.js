function solution(n) {
  var answer = 0;
  var checkStr;
  for (var i = 1; i <= n + 1; i++) {
    if (answer === 0) {
      answer++;
      continue;
    }
    while (true) {
      if (answer % 3 === 0 || answer.toString().split("").indexOf("3") != -1) {
        answer++;
      } else {
        console.log(answer);
        answer++;
        break;
      }
    }
  }

  answer--;

  return answer;
}

