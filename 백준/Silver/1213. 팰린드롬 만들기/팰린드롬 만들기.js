const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./text.txt";
let input = fs.readFileSync(filePath).toString().trim().split("");

//input = 문자열
function solution(input){
  //알파벳을 저장해둘 Map
  var map = new Map();
  var right = "";
  var left = "";
  var center = "";
  var evenCount = 0;

  //Map에 값 넣기 => key, value
  for(var element of input){
    if(map.has(element)){
      map.set(element,map.get(element)+1)
    }
    else{
      map.set(element,1)
    }
  }

  //홀, 짝 구분
  for(let [key, value] of map){
    if(value%2===1){
      evenCount++;
      center = key;
    }
  }

  if(evenCount>1){
    return "I'm Sorry Hansoo";
  }
  else{
    //홀수라면 그 값 제거
    if(evenCount===1){
      map.set(center,map.get(center)-1);
    }

    // 정렬
    var mapArr = new Array(...map);
    mapArr = mapArr.sort((a,b)=>a[0].charCodeAt()-b[0].charCodeAt())
    mapArr.forEach(element=>{
      for(var i = 0;i<Math.floor(element[1]/2);i++){
        left += element[0];
      }
    })
    right = left.split("").reverse().join("");
    return left + center + right;
  }
}

console.log(solution(input));