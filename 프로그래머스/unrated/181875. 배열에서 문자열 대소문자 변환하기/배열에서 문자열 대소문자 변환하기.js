function solution(strArr) {
    return strArr.map((element,index)=>{
        if(index%2===0) return element.toLowerCase();
        else return element.toUpperCase();
    });
}