function Time(inTime,outTime){
    var resultTime;
    var timeArr = outTime.split(":");
    resultTime = Number(timeArr[0])*60 + Number(timeArr[1]);
    var timeArr = inTime.split(":");
    resultTime -= Number(timeArr[0])*60 + Number(timeArr[1]);
    return resultTime;
}

function solution(fees, records) {
    var answer = [];
    var splitArr = [];
    var parkArr = new Map();
    //parkArr의 요소 => {number:"0000", time:0, price=0, carNumber="000"}
    records.forEach((element)=>{
        //"05:34", "5961", "IN"
        splitArr = element.split(" ");
        
        //IN이라면?
        if(splitArr[2]==="IN"){
            // 해쉬 형태 => key: 차번호, value: [inTime, totalTime, 주차여부(true면 주차함)] 
            if(parkArr.has(splitArr[1])){
                //기존 꺼는 그대로 둠.
                parkArr.set(splitArr[1],[splitArr[0],parkArr.get(splitArr[1])[1], true,splitArr[1]]);
                
            }
            else{
                parkArr.set(splitArr[1],[splitArr[0],0, true,splitArr[1]]);
            }
        }
        //OUT이라면?
        else{
            var inTime = parkArr.get(splitArr[1])[0];
            var time = Time(inTime, splitArr[0])+ parkArr.get(splitArr[1])[1];
            
           parkArr.set(splitArr[1],[splitArr[0],time, false,splitArr[1]])
            
        }
    })
    console.log(parkArr);

    //가격 계산
    parkArr.forEach((element)=>{
        if(element[2]===false){
            if(fees[0]<element[1]){
                answer.push([element[3],fees[1]+Math.ceil((element[1]-fees[0])/fees[2]) * fees[3]]);
            }
            else{
                answer.push([element[3],fees[1]]);
            }
        }
        // 나간 기록이 없다면
        else{
            //23:59나간거로 간주
            var time = Time(element[0],"23:59")+ element[1];
            if(fees[0]<time){
                answer.push([element[3],fees[1]+Math.ceil((time-fees[0])/fees[2]) * fees[3]]);
            }
            //5000 + ⌈(334 - 180) / 10⌉ x 600 = 14600
            else{
                answer.push([element[3],fees[1]]);
            }
        }

    })
    var answerPrice = [];
    answer.sort((a,b)=>{
        if(Number(a[0]>Number(b[0]))){
            return 1;
        }
        else{
            return -1;
        }
    }).forEach((element=>{
        answerPrice.push(element[1]);
    }))
    return answerPrice;
}

console.log(solution([180, 5000, 10, 600] ,["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]));