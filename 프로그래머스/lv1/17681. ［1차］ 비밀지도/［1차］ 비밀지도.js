function solution(n, arr1, arr2) {
  var answer = [];

  // 각 배열을 2진수로 바꾸기 (자릿수 채워서) -> 이때는 string임
  for (var i = 0; i < n; i++) {
    arr1[i] = arr1[i].toString(2).padStart(n, "0");
    arr2[i] = arr2[i].toString(2).padStart(n, "0");
  }

  var plusStr;

  //암호 해독하기
  for (var w = 0; w < n; w++) {
    plusStr = "";
    for (var h = 0; h < n; h++) {
      if (arr1[w][h] === "1" || arr2[w][h] === "1") {
        plusStr += "#";
      } else {
        plusStr += " ";
      }
    }
    answer.push(plusStr);
  }

  return answer;
}

