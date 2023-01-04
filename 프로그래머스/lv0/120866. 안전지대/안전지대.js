function solution(board) {
  var height = board.length;
  var width = board[0].length;
  var answer = 0;
  var checkArr = new Array(height);
  for (var h = 0; h < height; h++) {
    checkArr[h] = new Array(width).fill(0);
  }
  console.log(height, width);

  //세로
  for (var h = 0; h < height; h++) {
    //가로
    for (var w = 0; w < width; w++) {
      //만약 지뢰를 찾는다면
      if (board[h][w] === 1) {
        //걸린 기준에서 가로-1 ~ 가로+1 부터 세로 -1 ~ 세로 +1 칸 까지를 위험 구간 1로 지정
        for (var i = h - 1; i <= h + 1; i++) {
          /////
          if (i < 0) {
            i = 0;
          }
          if (i > height - 1) {
            break;
          }
          ///////

          for (var k = w - 1; k <= w + 1; k++) {
            ///////
            if (k < 0) {
              k = 0;
            }
            if (k > width - 1) {
              break;
            }
            ///////

            checkArr[i][k] = 1;
          }
        }
      }
    }
  }

  //0(안전구간)의 개수를 count해서 answer에 +해줌
  for (var i = 0; i < height; i++) {
    for (var k = 0; k < width; k++) {
      if (checkArr[i][k] === 0) {
        answer++;
      }
    }
  }

  return answer;
}

