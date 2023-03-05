function solution(want, number, discount) {
    var answer = 0;
    var exNumber;
    var disCountArr;
    for(var i = 0;i<discount.length-9;i++){
        //10개 마다 짜르기
        disCountArr = discount.slice(i,i+10);
        //number를 계속 초기화(얕은 복사)
        exNumber = [...number];
        disCountArr.forEach((element)=>{
            //want에 그 값이 있다면
            if(want.indexOf(element)!==-1){
                exNumber[want.indexOf(element)]--;
            }
        })
        var check = true;
        exNumber.forEach((element)=>{
           //남아 있다면
            if(element>0){
                check = false;
            }
        })
        //모든 값이 0 이하라면,
        if(check===true){
            answer++;
      
        }
    }
    return answer;
}