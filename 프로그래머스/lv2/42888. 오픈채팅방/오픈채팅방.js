function solution(record) {
    var answer = [];
    //id와 닉네임을 저장할 해시 맵
    var idStore = new Map();    
    // Enter, Leave 들어온 값을 순서대로 방법과 id를 저장해둘 배열
    var inputArr = [];
    
    //record분류 작업
    record.forEach((element)=>{
        //0=> 방법, 1=> id, 2=> NickName
        element = element.split(" ");
        if(element[0]!=="Change"){
            inputArr.push([element[0],element[1]]);
        }
        if(element[0]!=="Leave"){
         idStore.set(element[1],element[2]);   
        }
    })
    
    //inputArr 분류 작업 시작 0=> 방법 1=> id
    inputArr.forEach((element)=>{
        if(element[0]==="Enter"){
            answer.push(idStore.get(element[1]) + "님이 들어왔습니다.")
        }
        else if(element[0]==="Leave"){
            answer.push(idStore.get(element[1]) + "님이 나갔습니다.")
        }
    })
    return answer;
}