function solution(s) {
  var answer = 0;
  var arr = s.split(" ");
  answer = Number(arr[0]);
  for (var i = 1; i < arr.length; i++) {
    if (arr[i] === "Z") {
      answer -= Number(arr[i - 1]);
    } else {
      answer += Number(arr[i]);
    }
  }

  return answer;
}