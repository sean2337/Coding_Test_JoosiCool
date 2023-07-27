const fs = require(`fs`);
const inputData = fs.readFileSync('dev/stdin').toString().trim().split('\n');
let word = inputData[0];

if(word===word.split("").reverse().join("")){
    console.log(1)
}
else{
    console.log(0);
}

