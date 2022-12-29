function solution(n) {
     var answer = 0;
  for (var i = n; i >= 0; i--) {
    if (n === i * i) {
      answer = 1;
      break;
    }
    if (i == 0) {
      answer = 2;
    }
  }
    return answer;
}