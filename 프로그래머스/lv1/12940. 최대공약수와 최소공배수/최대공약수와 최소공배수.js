function solution(n, m) {
  var answer = [];
  var maxDivisor;
  var minMultiple;

  var smallNum = n > m ? m : n;
  var bigNum = n > m ? n : m;

  //최대공약수 구하기
  for (var i = 1; i <= smallNum; i++) {
    if (n % i === 0 && m % i === 0) {
      maxDivisor = i;
    }
  }
  answer.push(maxDivisor);

  minMultiple = smallNum;
  //최소공배수 구하기
  // 작은 수를 구해서 작은 수에 배수가 큰 수와 나눠지는지 체크해서
  // 나눠지면 최소공배수임.
  while (true) {
    if (minMultiple % bigNum === 0) {
      answer.push(minMultiple);
      break;
    } else {
      minMultiple += smallNum;
    }
  }

  return answer;
}

