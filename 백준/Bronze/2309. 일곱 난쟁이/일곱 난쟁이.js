const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'testcase.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

let sum = 0;
let numArr = [];
let result = '';

input.forEach((v) => {
  numArr.push(Number(v));
  sum += Number(v);
});

for (let i = 0; i < numArr.length; i++) {
  for (let j = 0; j < i; j++) {
    if (sum - numArr[i] - numArr[j] === 100) {
      numArr.splice(i, 1);
      numArr.splice(j, 1);
      numArr.sort((a, b) => {
        return a - b;
      });

      numArr.forEach((v) => {
        result += v + '\n';
      });
      return console.log(result);
    }
  }
}
