const fs = require(`fs`);
const inputData = fs.readFileSync('dev/stdin').toString().trim().split('\n');
var firstNameMap = new Map();
let count = Number(inputData.shift());


inputData.forEach((element)=>{
    var firstName = element[0];
    if(firstNameMap.has(firstName)){
        var beforeCount = firstNameMap.get(firstName);
        firstNameMap.set(firstName, beforeCount+1);
    }
    else{
        firstNameMap.set(firstName, 1);
    }
})

var firstNameArr = new Array(...firstNameMap).sort((a,b)=>a[0].charCodeAt()- b[0].charCodeAt());
var answer = "";

//7이상인거 count;
firstNameArr.forEach((element)=>{
    if(element[1]>=5){
        answer+=element[0];
    }
})

if(answer.length===0){
    console.log("PREDAJA");
}
else{
    console.log(answer);
}