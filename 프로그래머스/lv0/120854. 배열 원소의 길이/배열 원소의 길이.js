function solution(strlist) {
  var answer = [];
  strlist.forEach((element) => {
    answer.push(element.length);
  });

  return answer;
}
