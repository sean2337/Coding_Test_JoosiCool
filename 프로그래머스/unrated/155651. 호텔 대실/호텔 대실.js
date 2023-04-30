function timeFun(a){
    var aTotal = a.split(":").join("");
    return Number(aTotal);
}

function plusTimeFun(a){
    var aTotal = a.split(":");
    aTotal[0] = Number(aTotal[0]);
    aTotal[1] = Number(aTotal[1]);
    if(aTotal[1]>=50){
        aTotal[0]++;
        aTotal[1] = (aTotal[1] + 10)-60; 
    }
    else{
        aTotal[1]+=10;
    }
    
    return aTotal[0]*100+aTotal[1];
}

function solution(book_time) {
    //오름차순으로 정렬
    book_time = book_time.sort((a,b)=>{
        if(a[0]>b[0]){
            return 1;
        }
        else{
            return -1;
        }
    })
    var roomArr = [book_time[0]];
    var frontElement;
    var backElement;
    for(var i = 1;i<book_time.length;i++){
        frontElement = book_time[i][0];
        backElement = book_time[i][1];
        var check = false;
        for(var rIndex = 0; rIndex < roomArr.length;rIndex++){
            if((plusTimeFun(roomArr[rIndex][1]))<=timeFun(frontElement)){
                roomArr[rIndex] = [frontElement,backElement];
                check = true;
                break;
            }
            
        }

        if(check===false){
            roomArr.push([frontElement,backElement]);
        }
    }

    return roomArr.length;
}
