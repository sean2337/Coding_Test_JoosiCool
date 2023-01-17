function solution(N, stages) {
    var answer = [];
    var stageFailArr = new Array(N+1);
    
    
    // stage마다 count 0으로 생성
    for(var i =0;i<=N;i++){
        stageFailArr[i] = [i,0];
    }
    

    
    // 실패율 구하기
    for(var i =1;i<=N;i++){
        var count = stages.length;
        var sameCount = 0;
        stages.forEach(element =>{
            if(element<i){
                count--;
            }
            if(element===i){
                sameCount++;
            }
        })

        stageFailArr[i][1] = sameCount/count;
    }

    //정렬 하기
    stageFailArr.sort(function(a,b){
        if(a[1]>b[1])
            return -1;
        else{
            return 1;
        }
    })

    // 0 stage는 없음으로 이를 무시해주고, stage 정렬을 answer에 push
    for(var i =0;i<stageFailArr.length;i++){
        if(stageFailArr[i][0]===0){
            continue;
        }
        answer.push(stageFailArr[i][0])
    }

    
    return answer;
}
