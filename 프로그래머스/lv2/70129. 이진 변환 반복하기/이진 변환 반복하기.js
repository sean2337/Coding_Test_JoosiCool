function solution(s) {
  //0 => 변화 카운트, 1 => 0 카운트
  var answer = [0, 0];
  var beforeLen;
  while (s !== "1") {
    beforeLen = s.length;
    //0인것은 삭제
    s = s.replaceAll("0", "");
    // 삭제한 0의 개수 카운트
    answer[1] += beforeLen - s.length;
    answer[0]++;

    s = s.length.toString(2);
  }
  return answer;
}