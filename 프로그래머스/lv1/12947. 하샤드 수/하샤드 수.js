function solution(x) {
  var answer = true;
  var divNum = x;
  var div = 0;
  while (true) {
    div += x % 10;
    x = Math.floor(x / 10);
    console.log(x);
    if (x < 1) {
      break;
    }
  }

  if (divNum % div === 0) return answer;
  else {
    return false;
  }
}

