const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'testcase.txt';
const input = fs.readFileSync(filePath).toString().split('\n');

let [count, len] = input
  .shift()
  .split(' ')
  .map((v) => Number(v));

let countMap = new Map();
let valueArr = input
  .shift()
  .split(' ')
  .map((v) => Number(v));

valueArr.forEach((v) => {
  if (countMap.has(v)) {
    countMap.set(v, countMap.get(v) + 1);
  } else {
    countMap.set(v, 1);
  }
});
let rnt = '';
let countArr = new Array(...countMap);
countArr
  .sort((a, b) => b[1] - a[1])
  .forEach((v) => {
    for (let i = 0; i < v[1]; i++) {
      rnt += v[0];
      rnt += ' ';
    }
  });

return console.log(rnt);
