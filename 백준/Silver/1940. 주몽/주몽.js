const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./text.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");


var inputCount = Number(input.shift());
var need = Number(input.shift());
var count = 0;

input = input[0].split(" ").map(v=>Number(v));


function findNeed(startIndex, arr){

  if(startIndex >= arr.length-1){
    return "end";
  }

  var oneValue = arr[startIndex];
  for(var i = startIndex+1; i<arr.length;i++){
    //값이 있다면 제거
    if(oneValue+arr[i]===need){
      count++;
      arr.splice(i,1);
      arr.splice(startIndex,1);
      return startIndex;
    }
  }
  return startIndex+1
}

var start = 0;

while(start!=="end"){
  start = findNeed(start,input);
}
console.log(count);