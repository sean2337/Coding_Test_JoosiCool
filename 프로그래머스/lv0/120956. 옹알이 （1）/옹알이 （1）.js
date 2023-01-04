function solution(babbling) {
  var answer = 0;
  var checkArr = ["aya", "ye", "woo", "ma"];

  //babbling을 하나씩 체크
  for (var i = 0; i < babbling.length; i++) {
    //checkArr에 있는 값들을 찾고 있다면 빼줄것임.
    //단, 빈칸으로 대체시에 합쳐지면서 예외가 생길 수 있기 떄문에,
    // 이를 방지하기 위해 $문자로 대체
    for (var k = 0; k < checkArr.length; k++) {
      babbling[i] = babbling[i].replace(checkArr[k], "$");
    }
    //마지막에 $이걸 없애기 빈칸이 되어있나 확인
    babbling[i] = babbling[i].split("$").join("");
    if (babbling[i] === "") {
      answer++;
    }
  }

  return answer;
}