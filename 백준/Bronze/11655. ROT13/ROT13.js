const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'testcase.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

function ROTC13(c) {
  let cNum = c.charCodeAt();
  if (cNum >= 65 && cNum <= 90) {
    cNum += 13;
    if (cNum > 90) {
      cNum -= 26;
    }
  } else if (cNum >= 97 && cNum <= 122) {
    cNum += 13;
    if (cNum > 122) {
      cNum -= 26;
    }
  }
  return String.fromCharCode(cNum);
}

let checkStr = input[0];
console.log(
  [...checkStr]
    .map((v) => {
      return ROTC13(v);
    })
    .join('')
);
