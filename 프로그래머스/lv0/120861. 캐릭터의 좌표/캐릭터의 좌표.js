function solution(keyinput, board) {
  var answer = [];
  var x = 0;
  var y = 0;

  for (var i = 0; i < keyinput.length; i++) {
    if (keyinput[i] === "left" && x > -(board[0] - 1) / 2) {
      x--;
    } else if (keyinput[i] === "right" && x < (board[0] - 1) / 2) {
      x++;
    } else if (keyinput[i] === "up" && y < (board[1] - 1) / 2) {
      y++;
    } else if (keyinput[i] === "down" && y > -(board[1] - 1) / 2) {
      y--;
    }
  }

  answer = [x, y];

  return answer;
}

