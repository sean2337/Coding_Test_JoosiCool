function solution(array) {
  var answer = 0;
  array.sort(function (a, b) {
    if (a > b) return 1;
    else if (a == b) {
      return 0;
    } else {
      return -1;
    }
  });

  answer = array[Math.floor(array.length / 2)];
  return answer;
}