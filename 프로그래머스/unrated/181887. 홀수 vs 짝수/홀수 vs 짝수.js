function solution(num_list) {
    
    return num_list.reduce((a,b,idx)=>{if(idx%2===0) return a+b; else return a},0) >num_list.reduce((a,b,idx)=>{if(idx%2===1) return a+b; else return a},0)?num_list.reduce((a,b,idx)=>{if(idx%2===0) return a+b; else return a},0) : num_list.reduce((a,b,idx)=>{if(idx%2===1) return a+b; else return a},0) };