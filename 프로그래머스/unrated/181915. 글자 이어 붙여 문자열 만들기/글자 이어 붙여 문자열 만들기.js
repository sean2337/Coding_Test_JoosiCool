function solution(my_string, index_list) {
    return index_list.reduce((a,b)=>{return a+my_string[b]},"");
}