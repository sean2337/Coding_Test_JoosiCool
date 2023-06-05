function solution(num_list) {
    var sum = 0;
    var square = 1;
    num_list.forEach(element=>{
        sum+=element;
        square*=element;
    })
    return sum**2>square? 1: 0;
}