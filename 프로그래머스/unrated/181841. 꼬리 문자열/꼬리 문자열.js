function solution(str_list, ex) {
    var answer = '';
    return str_list.reduce((a,b)=>{return b.includes(ex)===true? a: a+b},"");
}