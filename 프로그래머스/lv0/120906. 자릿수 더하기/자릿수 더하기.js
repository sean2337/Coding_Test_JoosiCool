function solution(n) {
  var answer = 0;
  while (true) {
    if (n < 10) {
      answer += n;
      break;
    }

    answer += n % 10;
    n = Math.floor(n / 10);
  }
  return answer;
}