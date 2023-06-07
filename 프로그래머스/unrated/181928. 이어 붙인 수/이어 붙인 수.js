function solution(num_list) {
    return Number(num_list.reduce((a,b)=>{return b%2===1?a+b:a},"")) + Number(num_list.reduce((a,b)=>{return b%2===0?a+b:a},"")) ;
}