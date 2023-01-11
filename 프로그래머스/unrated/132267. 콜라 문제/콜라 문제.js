function solution(a, b, n) {
  var answer = 0;
  while (true) {
    if (n < a) {
      return answer;
    }
    answer += Math.floor(n / a) * b;
    n = Math.floor(n / a) * b + (n % a);
  }
}

