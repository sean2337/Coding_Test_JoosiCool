function solution(arr, k) {
    arr = arr.map((element)=>{
        if(k%2===1){
            return element*k;
        }
        else{
            return element+k;
        }
    })
    return arr;
}