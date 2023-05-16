function solution(grid) {
  var answer = [];
  //0 => 우측으로 이동, 1=>위로 이동, 2=> 좌측으르 이동, 3=> 아래로 이동
  var dirIndex = 0;
  grid = grid.map((element)=>{
    return element.split("");
  })
  var xLen = grid[0].length;
  var yLen = grid.length;

  //함수에 현재 위치 좌표를 주면 그 다음 좌표를 리턴
  // 방향을 틀고 글로 이동한다. 
  // ex) current = [0,0]
  function coorFun(current){
    // 방향을 트는 과정
    if(grid[current[1]][current[0]]==="S"){

    }
    else if(grid[current[1]][current[0]]==="L"){
      // L에 걸리면 index 를 +1 해준다. 단, 3을 넘어가면 0으로 초기화
      dirIndex = dirIndex>=3? 0:dirIndex+1;
      current[2] = dirIndex;
    }
    else if(grid[current[1]][current[0]]==="R"){
      dirIndex = dirIndex<=0? 3:dirIndex-1;
      current[2] = dirIndex;
    }

    // dirIndex ===0 => 우측으로 이동
    if(dirIndex === 0){
      //x좌표에 1 증가
      current[0] = current[0] >= xLen -1  ? 0 : current[0]+1;
    }
    // 위로 이동
    else if(dirIndex===1){
      current[1] = current[1] >= yLen -1  ? 0 : current[1]+1;
    }
    // 좌측으로 이동
    else if(dirIndex===2){
      //x좌표에 1 감소
      current[0] = current[0] <=0 ? xLen - 1 : current[0]-1;
    }
    // 아래로 이동
    else if(dirIndex===3){
      //y좌표에 1 감소
      current[1] = current[1] <=0 ? yLen - 1 : current[1]-1;
    }
    return current;
  }


  
  var visitArr = Array.from(Array(yLen), () => Array.from(Array(xLen), () => Array(4).fill(false)));


  for(var dx = 0; dx<xLen;dx++){
    for(var dy = 0; dy<yLen;dy++){

      for(var i =0;i<4;i++){
        dirIndex = i;
        var plusArr = [];
        // 0,0, 방향
        var current = [dx,dy,dirIndex];
        if(visitArr[current[1]][current[0]][current[2]]){
          continue;
        }
        while(!visitArr[current[1]][current[0]][current[2]]){
          visitArr[current[1]][current[0]][current[2]] = true;
          plusArr.push([...current]);
          current = coorFun([...current]);
        }
        plusArr.forEach((element)=>{
            visitArr[element[1]][element[0]][element[2]] = true;  
        })
          
        answer.push(plusArr.length);
      }

    }
  }
  
  return answer.sort((a,b)=>a-b);
}