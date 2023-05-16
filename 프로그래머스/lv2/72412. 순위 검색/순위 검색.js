function solution(info, query) {
  var answer = [];
  var hashMap = new Map();

  const lowerBound = (arr, target) => {
    let left = 0;
    let right = arr.length; 
    while(left < right){
        const mid = Math.floor((left + right) / 2);

        if(arr[mid] >= target) right = mid;
        else left = mid + 1;
    }

    return left;
}

  //info나누기
  info = info.map((element)=>element.split(" "));
  info.forEach((element)=>{
    var score = Number(element.pop());
    var key = element.join("");
   
    if(!hashMap.has(key)){
      hashMap.set(key,[score]);
    }  
    else{
      hashMap.set(key,[...hashMap.get(key),score]);
    }
  })

  for(let[key,value] of hashMap){
    hashMap.set(key, value.sort((a,b)=> a-b));
  }


  query.forEach((element)=>{
    //-나 공백 기준으로 자름.
    element = element.split(/ and | |-/i).filter(e => e);
    //점수는 미리 뺴두고
    var score = element.pop();
    // hashMap의 키 중에 element의 모든 것이 잇는 것만을 거름.
    var keyArr = Array.from(hashMap.keys()).filter(key=> element.every(v=>key.includes(v)));
    var result = keyArr.reduce((a,c)=> a+hashMap.get(c).slice(lowerBound(hashMap.get(c),score)).length,0);
    
    answer.push(result);
  })
  

  return answer;
}