function Factorization(n) {
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
        answer.push(i);
      } else {
        break;
      }
    }
    check = false;
  }

  return answer;
}

function solution(a, b) {
  var answer = 0;
  // 분모를 소인수 분해한 배열
  var denominator = Factorization(b);
  var numerator = Factorization(a);

  var check = true;

  for (var i = 0; i < denominator.length; i++) {
    //분모의 소인수가 분자에 존재한다면
    if (denominator[i] === 2 || denominator[i] === 5) {
      continue;
    } else if (numerator.indexOf(denominator[i]) != -1) {
      numerator.splice(numerator.indexOf(denominator[i]), 1);
    } else {
      check = false;
      break;
    }
  }

  if (check === true) {
    answer = 1;
  } else {
    answer = 2;
  }

  return answer;
}
