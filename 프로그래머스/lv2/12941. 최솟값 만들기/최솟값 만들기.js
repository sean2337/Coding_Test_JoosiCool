function solution(A, B) {
  var answer = 0;
    //두 배열을 곱했을때 최소가 나오기 위해선, 제일 큰거 * 제일 작은거를 해줘야 작게 나온다.
    //따라서 한 배열은 오름차순, 한 배열은 내림차순으로 정렬 후, 곱셈을 진행
  A.sort((a, b) => {
    if (a > b) {
      return 1;
    } else {
      return -1;
    }
  });
  B.sort((a, b) => {
    if (a > b) {
      return -1;
    } else {
      return 1;
    }
  });

  for (var i = 0; i < A.length; i++) {
    answer += A[i] * B[i];
  }
  return answer;
}