


function solution(n) {
    var dpArr = [0,1,2];
    
    for(var i =3;i<=n;i++){
        dpArr.push((dpArr[i-2]+dpArr[i-1])% 1000000007);
    }
    
    return dpArr[n];
}