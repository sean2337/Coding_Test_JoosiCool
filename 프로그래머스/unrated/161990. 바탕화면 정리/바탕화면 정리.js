function solution(wallpaper) {
    var answer = [];
    var minX = 100;
    var minY = 100;
    var maxX = 0;
    var maxY = 0;
    
    
    for(var y = 0;y<wallpaper.length; y++){
        for(var x = 0; x<wallpaper[0].length;x++){
            //해당에 파일이 있으면 값을 체크
            if(wallpaper[y][x]==="#"){
                if(y>maxY){
                    maxY =y;
                }
                
                if(x>maxX){
                    maxX = x;
                }
                   
                if(y<minY){
                    minY =y;
                }
                
                if(x<minX){
                    minX =x;
                }
            }
        }    
    }
    
    

    return [minY,minX,maxY+1,maxX+1];
}