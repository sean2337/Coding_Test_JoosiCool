function solution(array, n) {
  var answer = 0;
  array.forEach(element => {
    if(element===n){
      answer++;
    }
  });

  return answer;
}