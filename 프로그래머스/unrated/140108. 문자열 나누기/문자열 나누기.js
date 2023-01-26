function solution(s) {
  var answer = 0;

  var checkChar = s[0];
  var checkNum = 1;
  var otherNum = 0;
  for (var i = 1; i < s.length; i++) {
    //두 수가 같아진다면
    if (checkNum === otherNum) {
      answer++;
      checkChar = s[i];
      checkNum = 0;
      otherNum = 0;
    }

    //같다면 checkNum 증가, 다르면 otherNum에 증가
    if (s[i] === checkChar) {
      checkNum++;
    } else {
      otherNum++;
    }
  }

  //마지막 확인
  if (checkNum === otherNum) {
    answer++;
  }
  //아직 문자가 남아 있다면 하나 더 추가
  else if (checkNum !== 0 || otherNum !== 0) {
    answer++;
  }

  return answer;
}