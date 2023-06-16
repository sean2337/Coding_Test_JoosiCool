function solution(my_string) {
    return my_string.split(" ").filter((element)=>{
        if(element === "")return false;
        return true;
    });
}