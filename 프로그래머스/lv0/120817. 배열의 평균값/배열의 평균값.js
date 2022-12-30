function solution(numbers) {
  var answer = 0;
  numbers.forEach((element) => {
    answer += element;
  });
  answer = answer / numbers.length;
  return answer;
}
