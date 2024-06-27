const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'testcase.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

let inCount = Number(input[0]);
let goal = Number(input[1]);

let arr = input[2]
  .split(' ')
  .map((v) => Number(v))
  .sort((a, b) => a - b);

let l = 0;
let r = inCount - 1;
let result = 0;
while (l < r) {
  if (arr[l] + arr[r] === goal) {
    result++;
    l++;
    r--;
  } else if (arr[l] + arr[r] > goal) {
    r--;
  } else l++;
}
return console.log(result);
