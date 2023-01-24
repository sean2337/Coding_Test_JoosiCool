function solution(board, moves) {
  var answer = 0;
  var stack = [];

  //움직이는 칸 하나씩 알고리즘 구현
  moves.forEach((catchElement) => {
    //위에서부터 값이 있는지 체크
    for (var i = 0; i < board.length; i++) {
      //값이 있는걸 발견했다면
      if (board[i][catchElement - 1] !== 0) {
        // 스택에 앞에 있는것과 넣을려는 값이 같다면 answer 2증가, stack에 있는걸 뺌.
        if (stack[stack.length - 1] === board[i][catchElement - 1]) {
          stack.pop();
          answer = answer + 2;
          board[i][catchElement - 1] = 0;
        } else {
          //stack에 넣고 이고 그 요소를 0으로 변경
          stack.push(board[i][catchElement - 1]);
          board[i][catchElement - 1] = 0;
        }
        break;
      }
    }   
  });
  return answer;
}

