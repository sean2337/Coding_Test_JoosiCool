function solution(arr, divisor) {
    //divisor로 나누어지는 요소만을 배열로 다시 생성
  var answer = arr.filter((e) => e % divisor === 0);
  //나누어진게 없는지 check
    if (answer.length === 0) {
    answer.push(-1);
  }
    //오름차순 정렬
  answer.sort(function (a, b) {
    if (a > b) {
      return 1;
    } else {
      return -1;
    }
  });

  return answer;
}

