const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'testcase.txt';
const input = fs.readFileSync(filePath).toString().split('\n');

let len = Number(input.shift());

let arr = new Array(len);
for (let i = 0; i < len; i++) {
  arr[i] = input
    .shift()
    .split('')
    .map((v) => Number(v));
}

function quadTree(startY, startX, len) {
  let check = true;
  let checkValue = arr[startY][startX];
  for (let i = startY; i < startY + len; i++) {
    for (let j = startX; j < startX + len; j++) {
      if (checkValue !== arr[i][j]) {
        check = false;
      }
    }
  }
  if (check) return checkValue;
  else
    return (
      '(' +
      quadTree(startY, startX, len / 2) +
      quadTree(startY, startX + len / 2, len / 2) +
      quadTree(startY + len / 2, startX, len / 2) +
      quadTree(startY + len / 2, startX + len / 2, len / 2) +
      ')'
    );
}

console.log(quadTree(0, 0, len));
