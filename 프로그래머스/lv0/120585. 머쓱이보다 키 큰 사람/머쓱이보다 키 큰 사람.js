function solution(array, height) {
  var answer = 0;
  array.forEach(element => {
    if(element>height){
      answer++;
    }
  });

  return answer;
}