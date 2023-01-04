function solution(denum1, num1, denum2, num2) {
  var answer = [];
  var denum = denum1 * num2 + denum2 * num1;
  var num = num1 * num2;
  answer[0] = denum;
  answer[1] = num;

  var checkMin = answer[0] > answer[1] ? answer[1] : answer[0];
  for (var i = checkMin; i > 0; i--) {
    if (answer[0] % i === 0 && answer[1] % i === 0) {
      answer[0] = answer[0] / i;
      answer[1] = answer[1] / i;
    }
  }

  return answer;
}
