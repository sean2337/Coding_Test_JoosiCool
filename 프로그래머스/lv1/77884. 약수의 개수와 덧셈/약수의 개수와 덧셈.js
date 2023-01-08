function solution(left, right) {
  var answer = 0;
  //left 부터 하나 씩 체크 해보자.
  for (var i = left; i <= right; i++) {
    //약수 담을 배열
    var divArr = [];
    for (var div = 1; div <= i; div++) {
      if (i % div === 0) {
        divArr.push(div);
      }
    }

    //약수 짝수인지 홀수인지 체크
    if (divArr.length % 2 === 0) {
      answer += i;
    } else {
      answer -= i;
    }
  }

  return answer;
}


