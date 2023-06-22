function selfNumberFun(checkNum){
    var selfNumber = checkNum;
    var arr = checkNum.toString().split("");
    arr.forEach((element)=>{
        element = Number(element);
        selfNumber+=element;
    })
    return selfNumber;
}


// 셀프 넘버 몇개인지 체크하는 함수 => 인덱스에 해당하는 요소값이 셀프 넘버 몇개인지 
var numberArr = new Array(11000).fill(0);

for(var checkNum = 1; checkNum<=10000;checkNum++){
    numberArr[selfNumberFun(checkNum)]++;
}

for(var checkNum = 1; checkNum<=10000;checkNum++){
   if(numberArr[checkNum]===0){
        console.log(checkNum);
   }
}