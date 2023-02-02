function solution(s) {
  var answer = 0;
  var arr = s.toLowerCase().split(" ");
  if (arr.length === 0) {
    return "";
  }
  arr = arr.map((element) =>
    element ? element[0].toUpperCase() + element.substring(1) : ""
  );

  answer = arr.join(" ");
  return answer;
}