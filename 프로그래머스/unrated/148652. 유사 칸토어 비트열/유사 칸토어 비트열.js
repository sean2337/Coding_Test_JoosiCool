function solution(n, l, r) {
    var answer = 0;
    n--;
    var arr = [1,1,0,1,1];
    while(n--){
        arr = arr.map((element)=>{
        return element*4;
        })
    }
    
    l--;
    r--;
    answer = arr[l%5] + arr[r%5];
    
    return answer;
}