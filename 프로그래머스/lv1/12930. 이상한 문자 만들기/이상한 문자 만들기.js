function solution(s) {
  var answer = "";
  s = s.split(" ");
  for (var index = 0; index < s.length; index++) {
    for (var i = 0; i < s[index].length; i++) {
      //짝수라면, 대문자로
      if (i % 2 === 0) {
        answer += s[index][i].toUpperCase();
      }
      //홀수라면 소문자로
      else {
        answer += s[index][i].toLowerCase();
      }
    }
    if (index === s.length - 1) break;
    answer += " ";
  }
  return answer;
}


