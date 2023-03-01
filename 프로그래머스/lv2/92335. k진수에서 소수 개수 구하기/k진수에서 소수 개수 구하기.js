function solution(n, k) {
    var answer = 0;
    //k진수로 바꿈.
    var changeN = n.toString(k);
    var splitArr = changeN.toString().split("0").filter(element=>element!==""&&element!=="1");;
    console.log(splitArr);
    splitArr.forEach(element=>{
        for(var i =2; i<=Math.sqrt(element);i++){
            if(element%i===0) return;
        }
        answer++;
    })
    return answer;
}
