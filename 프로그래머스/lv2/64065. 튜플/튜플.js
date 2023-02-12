function solution(s) {
    var answer = [];
    const regex = /{+[0-9,]+}/g;
    //앞, 뒤 중괄호 제거
    s= s.substring(1,s.length-1);
    //괄호 형태로 되어 있는것 빼내기 [ '20,111', '111' ]
    var allArr = s.match(regex).map(element => element.substring(1,element.length-1));
    var plusArr = [];
    var numArr = [];
    var plusNum = "";
    //숫자로 배열로 재생성 [ [ 20, 111 ], [ 111 ] ]
    allArr.forEach(element => {
        for(var i = 0;i<element.length;i++){
            if(element[i]===","){
                plusArr.push(Number(plusNum));
                plusNum="";
            }
            else{
                plusNum+=element[i];
            }
        }
        plusArr.push(Number(plusNum));
        numArr.push(plusArr);
        plusArr = [];plusNum="";

    });
    // 배열 요소 순으로 정렬 [ [ 111 ], [ 20, 111 ] ]
    numArr = numArr.sort((a,b)=> {return a.length>b.length? 1: -1});
    for(var front =0;front<numArr.length;front++){
        answer.push(numArr[front][0]);
        for(var back = front + 1 ;back<numArr.length;back++){
            numArr[back].splice(numArr[back].indexOf(numArr[front][0]),1);
        }
    }
    return answer;
}