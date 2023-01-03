function solution(numlist, n) {
  var answer = [];
  //기준이 되는 값 인덱스 값 설정
  numlist = numlist.sort(function (a, b) {
    if (Math.abs(n - a) > Math.abs(n - b)) {
      return 1;
    } else if (Math.abs(n - a) < Math.abs(n - b)) {
      return -1;
    } else {
        //같다면 큰수를 앞에 배치
      if (a > b) {
        return -1;
      } else {
        return 1;
      }
    }
  });
  answer = numlist;

  return answer;
}


