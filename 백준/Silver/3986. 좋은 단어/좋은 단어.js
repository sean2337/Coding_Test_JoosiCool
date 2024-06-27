const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'testcase.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

function isGoodWord(word) {
  let stk = [];
  for (let i = 0; i < word.length; i++) {
    if (stk.length === 0 || stk[stk.length - 1] !== word[i]) {
      stk.push(word[i]);
    } else {
      stk.pop();
    }
  }
  if (stk.length === 0) {
    return true;
  } else return false;
}

let inCount = Number(input[0]);
let result = 0;
for (let i = 1; i <= inCount; i++) {
  if (isGoodWord(input[i])) result++;
}
return console.log(result);
