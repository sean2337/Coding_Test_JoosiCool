function solution(k, tangerine) {
    var answer = 0;
    var hashMap = new Map();
    
    //해시에 key, value값 넣기
    for(var i = 0;i<tangerine.length;i++){
        if(hashMap.has(tangerine[i])){
            hashMap.set(tangerine[i],hashMap.get(tangerine[i])+1);
        }
        else{
            hashMap.set(tangerine[i],1);
        }
    }
    //해시 맵 정렬
    hashMap = [...hashMap].sort((a,b)=>a[1] - b[1]);
    while(k>0){
        k-=hashMap.pop()[1];
        answer++;
    }
    return answer;
}