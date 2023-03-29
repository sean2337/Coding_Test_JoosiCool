function solution(orders, course) {
    var answer = [];
    var pushString = "";
    var pushArr = [];

    // sum은 빈 문자열, index =0 초기 인덱스로 설정 count는 몇개까지 할껀지, 검색할 단어를 eachCourse로 둠.
    function dfs(sum,index,count,eachCourse){
    
        if(sum.length===count){
            pushArr.push(sum);
            return;
        }
        for(var i = index;i<eachCourse.length;i++){
            dfs(sum+=eachCourse[i],i+1,count,eachCourse);
            sum = sum.slice(0,-1);
        }
    }



    //2 3 4 에서 2라면 2개씩 잘라서 배열에 넣음.
    course.forEach(count => {
        orders.forEach(courses=>{
            dfs(pushString,0,count,courses);
        })   
    });


    var hashMap = new Map();
    for(var i =0; i<pushArr.length-1;i++){
        
        if(hashMap.has(pushArr[i])){
            hashMap.set(pushArr[i],hashMap.get(pushArr[i])+1);
        }
        else{
            hashMap.set(pushArr[i],1);
        }

        if(pushArr[i].length!==pushArr[i+1].length){
            var maxValue = 0;
            for (let [key, value] of hashMap) {
                if(maxValue<value&&key.length>=2&&value>1){
                    maxValue = value;
                }
            }

            for (let [key, value] of hashMap) {
                if(maxValue === value){
                    answer.push(key);
                }
            }

            hashMap.clear();
        }
    }

    //마지막 요소 처리
    if(hashMap.has(pushArr[pushArr.length-1])){
        hashMap.set(pushArr[pushArr.length-1],hashMap.get(pushArr[pushArr.length-1])+1);
    }
    else{
        hashMap.set(pushArr[i],1);
    }

    maxValue = 0;

    for (let [key, value] of hashMap) {
        if(maxValue<value&&key.length>=2&&value>1){
            maxValue = value;
        }
    }

    for (let [key, value] of hashMap) {
        if(maxValue === value){
            answer.push(key);
        }
    }

    return answer.sort();
}