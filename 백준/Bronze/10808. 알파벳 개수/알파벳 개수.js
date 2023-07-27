const fs = require(`fs`);
const inputData = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let word = inputData[0];
let answerArr = new Array(26).fill(0);


word.split("").forEach((alphabet)=>{
    let ascii = alphabet.charCodeAt();
    answerArr[ascii-97]++;
})

answerArr.forEach((element)=>{
    console.log(element);
})

