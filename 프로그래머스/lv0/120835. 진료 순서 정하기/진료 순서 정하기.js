function solution(emergency) {
  var answer = [];
    // 원래 있던 순서와 값을 같이 담아줄 배열 생성
  var pair = [];
    // 초기 순서와 값을 같이 담아줌.
  for (var i = 0; i < emergency.length; i++) {
    pair.push([emergency[i], emergency.length - i]);
  }

    //각각의 요소의 첫번째 값 기준으로 정렬
  pair.sort(function (a, b) {
    if (a[0] > b[0]) {
      return 1;
    } else {
      return -1;
    }
  });

    //이를 answer에 뒤에 값만 입력
  for (var i = 0; i < emergency.length; i++) {
    answer.push(pair[i][1]);
  }

  return answer;
}