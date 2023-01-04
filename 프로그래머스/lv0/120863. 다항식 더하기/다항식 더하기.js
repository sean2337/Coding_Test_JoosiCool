function solution(polynomial) {
  var answer = "";
  var polyArr = [];

  //0=> X항 계수, 1 => 상수항 계수
  var xArr = [];
  var numArr = [];
  var sumArr = [0, 0];

  polyArr = polynomial.split(" + ");
  for (var i = 0; i < polyArr.length; i++) {
    if (polyArr[i].indexOf("x") != -1) {
      if (polyArr[i] === "x") {
        xArr.push("1");
      } else {
        xArr.push(polyArr[i].replace("x", ""));
      }
    } else {
      numArr.push(polyArr[i]);
    }
  }

  //X항 더하는 과정
  for (var i = 0; i < xArr.length; i++) {
    sumArr[0] += Number(xArr[i]);
  }
  for (var i = 0; i < numArr.length; i++) {
    sumArr[1] += Number(numArr[i]);
  }

  //X항이 0일때
  if (sumArr[0] === 0) {
    if (sumArr[1] === 0) {
      return 0;
    }
    answer = sumArr[1].toString();
  }
  //X항은 있고, 상수항이 0일떄
  else if (sumArr[1] === 0) {
    if (sumArr[0] === 1) {
      answer = "x";
    } else {
      answer = sumArr[0].toString() + "x";
    }
  }
  // 둘다 있을때
  else {
    if (sumArr[0] === 1) {
      answer = "x + " + sumArr[1].toString();
    } else {
      answer = sumArr[0].toString() + "x + " + sumArr[1].toString();
    }
  }

  return answer;
}

