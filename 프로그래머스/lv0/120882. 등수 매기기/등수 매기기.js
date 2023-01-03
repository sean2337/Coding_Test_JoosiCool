function solution(score) {
  var answer = [];
  var averageArr = [];
  var average;
  for (var i = 0; i < score.length; i++) {
    average = (score[i][0] + score[i][1]) / 2;
    averageArr.push([average]);
  }

  for (var i = 0; i < score.length; i++) {
    answer.push(1);
    for (var k = 0; k < score.length; k++) {
      if (Number(averageArr[i]) < Number(averageArr[k])) {
        answer[i]++;
      }
    }
  }

  return answer;
}