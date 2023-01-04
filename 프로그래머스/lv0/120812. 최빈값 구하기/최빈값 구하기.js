function solution(array) {
  var answer = 0;
  if (array.length === 0) {
    return 0;
  }
  var max = array[0];
  // 1000칸을 다 만들기엔 시간이 많이 들기 때문에, 원소의 최대값 구함.
  for (var i = 0; i < array.length; i++) {
    if (max < array[i]) {
      max = array[i];
    }
  }

  //각각의 원소의 빈도값을 카운트할 배열 생성
  var checkArr = new Array(++max).fill(0);

  for (var i = 0; i < array.length; i++) {
    checkArr[array[i]]++;
  }

  var many = checkArr[0];
  var check = false;
  for (var i = 1; i < max + 1; i++) {
    if (checkArr[i] > many) {
      many = checkArr[i];
      answer = i;
      check = false;
    } else if (checkArr[i] === many) {
      check = true;
    }
  }

  if (check === true) {
    return -1;
  }

  return answer;
}

