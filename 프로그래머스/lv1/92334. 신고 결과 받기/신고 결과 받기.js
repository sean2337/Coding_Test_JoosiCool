function solution(id_list, report, k) {
    var answer = [];
    //신고당한 사람 기준에서 신고한 사람의 set을 가지고 있음
    var map = new Map();
    // 신고한 사람 기준 => 신고당한 사람의 set을 가지고 있음
    var toMap = new Map();
    
    //각각에 대한 해시테이블 만들기 key= id, value= 신고한 사람의 이름을 담을 셋
    id_list.forEach((element)=>{
        map.set(element, new Set());
    })

    //id = 신고한 사람의 id, value=신고 당한 사람의 모음
    id_list.forEach((element)=>{
        toMap.set(element, new Set());
    })
    
    //신고자에 따른 값 추가
    report.forEach((element)=>{
        element = element.split(" ");
        //신고한 사람
        var toPlayer = element[0];
        //신고 당한 사람
        var fromPlayer = element[1];
        
        map.set(fromPlayer, map.get(fromPlayer).add(toPlayer));
        toMap.set(toPlayer, toMap.get(toPlayer).add(fromPlayer));
        
    })
    
    
    // set에 담긴 크기가 k이상인 아이디 걸러내기
    id_list.forEach((element)=>{
        var count = 0;
        //신고한 사람이 누굴 신고했는지 다음 set에서 신고당한 사람 한명씩 가져오기
        for(var fromPlayer of toMap.get(element)){
            if((map.get(fromPlayer)).size>=k){
                count++;
            }
        }
        answer.push(count);
    })
    
    
    return answer;
}