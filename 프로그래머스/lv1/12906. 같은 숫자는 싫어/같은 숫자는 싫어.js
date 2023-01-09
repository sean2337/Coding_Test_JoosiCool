function solution(arr) {
  var answer = [];
  var beforeNum;
  answer.push(arr[0]);
  for (var i = 1; i < arr.length; i++) {
    beforeNum = arr[i - 1];
    if (beforeNum !== arr[i]) {
      answer.push(arr[i]);
    }
  }

  return answer;
}
