function solution(my_string) {
    var answer = [];
    for(var i=0;i<my_string.length;i++){
        if(Number(my_string[i])>=0&&Number(my_string[i])<10){
            answer.push(Number(my_string[i]));
        }
        answer.sort(function(a,b){
        if(a>b){
            return 1;
        }
        else{
            return -1;
        }
                    
                    })
    }
    
    return answer;
}