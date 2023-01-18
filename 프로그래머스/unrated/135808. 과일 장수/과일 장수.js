function solution(k, m, score) {
  var answer = 0;
  //순위를 알기위한 sort 잡업
  score = score.sort((a, b) => {
    if (a > b) return -1;
    else {
      return 1;
    }
  });

  for (var i = m-1; i < score.length; i = i + m) {
    answer += score[i] * m;
  }

  return answer;
}
