function solution(sides) {
  var answer = 0;
  var min;
  var max;
  //a가 제일 클때
  max = sides[0] + sides[1];
  //a가 제일 작을때
  if (sides[0] > sides[1]) min = sides[0] - sides[1];
  else {
    min = sides[1] - sides[0];
  }

  answer = max - min - 1;
  return answer;
}