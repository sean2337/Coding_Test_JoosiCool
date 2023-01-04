//기울기 구하는 함수 => (x,y) 두 점을 넣으면 기울기를 구함
function inclinationFun(a, b) {
  var inclination = (b[1] - a[1]) / (b[0] - a[0]);
  return inclination;
}

function solution(dots) {
  var answer = 0;
  var inclinationArr = [];
  //기울기 구해서 넣는 과정(이중 for문 활용)
  for (var i = 0; i < dots.length - 1; i++) {
    for (var k = i + 1; k < dots.length; k++) {
      inclinationArr.push(inclinationFun(dots[i], dots[k]));
    }
  }

  //기울기 같은게 있는지 체크
  for (var i = 0; i < inclinationArr.length - 1; i++) {
    for (var k = i + 1; k < inclinationArr.length; k++) {
      //같은게 있다면 1 return
      if (inclinationArr[i] === inclinationArr[k]) {
        return 1;
      }
    }
  }

  return answer;
}

