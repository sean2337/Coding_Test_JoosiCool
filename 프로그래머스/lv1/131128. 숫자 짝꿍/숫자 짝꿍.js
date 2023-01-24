function solution(X, Y) {
  var answer = "";
  //X,Y 수를 배열로 쪼갬
  var xArr = X.split("");
  var yArr = Y.split("");
  //x,y의 값이 0~9까지 각각 개수를 카운트 해줄 배열 생성
  var countArrX = new Array(10).fill(0);
  var countArrY = new Array(10).fill(0);
  xArr.forEach((element) => {
    countArrX[element]++;
  });
  yArr.forEach((element) => {
    countArrY[element]++;
  });

  //console.log(countArrX, countArrY);

  for (var i = 9; i >= 0; i--) {
    while (countArrX[i]-- && countArrY[i]--) {
      answer += i;
      //console.log(answer);
    }
  }

  if (answer === "") {
    return "-1";
  } else if (answer[0] === "0") {
    return "0";
  }

  return answer;
}
