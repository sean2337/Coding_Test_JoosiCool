const fs = require(`fs`);
const inputData = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

var count = Number(inputData.shift());

var [startPattern, endPattern] = inputData.shift().split("*");

const regex = new RegExp(`^${startPattern}.*${endPattern}$`, 'gi');

inputData.forEach((element)=>{

    if(element.search(regex) !== -1){
        console.log("DA");
    }
    else{
        console.log("NE");
    }
})