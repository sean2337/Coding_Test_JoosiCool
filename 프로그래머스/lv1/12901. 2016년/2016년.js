function solution(a, b) {
  var answer;
  var dayArr = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
  var answerArr = ["FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"];
  var totalDay = 0;


    
  // 5월이라면 4월까지의 수를 더함
  for (var i = 0; i < a - 1; i++) {
    totalDay += dayArr[i];
  }
  // 그리고 일수를 더함
  totalDay += (b-1);

  var day = totalDay % 7;

  answer = answerArr[day];

  return answer;
}
