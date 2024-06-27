const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'testcase.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n');

//key=성, value = count
let map = new Map();

let inCount = Number(input[0]);
for (let i = 1; i <= inCount; i++) {
  let checkStr = input[i][0];
  if (map.has(checkStr)) {
    map.set(checkStr, map.get(checkStr) + 1);
  } else {
    map.set(checkStr, 1);
  }
}
let arr = [];

for (let [a, b] of map) {
  if (b >= 5) {
    arr.push(a);
  }
}

if (arr.length === 0) {
  return console.log('PREDAJA');
}
return console.log(arr.sort().join(''));
