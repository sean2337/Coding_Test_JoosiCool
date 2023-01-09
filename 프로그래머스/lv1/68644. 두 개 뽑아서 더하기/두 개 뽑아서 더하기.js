function solution(numbers) {
  var answer = [];
  //모든 요소 더한 값 구하기
  for (var one = 0; one < numbers.length - 1; one++) {
    for (var two = one + 1; two < numbers.length; two++) {
      answer.push(numbers[one] + numbers[two]);
    }
  }

  //오름차순으로 정렬
  answer = answer.sort((a, b) => {
    if (a > b) {
      return 1;
    } else {
      return -1;
    }
  });

  //중복된거 빼기
  answer = [...new Set(answer)];

  return answer;
}

console.log(solution([2, 1, 3, 4, 1]));
