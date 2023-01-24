function solution(numbers, hand) {
  var answer = "";
  var keyArr = [1, 2, 3, 4, 5, 6, 7, 8, 9, "*", 0, "#"];
  const leftArr = [1, 4, 7];
  const rightArr = [3, 6, 9];
  var elementRow, elementCol;
  //현재 손 위치를 알려주는 변수
  var leftHand = [3, 0];
  var rightHand = [3, 2];

  numbers.forEach((element) => {
    //1,4,7 중에 입력 받으면 왼손으로 침.그 후에 왼손 위치 수정
    if (leftArr.indexOf(element) !== -1) {
      answer += "L";
      leftHand = [
        Math.floor(keyArr.indexOf(element) / 3),
        keyArr.indexOf(element) % 3,
      ];
      //console.log(leftHand);
    }
    //3,6,9 중에 입력 받으면 오른손으로 침. 그 후에 오른손 위치 수정
    else if (rightArr.indexOf(element) !== -1) {
      rightHand = [
        Math.floor(keyArr.indexOf(element) / 3),
        keyArr.indexOf(element) % 3,
      ];
      answer += "R";
      //console.log(rightHand);
    }
    // 중간에 있다면?
    else {
      // 그 요소에 배열 인덱스 값을 찾자.
      elementRow = Math.floor(keyArr.indexOf(element) / 3);
      elementCol = keyArr.indexOf(element) % 3;

      //그 후에 왼손 거리, 오른손 거리 비교
      var leftDistance =
        Math.abs(leftHand[0] - elementRow) + Math.abs(leftHand[1] - elementCol);
      var rightDistance =
        Math.abs(rightHand[0] - elementRow) +
        Math.abs(rightHand[1] - elementCol);
      //거리 기준으로 오른쪽이 가깝다면
      if (leftDistance > rightDistance) {
        rightHand = [elementRow, elementCol];
        answer += "R";
      }
      //거리 기준으로 왼쪽이 더 가깝다면
      else if (leftDistance < rightDistance) {
        leftHand = [elementRow, elementCol];
        answer += "L";
      }
      //두 거리가 같다면
      else {
        if (hand === "right") {
          rightHand = [elementRow, elementCol];
          answer += "R";
        } else if (hand === "left") {
          leftHand = [elementRow, elementCol];
          answer += "L";
        }
      }
    }
  });

  return answer;
}