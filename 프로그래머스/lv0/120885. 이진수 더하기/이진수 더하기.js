function solution(bin1, bin2) {
  var answer = "";

  if (bin1 === "0") return bin2;
  if (bin2 === "0") return bin1;

  //두개를 배열로 쪼갬.
  bin1 = bin1.split("");
  bin2 = bin2.split("");

  var bin1Num = 0;
  var bin2Num = 0;

  //bin1 수로 구하기
  var check = 1;
  for (var i = bin1.length - 1; i >= 0; i--) {
    if (bin1[i] == "1") {
      bin1Num += check;
    }
    check = check * 2;
  }

  //bin2 수로 구하기
  check = 1;
  for (var i = bin2.length - 1; i >= 0; i--) {
    if (bin2[i] == "1") {
      bin2Num += check;
    }
    check = check * 2;
  }

  //두 수 합치기
  var answerNum = bin1Num + bin2Num;

  //합친 수 이진수로 변환
  while (true) {
    if (Math.floor(answerNum / 2) == 0) {
      answer += "1";
      break;
    }
    answer += (answerNum % 2).toString();
    answerNum = (answerNum - (answerNum % 2)) / 2;
  }

  answer = answer.split("").reverse().join("");

  return answer;
}

