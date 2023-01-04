function solution(lines) {
  var answer = 0;
  //겹치는 부분을 count 해줄 배열 생성
  var countArr = new Array(205).fill(0);
  //각각 하나씩 체크
  for (var i = 0; i < lines.length; i++) {
    //그 영역에 +
    for (var k = lines[i][0]; k < lines[i][1]; k++) {
      countArr[k + 100]++;
    }
  }

  for (var i = 0; i < countArr.length; i++) {
    if (countArr[i] >= 2) {
      answer++;
    }
  }

  return answer;
}

