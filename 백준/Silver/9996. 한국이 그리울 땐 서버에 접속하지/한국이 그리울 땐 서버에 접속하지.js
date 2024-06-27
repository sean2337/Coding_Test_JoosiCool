const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'testcase.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

let inCount = Number(input[0]);
let [f, e] = input[1].split('*');
let result = '';

function checkDA(str) {
  if (str.length < f.length + e.length) return 'NE';
  let frontIndex = str.indexOf(f);
  let endIndex = str.lastIndexOf(e);
  if (frontIndex === 0 && endIndex === str.length - e.length) return 'DA';
  else return 'NE';
}

for (let i = 2; i <= inCount + 1; i++) {
  let checkStr = input[i];
  result += checkDA(checkStr);
  result += '\n';
}
return console.log(result);
