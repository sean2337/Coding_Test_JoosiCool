function solution(elements) {
    var answer = [];
    var first = 1;
    var length = elements.length;
    const element = [...elements,...elements];
    for(var k =0;k<length;k++){
        for(var i = 0;i<length;i++){
            answer.push(element.slice(i,i+first).reduce((a,b)=>(a+b)));
        }  
        first++;
    }     
    const result = [...new Set(answer)];
    return result.length;
}