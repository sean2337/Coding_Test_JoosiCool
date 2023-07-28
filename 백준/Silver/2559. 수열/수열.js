const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./text.txt";
let input = fs.readFileSync(filePath).toString().split("\n");

let [inputCount, sumCount] = input[0].split(" ").map((v) => Number(v));

let numArr = input[1].split(" ").map((v) => Number(v));

let result = 0;
// sumCount개씩 구하는 과정

//1. 우선적으로 sumCount만큼 인덱스 0부터 더해줌.
for (var i = 0; i < sumCount; i++) {
  result += numArr[i];
}

let answer = result;

//2. 그 다음부터 앞에껀 빼주고 뒤에껀 더해주면서 감.
for (var i = 1; i <= inputCount - sumCount; i++) {
  result -= numArr[i - 1];
  result += numArr[i + sumCount - 1];
  if (result > answer) {
    answer = result;
  }
}
console.log(answer);
