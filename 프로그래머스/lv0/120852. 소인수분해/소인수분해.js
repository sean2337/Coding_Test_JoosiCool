function solution(n) {
  var answer = [];
  //중복 받는거 제거
  var check = false;
  var num = n;
  //어떤게 나누어지는 check
  for (var i = 2; i < num + 1; i++) {
    // 안나누어 질때 까지 반복
    while (true) {
      if (n % i == 0) {
        n = n / i;
        if (check === false) {
          answer.push(i);
          check = true;
        }
      } else {
        break;
      }
    }
    check = false;
  }

  return answer;
}
