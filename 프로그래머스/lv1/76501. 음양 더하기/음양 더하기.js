function solution(absolutes, signs) {
  var answer = 0;
  var check = 0;
  // true면 그대로, false면 -를 붙임
  absolutes = absolutes.map((e) => {
    if (signs[check++] === true) {
      return e;
    } else {
      return -1 * e;
    }
  });

  //각각의 요소를 더함.
  absolutes.forEach((element) => {
    answer += element;
  });

  return answer;
}

