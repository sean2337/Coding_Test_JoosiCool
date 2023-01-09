function solution(n) {
  var answer = 0;
  var threeAnswer = "";
  var three = 1;

  //three 구하기
  while (true) {
    if (n < three) {
      three = three / 3;
      break;
    } else {
      three *= 3;
    }
  }

  //3진법 구하기
  while (true) {
    if (three < 3) {
      if (n === 0) {
        threeAnswer += "0";
      } else {
        threeAnswer += n.toString();
      }
      break;
    }
    threeAnswer += Math.floor(n / three).toString();
    n = n - Math.floor(n / three) * three;
    three = three / 3;
  }

  // 뒤집기 과정
  threeAnswer = threeAnswer.split("").reverse();

  //십진법으로 다시 전환
  var newThree = 1;
  for (var i = threeAnswer.length - 1; i >= 0; i--) {
    answer += newThree * Number(threeAnswer[i]);
    newThree = newThree * 3;
  }

  return answer;
}