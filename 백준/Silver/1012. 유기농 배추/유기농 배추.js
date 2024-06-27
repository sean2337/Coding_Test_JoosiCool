const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'testcase.txt';
let input = fs.readFileSync(filePath).toString().split('\n');
let result = '';
let dx = [0, 0, 1, -1];
let dy = [1, -1, 0, 0];

let testCount = Number(input.shift());

for (let i = 0; i < testCount; i++) {
  let resultCount = 0;
  let [yLen, xLen, inCount] = input
    .shift()
    .split(' ')
    .map((v) => Number(v));
  //배추 배열 생성 및 초기화
  let arr = new Array(yLen);
  for (let j = 0; j < yLen; j++) {
    arr[j] = new Array(xLen).fill(0);
  }
  //인풋 받기
  for (let j = 0; j < inCount; j++) {
    let [y, x] = input
      .shift()
      .split(' ')
      .map((v) => Number(v));
    arr[y][x] = 1;
  }

  for (let y = 0; y < yLen; y++) {
    for (let x = 0; x < xLen; x++) {
      if (arr[y][x] === 1) {
        resultCount++;
        let queue = [[y, x]];
        arr[y][x] = 0;
        while (queue.length) {
          let [curY, curX] = queue.shift();
          for (let k = 0; k < 4; k++) {
            let nX = curX + dx[k];
            let nY = curY + dy[k];
            //범위를 나가거나 방문한 곳이라면 패스
            if (
              nX < 0 ||
              nY < 0 ||
              nX >= xLen ||
              nY >= yLen ||
              arr[nY][nX] === 0
            )
              continue;
            queue.push([nY, nX]);
            arr[nY][nX] = 0;
          }
        }
      }
    }
  }
  result += resultCount;
  result += '\n';
}

return console.log(result);
