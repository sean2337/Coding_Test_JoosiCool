const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'testcase.txt';
const input = fs.readFileSync(filePath).toString().split('\n');

let dx = [0, 0, 1, -1];
let dy = [1, -1, 0, 0];

let [xLen, yLen] = input
  .shift()
  .split(' ')
  .map((v) => Number(v));

let arr = new Array(yLen);

for (let i = 0; i < yLen; i++) {
  arr[i] = input.shift().split('');
}

function DFS(goal) {
  let rnt = 0;
  //방문 배열 만들기
  let visited = new Array(yLen);
  for (let i = 0; i < yLen; i++) {
    visited[i] = new Array(xLen).fill(0);
  }

  for (let y = 0; y < yLen; y++) {
    for (let x = 0; x < xLen; x++) {
      if (visited[y][x] === 0 && arr[y][x] === goal) {
        let cnt = 1;
        visited[y][x] = 1;
        let queue = [[y, x]];
        while (queue.length) {
          let [cY, cX] = queue.shift();
          for (let i = 0; i < 4; i++) {
            let nY = cY + dy[i];
            let nX = cX + dx[i];
            if (
              nX < 0 ||
              nY < 0 ||
              nX >= xLen ||
              nY >= yLen ||
              visited[nY][nX] === 1 ||
              arr[nY][nX] !== goal
            )
              continue;
            cnt++;
            visited[nY][nX] = 1;
            queue.push([nY, nX]);
          }
        }
        rnt += cnt * cnt;
      }
    }
  }
  return rnt;
}

return console.log(DFS('W') + ' ' + DFS('B'));
