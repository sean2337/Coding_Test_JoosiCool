function solution(m, n, board) {
    var answer = 0;
    var checkAll = true;
    //기본적인 boardFun 틀 만들기
    var boardFun = new Array(m).fill([]);
    var boardRow;
    var plusArr = [];
    for(var i = 0;i<m;i++){
        boardRow = board[i].split("");
        plusArr = [];
        boardRow.forEach(element => {
            plusArr.push({value:element, check:false});
        });
        boardFun[i] = plusArr;
    }
    //반복한다. -> check가 false라면 탈출
    while(checkAll){
        checkAll = false;
           // 가로 +1 , 세로 +1 , 가로 +1 ,세로 +1 세개 다 현 요소와 같다면 체크
    for(var row = 0;row<m-1;row++){
        for(var col = 0;col<n-1;col++){
            var checking = boardFun[row][col];
            if(checking.value===boardFun[row+1][col].value&&checking.value===boardFun[row][col+1].value&&checking.value===boardFun[row+1][col+1].value){
                if(boardFun[row][col].check ===false){
                    boardFun[row][col].check = true;
                    answer++;
                    checkAll = true;
                }
                if(boardFun[row+1][col].check ===false){
                    boardFun[row+1][col].check = true;
                    answer++;
                    checkAll = true;
                }
                if(boardFun[row][col+1].check ===false){
                    boardFun[row][col+1].check = true;
                    answer++;
                    checkAll = true;
                }
                if(boardFun[row+1][col+1].check ===false){
                    boardFun[row+1][col+1].check = true;
                    answer++;
                    checkAll = true;
                }
            }
        }
    }


    
    // 함수가 비어있을때 아래 채워주는 함수
    for(var col = 0;col<n;col++){
        for(var row = m-1;row>=0;row--){
            if(boardFun[row][col].check === true){
                for(var i =row-1;i>=0;i--){
                    if(boardFun[i][col].check === false){
                        boardFun[row][col].value = boardFun[i][col].value;
                        boardFun[i][col].check = true;
                        boardFun[row][col].check = false;
                        break;
                    }
                }
            }
        }
    }
    

        // 체크 한 요소를 지우는 함수
        for(var row = 0;row<m-1;row++){
            for(var col = 0;col<n-1;col++){
                if(boardFun[row][col].check === true){
                    boardFun[row][col].value = "";
                }
            }
        }     
        
    }
    return answer;
}