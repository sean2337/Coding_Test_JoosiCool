function solution(sides) {
  var answer = 0;

  sides.sort(function (a, b) {
    if (a > b) {
      return 1;
    } else if (a == b) {
      return 0;
    } else {
      return -1;
    }
  });

  if(sides[2] >= sides[1] + sides[0]){
    answer = 2;
  }
  else{
    answer = 1;
  }

  return answer;
}