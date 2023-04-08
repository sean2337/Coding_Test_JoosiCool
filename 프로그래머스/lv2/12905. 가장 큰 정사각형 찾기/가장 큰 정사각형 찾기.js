


function solution(board)
{
    var row = board.length;
    var col = board[0].length;
    var answer = 0;   
    var map = new Array(row+1);
    for(var i = 0;i<=row;i++){
        map[i] = new Array(col+1).fill(0);
    }

    
    for(var i = 0;i<row;i++){
        for(var k = 0 ;k<col;k++){
            map[i+1][k+1] = board[i][k]
        }
    }

    for(var r = 1;r<=row;r++){
        for(var c = 1;c<=col;c++){
            if(map[r][c]!==0){
                map[r][c] = Math.min(map[r-1][c],map[r][c-1],map[r-1][c-1])+1;
                answer = Math.max(answer,map[r][c]);
            }
        }
    }
    return answer*answer;
}