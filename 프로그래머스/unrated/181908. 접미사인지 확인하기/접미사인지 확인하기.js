function solution(my_string, is_suffix) {
    return my_string.split("").reverse().join("").indexOf(is_suffix.split("").reverse().join("")) === 0? 1: 0;
}