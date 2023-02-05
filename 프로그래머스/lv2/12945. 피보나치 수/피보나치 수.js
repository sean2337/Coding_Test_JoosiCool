function solution(n) {
    
    var fivoArr= [0,1];
    if(n>2){
        for(var i =2;i<n+1;i++){
            fivoArr[i] = (fivoArr[i-1] + fivoArr[i-2])%1234567;
        }
    }
    
    return fivoArr[n];
}