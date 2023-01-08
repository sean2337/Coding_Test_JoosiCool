function solution(s) {
  var answer = false;
  var alphabet = /[a-zA-Z]/;
  //길이 확인
  if (s.length === 4 || s.length === 6) {
    //숫자만 있는지 확인
    //test 함수-> 하나라도 있으면 true임
    //indexOf 함수 -> 값이 있으면 그 부분의 인덱스 부분을 리턴 
    // 없으면 false return
    if (alphabet.test(s)===false) {
      return true;
    }
  }
  return answer;
}

console.log(solution("1234"));
