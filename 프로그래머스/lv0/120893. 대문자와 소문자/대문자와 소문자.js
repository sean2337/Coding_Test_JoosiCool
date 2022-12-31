function solution(my_string) {
  var answer = "";

  for (var i = 0; i < my_string.length; i++) {
    //대문자인지 구별
    if (my_string[i] === my_string[i].toUpperCase()) {
      answer += my_string[i].toLowerCase();
    } else {
      answer += my_string[i].toUpperCase();
    }
  }
  return answer;
}