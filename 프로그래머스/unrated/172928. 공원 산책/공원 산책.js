function solution(park, routes) {
    var answer = [];
    //s를찾아서 처음 위치 찾기
    var park_Y_Len = park.length;
    var park_X_Len = park[0].length;
    
    var curX,curY;
    
    for(var y = 0;y<park_Y_Len;y++){
        for(var x = 0;x<park_X_Len;x++){
         if(park[y][x]==="S"){
             curX = x;
             curY= y;
            }   
        }
    }
    
    
    for(var element of routes){
        // dir: 방향, dis: 거리
        let[dir, dis] = element.split(" ");
        dis = Number(dis);
        
        var nextX = curX;
        var nextY = curY;
        
        //남쪽이면 y방향으로 이동 +1
        if(dir==="S"){
            while(dis--){
                nextY++;
                // 가면 안될 곳일시
                if(nextY>=park_Y_Len){
                    nextX = curX;
                    nextY = curY;
                    break;
                }
                if(park[nextY][nextX]==="X"){
                    nextX = curX;
                    nextY = curY;
                    break;
                }
            }
        }
        //북쪽이면 y방향으로 이동 -1
        if(dir==="N"){
            while(dis--){
                nextY--;
                // 가면 안될 곳일시
                if(nextY<0){
                    nextX = curX;
                    nextY = curY;
                    break;
                }
                if(park[nextY][nextX]==="X"){
                    nextX = curX;
                    nextY = curY;
                    break;
                }
            }
        }
        //서쪽이면 w방향으로 이동 -1
        if(dir==="W"){
            while(dis--){
                nextX--;
                // 가면 안될 곳일시
                if(nextX<0){
                    nextX = curX;
                    nextY = curY;
                    break;
                }
                if(park[nextY][nextX]==="X"){
                    nextX = curX;
                    nextY = curY;
                    break;
                }
            }
        }
        //남쪽이면 y방향으로 이동 +1
        if(dir==="E"){
            while(dis--){
                nextX++;
                // 가면 안될 곳일시
                if(nextX>=park_X_Len){
                    nextX = curX;
                    nextY = curY;
                    break;
                }
                if(park[nextY][nextX]==="X"){
                    nextX = curX;
                    nextY = curY;
                    break;
                }
            }
        }
        
        curX = nextX;
        curY = nextY;    
    }
    return [curY,curX];
}