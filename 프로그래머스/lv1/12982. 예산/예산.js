function solution(d, budget) {
  var answer = 0;

  //배열을 내림차순으로 정렬
  // 최대한 많은 곳에게 줄려면 적은 곳부터 주는게 효율적
  d = d.sort(function (a, b) {
    if (a > b) {
      return 1;
    } else {
      return -1;
    }
  });

 //예산이 - 될때까지 count
  for (var i = 0; i < d.length; i++) {
    if (budget - d[i] < 0) {
      return answer;
    } else {
      budget -= d[i];
      answer++;
    }
  }
    return answer;
}