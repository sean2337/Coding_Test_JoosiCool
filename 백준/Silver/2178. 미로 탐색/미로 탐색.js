const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'testcase.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

let dx = [-1, 1, 0, 0];
let dy = [0, 0, 1, -1];

let [yLen, xLen] = input[0].split(' ').map((v) => Number(v));
let visited = new Array(yLen);
for (let i = 0; i < yLen; i++) {
  visited[i] = new Array(xLen).fill(0);
}

let arr = new Array(yLen);
for (let i = 0; i < yLen; i++) {
  arr[i] = input[i + 1].split('').map((v) => Number(v));
}

let queue = [];
queue.push([0, 0]);
visited[0][0] = 1;
while (queue.length) {
  let [curY, curX] = queue.shift();
  for (let i = 0; i < 4; i++) {
    let nY = curY + dy[i];
    let nX = curX + dx[i];
    if (nY < 0 || nX < 0 || nY >= yLen || nX >= xLen || visited[nY][nX] !== 0)
      continue;
    if (arr[nY][nX] === 1) {
      visited[nY][nX] = visited[curY][curX] + 1;
      queue.push([nY, nX]);
    }
  }
}

return console.log(visited[yLen - 1][xLen - 1]);
