function solution(my_string) {
  var answer = 0;
  var arrNum = my_string.match(/\d+/g);

  if(arrNum ==null)
    return 0;
  for (var i = 0; i < arrNum.length; i++) {
    answer += Number(arrNum[i]);
  }

  return answer;
}

