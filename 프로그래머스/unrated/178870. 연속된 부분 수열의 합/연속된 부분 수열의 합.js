function solution(sequence, k) {
    var answer = [];
    var sum = 0;
    var head = 0;
    for(var i = 0; i<sequence.length;i++){
        sum+=sequence[i];
        if(sum>k){
            while(sum>k){
                sum -= sequence[head++];
            }
        }
        //같다면 리턴
      
        if(sum===k){
            answer.push([head,i]);
        }
 
    }

    var min = sequence.length;
    var result = [];
    answer.forEach((element)=>{
        if(min>(element[1]-element[0])){
            min = (element[1]-element[0]);
            result = [element[0],element[1]];
        }
    }) 
    return result;
}