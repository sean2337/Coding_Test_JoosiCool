function solution(cacheSize, cities) {
    var answer = 0;
    const cache_size = cacheSize;
    const cache_memory = new Array(cache_size).fill(null);
    if(cacheSize===0){
        return cities.length*5;
    }
    cities.forEach((element)=>{
        element = element.toLowerCase();
    const idx  = cache_memory.indexOf(element);
    //캐시에 없는데이터라면(HIT)
    if(idx === -1){
        answer+=5;
        // 공간이 비어져있다면 데이터를 캐시에 저장
        if(cache_memory.length<cache_size){
            cache_memory.push(element);
        }
        else{
            //꽉 차있다면 제일 앞에 있는거 빼주고 데이터 캐시에 저장
            cache_memory.shift();
            cache_memory.push(element);
        }
    }
    //캐시에 있는 데이터라면, 그 부분을 tail로 이동 (MISS)
    else{
        answer+=1;
        cache_memory.splice(idx,1);
        cache_memory.push(element);  
    }
})  
    return answer;
}