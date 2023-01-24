function solution(babbling) {
  var answer = 0;
  var checkArr = ["aya", "ye", "woo", "ma"];
  //babbling 하나씩 체크
  for (var i = 0; i < babbling.length; i++) {
    //각 요소가 checkArr에 해당하는 것이 있으면 숫자로 변경.
    for (var check = 0; check < checkArr.length; check++) {
      babbling[i] = babbling[i].replaceAll(checkArr[check], check);
    }
  }
  var onlyNumArr = [];
  for (var i = 0; i < babbling.length; i++) {
    //숫자만 가지고 있는 문자열만 onlyNumArr에 대입
    if (isNaN(babbling[i]) === false) {
      onlyNumArr.push(babbling[i]);
    }
  }
  //연속된 숫자가 있는지 확인, 단 길이가 1이라면 할 필요 없이 답임.
  for (var numCount = 0; numCount < onlyNumArr.length; numCount++) {
    if (onlyNumArr[numCount].length === 1) {
      answer++;
      continue;
    }
    for (
      var numIndex = 0;
      numIndex < onlyNumArr[numCount].length - 1;
      numIndex++
    ) {
      if (
        onlyNumArr[numCount][numIndex] === onlyNumArr[numCount][numIndex + 1]
      ) {
        break;
      }
      if (numIndex === onlyNumArr[numCount].length - 2) {
        answer++;
      }
    }
  }
  return answer;
}