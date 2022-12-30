function solution(common) {
  var answer = 0;
    // 등차 구하기
  var minus = common[1] - common[0];
    // 배열을 등차수열에 관한것인지 모두 체크, 단 등차수열이 아니라면 등비수열임.
  for (var i = 1; i < common.length - 1; i++) {
    if (common[i + 1] - common[i] != minus) {
      check = 0;
      answer = common[common.length - 1] * (common[1] / common[0]);
      return answer;
    }
  }

  answer = common[common.length - 1] + minus;

  return answer;
}