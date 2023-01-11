function solution(n) {
  var answer = 0;
  //에라토스테네스의 체 이용
  var checkArr = new Array(n + 1).fill(true);

  for (var i = 2; i <= n; i++) {
    if (checkArr[i]) {
      answer++;
      for (var j = i + i; j <= n; j += i) {
        checkArr[j] = false;
      }
    }
  }

  return answer;
}

