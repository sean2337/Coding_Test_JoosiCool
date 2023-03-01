function solution(n, t, m, p) {
    var answer = [];
    //게임에서 해당 되는 숫자 
    var num = 0;
    var checkNum;
    //내가 몇개 말했는지 변수
    var count = 0;
    //순서
    var order = 1;
    while(true){
        if(count===t) return answer.join("").toUpperCase();
        checkNum = num.toString(n).split("");
        for(var i = 0; i<checkNum.length;i++){
            if(p===m) p=0;
            else if(order%m===p){
                answer.push(checkNum[i]);
                count++;
                if(count===t) break;
             }
             order++;
        }
        num++;
    }    
}