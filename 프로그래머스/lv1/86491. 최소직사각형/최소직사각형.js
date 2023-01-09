function solution(sizes) {
  var answer = 0;
  var width = sizes[0][0];
  var height = sizes[0][1];
  var checkW;
  var checkH;

  for (var i = 1; i < sizes.length; i++) {
    var changeSum = 0;
    var sum = 0;
    checkW = sizes[i][0];
    checkH = sizes[i][1];

    if (width > checkW && height > checkH) {
      continue;
    } else {
      if (checkW - width > 0) {
        sum += checkW - width;
      }
      if (checkH - height > 0) {
        sum += checkH - height;
      }

      if (checkW - height > 0) {
        changeSum += checkW - height;
      }
      if (checkH - width > 0) {
        changeSum += checkH - width;
      }

      if (sum < changeSum) {
        width = width > checkW ? width : checkW;
        height = height > checkH ? height : checkH;
      } else {
        width = width > checkH ? width : checkH;
        height = height > checkW ? height : checkW;
      }
    }
  }

  answer = width * height;
  return answer;
}


