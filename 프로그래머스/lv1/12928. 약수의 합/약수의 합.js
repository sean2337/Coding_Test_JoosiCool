function solution(n) {
  var answer = 0;
  var divArr = [];
  // 약수 구하기
  for (var i = 1; i <= n; i++) {
    if (n % i === 0) {
      divArr.push(i);
    }
  }

  //약수 더하기
  for (var i = 0; i < divArr.length; i++) {
    answer += divArr[i];
  }
  return answer;
}
console.log(solution(12));
