const fs = require(`fs`);
const inputData = fs.readFileSync('dev/stdin').toString().trim().split('\n');

let scoreArr = inputData.shift().split(" ").map(v=>Number(v));
scoreArr[1] *=2;
scoreArr[2] *=3;

let max = Number.MIN_SAFE_INTEGER;
let min = Number.MAX_SAFE_INTEGER;

var rangeArr = [];

inputData.forEach(((element)=>{
    let [start, end] = element.split(" ").map(v=>Number(v));
    rangeArr.push([start,end]);
    if(max<end){
        max = end;
    }
    if(min>start){
        min = start;
    }
}))

var result = 0;

for(var i = min + 0.5; i<max;i++){
    let count = 0;
    rangeArr.forEach(([start,end])=>{
        if(i>start && i<end){
            count++;
        }
    })
    if(count===0) continue;
    result+=scoreArr[count-1];
}

console.log(result);