function solution(n_str) {
    var check = false;
    return n_str.split("").filter((element)=>{
        if(check === false && element === "0"){
            return false;
        }
        else{
            check = true;
            return true;
        }
    }).join("");
}