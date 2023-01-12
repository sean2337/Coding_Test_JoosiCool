function solution(answers) {
    var answer = [];
    var collectArr = [0,0,0];
    var oneAnswer = 1;
    var twoAnswer = 1;
    var threeAnswer = 3;
    // 각 수포차에 맞는 문제를 collectArr 에 저장
    for(var i =0;i<answers.length;i++){
         // 1번 수포차 몇 문제 맞추는가? -> collect 0번째에 저장
        if(answers[i]===oneAnswer){
            collectArr[0]++;
        }
        oneAnswer++;
    
        if(oneAnswer===6){
            oneAnswer =1;
        }
    
        ///// 2번 수포차 몇 문제 맞추는가? -> collect 1번째에 저장

        if(i%2===0){
            if(answers[i]===2){
                collectArr[1]++;
            }
        }
        else{
            if(answers[i]===twoAnswer){
                collectArr[1]++;
            }
            twoAnswer++;
            if(twoAnswer===2){
                twoAnswer++;
            }
            if(twoAnswer>5){
                twoAnswer = 1;
            }
        }
    
        
        ///// 3번 수포차 몇 문제 맞추는가? -> collect 3번째에 저장
        
        if(i%2===0&&i!==0){
            
            if(threeAnswer===5){
                threeAnswer =3;
            }
            else if(threeAnswer===3){
                threeAnswer = 1;
            }
            else if(threeAnswer===2){
                threeAnswer +=2;
            }
            else{
                threeAnswer++;
            }
        }

        if(threeAnswer===answers[i]){
            collectArr[2]++;
        }


       
    }

    
    //제일 많이 맞춘거 구하기
    var max = collectArr[0];
    for(var i =1 ;i<3;i++){
        if(max<collectArr[i])
            max = collectArr[i];
    }
    
    //max 값에 해당하는거 answer에 대입
    for(var i =0 ;i<3;i++){
        
       if(max===collectArr[i]){
           answer.push(i+1);
       }
    }

    return answer;
}
