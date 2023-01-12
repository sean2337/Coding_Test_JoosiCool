function solution(nums) {
    var answer = 0;
    var plusArr=[];

    //세개 뽑아서 더하는 경우의 수 plussArr에 넣어놓기
    for(var one =0;one<nums.length-2;one++){
        for(var two = one+1;two<nums.length-1;two++){
            for(var three = two+1;three<nums.length;three++){
                plusArr.push(nums[one]+nums[two]+nums[three]);
            }
        }
    }
    var check = true;
    
    plusArr.forEach(element => {
        check = true;
        for(var i = 2;i<element;i++){
            if(element%i===0){
                check = false;
                break;
            }     
        }
        if(check===true)
            answer++;
        
    })
    console.log(plusArr);
    
    
    return answer;
}

