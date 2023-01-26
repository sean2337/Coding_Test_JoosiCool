function solution(ingredient) {
  var answer = 0;
  var stack = [];
  for (var i = 0; i < ingredient.length; i++) {
    stack.push(ingredient[i]);

    //1231을 찾기
    if (
      stack[stack.length - 1] === 1 &&
      stack[stack.length - 2] === 3 &&
      stack[stack.length - 3] === 2 &&
      stack[stack.length - 4] === 1
    ) {
      answer++;
      for (var p = 0; p < 4; p++) {
        stack.pop();
      }
    }
  }

  return answer;
}