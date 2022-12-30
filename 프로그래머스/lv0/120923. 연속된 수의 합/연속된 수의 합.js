function solution(num, total) {
  var answer = [];
  //홀수라면..
  if (num % 2 == 1) {
    var oneArr = total / num;
    oneArr = oneArr - (num - 1) / 2;
  } 
    //짝수라면..
    else {
    var oneArr = total / num + 0.5 - num / 2;
  }
  for (var i = 0; i < num; i++) {
    answer.push(oneArr++);
  }
  return answer;
}