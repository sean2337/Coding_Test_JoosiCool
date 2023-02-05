function solution(n) {
  var answer = 0;
  if (n === 1) {
    return 1;
  }
  // 반부터 체크 그 앞은 확인 안해도 가능
  for (var a = Math.floor(n / 2) + 1; a > 0; a--) {
    if (a % 2 === 1 && n % a == 0 && n / a - Math.floor(a / 2) > 0) {
      answer++;
      console.log(a);
    } else if (
      a % 2 === 0 &&
      n / a - Math.floor(n / a) === 0.5 &&
      n / a - a / 2 > 0
    ) {
      answer++;
    }
  }
  return answer;
}