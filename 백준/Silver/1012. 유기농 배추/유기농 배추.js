const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'testcase.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

const maxNum = 54;
let dx = [-1, 1, 0, 0];
let dy = [0, 0, 1, -1];

let visited;
let yLen, xLen;

function DFS(y, x) {
  for (let k = 0; k < 4; k++) {
    let ny = y + dy[k];
    let nx = x + dx[k];
    if (ny < 0 || nx < 0 || ny >= yLen || nx >= xLen || visited[ny][nx])
      continue;
    visited[ny][nx] = true;
    DFS(ny, nx);
  }
}

let T = input.shift();
while (T--) {
  let [xLen, yLen, N] = input.shift().split(' ').map(Number);

  visited = Array.from({ length: maxNum }, () => {
    return new Array(maxNum).fill(true);
  });
  for (let i = 0; i < N; i++) {
    let [x, y] = input.shift().split(' ').map(Number);
    visited[y][x] = false;
  }

  let rnt = 0;
  for (let y = 0; y < yLen; y++) {
    for (let x = 0; x < xLen; x++) {
      if (!visited[y][x]) {
        visited[y][x] = true;
        DFS(y, x);
        rnt++;
      }
    }
  }
  console.log(rnt);
}