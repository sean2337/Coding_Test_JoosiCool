const fs = require(`fs`);
const inputData = fs.readFileSync('/dev/stdin').toString().trim().split('\n').map(v=>Number(v));

const sortArr = inputData.sort((a,b)=>a-b);
const len = sortArr.length;

let answer = [];

function choice(index,sum, result){
    if(sum===100){
        answer.push(result);
        return;
    }
    else if(sum>100||index>=len){
        return;
    }
    else{
        for(index;index<len;index++){
            choice(index+1,sum+sortArr[index],[...result,sortArr[index]]);
        }
    }
}

choice(0,0,[]);
answer = answer.filter((element)=>element.length===7);
answer[0].forEach((element)=>{
    console.log(element);
})