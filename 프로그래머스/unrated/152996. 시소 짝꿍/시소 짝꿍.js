function solution(weights) {
  var answer = 0;
  var arr = {};
  weights.map((element) => {
    if (arr[element] === undefined) {
      arr[element] = 1;
    } else {
        answer+=arr[element];
      arr[element]++;
    }
  });

  var keyArr = Object.keys(arr);
  var result = {};
  for (var i = 2; i <= 4; i++) {
    keyArr.forEach((element) => {
      var temp = element * i;
      if (result[temp] === undefined) {
        result[temp] = arr[element];
      } else {
        answer += result[temp] * arr[element];
        result[temp] += arr[element];
      }
    });
  }

  return answer;
}

