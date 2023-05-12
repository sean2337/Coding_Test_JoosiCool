function disCheck(arr){
   arr = arr.map((element)=>{
    return element.split("");
   })

  var moveX = [1,-1,0,0];
  var moveY = [0,0,1,-1];
  
   for(var x = 0;x<5;x++){
    for(var y = 0;y<5;y++){
      // 자기 원소가 P일때 상하좌우에 P가 없어야 한다. 
      if(arr[y][x] === "P"){
        for(var i =0;i<4;i++){
          var dx = x+ moveX[i];
          var dy = y + moveY[i];
          if(dx>=0 && dy>=0 && dx<=4 && dy<=4){
            if(arr[dy][dx]==="P"){
              return 0;
            }
          }
        }
      }

      if(arr[y][x]==="O"){
        var count = 0;
        for(var i =0;i<4;i++){
          var dx = x+ moveX[i];
          var dy = y + moveY[i];
          if(dx>=0 && dy>=0 && dx<=4 && dy<=4){
            if(arr[dy][dx]==="P"){
              count++;
            }
          }
        }

        if(count>1){
          return 0;
        }
      }
    }
   }
    return 1;
   
}

function solution(places) {
    var answer = [];
    for(var i = 0;i<places.length;i++){
       answer.push(disCheck(places[i]));
    }

    return answer;
}