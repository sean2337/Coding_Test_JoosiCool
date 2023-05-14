function coorFun(coord1, coord2){
  let [A,B,E] = coord1;
  let [C,D,F] = coord2;
  
  if((A*D) - (B*C) === 0){
    return 0;
}

  let x = ((B * F) - (E * D)) / ((A*D) - (B*C));
  let y = ((E * C) - (A * F)) / ((A*D) - (B*C));
  
  return [x,y];
  
}

function solution(line) {
  
  var meetArr = [];

  for(var i = 0;i<line.length;i++){
    for(var j = i+1;j<line.length;j++){
      meetArr.push(coorFun(line[i],line[j]));
    }
  }

  //교점 거르기 => 평행하지 않고 정수인 것만 모으기
  meetArr = meetArr.filter((element)=>{
    //평행하지 않고
    if(element!==0){
      //정수로만 이루어진 것
      if(element[0]===Math.floor(element[0]) && element[1]===Math.floor(element[1])){
        return true;
      }
      else{
        return false;
      }
    }
    else{
      return false;
    }
  })
  
  //[ [ -0, 4 ], [ -4, -4 ], [ 4, -4 ], [ 4, 1 ], [ -4, 1 ] ]
  //최대 y,x 최소 y,x값 찾기
  var maxY = Number.MIN_SAFE_INTEGER;
  var maxX = Number.MIN_SAFE_INTEGER;
  var minY = Number.MAX_SAFE_INTEGER;
  var minX = Number.MAX_SAFE_INTEGER;


  meetArr.forEach((element)=>{
    if(element[0]>maxX){
      maxX = element[0];
    }
    if(element[0]<minX){
      minX = element[0];
    }
    if(element[1]>maxY){
      maxY = element[1];
    }
    if(element[1]<minY){
      minY = element[1];
    }
  })


  var answer = Array.from(Array(maxY-minY+1),()=>new Array(maxX- minX+1).fill("."))

  meetArr.forEach((element)=>{
    answer[element[1]-minY][element[0]-minX] = "*";
  })

  answer = answer.map(element=>element.join(""));



  return answer.reverse();
}
