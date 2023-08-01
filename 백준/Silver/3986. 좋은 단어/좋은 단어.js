const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./text.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");


var inputCount = Number(input.shift());

function goodWordsFun(word){
  word = word.split("");
  var stack = [];
  word.forEach((element)=>{
    if(stack.length===0){
      stack.push(element);
    }
    else if(stack[stack.length-1] !== element){
      stack.push(element);
    }
    else{
      stack.pop();
    }
  })
  // 단어가 모두 사라져있으면 좋은 단어
  if(stack.length===0){
    return true;
  }
  else{
    return false;
  }
}

var count = 0;
input.forEach((element)=>{
  if(goodWordsFun(element)) count++;
})

console.log(count);