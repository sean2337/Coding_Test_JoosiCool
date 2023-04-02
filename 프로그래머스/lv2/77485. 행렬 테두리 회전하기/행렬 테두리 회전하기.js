function solution(rows, columns, queries) {
    var answer = [];
    var table = new Array(rows);
    var plus = 1;
    for(var i = 0; i<rows;i++){
        table[i] = new Array(columns);
        for(var k = 0;k<columns;k++){
            table[i][k] = plus++;
        }
    }
    
    queries.forEach((element)=>{
        var enterArr = [];
        let [y1,x1,y2,x2] = element;
        x1--;
        x2--;
        y1--;
        y2--;
        var recHeight = y2- y1;
        var recLen = x2-x1;
       //첫 요소 저장 해두기
       var firstElement = table[y1][x1];
       //1번 내려가기
       for(var i =0;i<recHeight;i++){
        enterArr.push(table[y1][x1]);
        table[y1][x1] = table[y1+1][x1];
        y1++;
       }

        //2번 오른쪽
       for(var i =0;i<recLen;i++){
        enterArr.push(table[y1][x1]);
        table[y1][x1] = table[y1][x1+1];
        x1++;
       }

        //3번 위쪽
       for(var i =0;i<recHeight;i++){
        enterArr.push(table[y1][x1]);
        table[y1][x1] = table[y1-1][x1];
        y1--;
       } 
        
        //4번 왼쪽
       for(var i =0;i<recLen-1;i++){
        enterArr.push(table[y1][x1]);
        table[y1][x1] = table[y1][x1-1];
        x1--;
       }
       enterArr.push(table[y1][x1]);
       table[y1][x1] = firstElement;
       
       answer.push(Math.min(...enterArr));
    })
    return answer;
}