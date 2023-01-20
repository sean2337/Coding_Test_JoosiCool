function solution(k, score) {
  var answer = [];
  var threeArr = [];
  for (var i = 0; i < score.length; i++) {
    //k번째까지는 일단 score 넣기
    if (k > i) {
      threeArr.push(score[i]);
    } 
      // 이후에는 0번째 제일 작은거랑 비교해서 작다면 값 바꾸기 
      else {
      if (threeArr[0] < score[i]) {
        threeArr[0] = score[i];
      }
    }

      //그리고 정렬 다시 해준다.
    threeArr.sort((a, b) => {
      if (a > b) {
        return 1;
      } else {
        return -1;
      }
    });
    //제일 작은거 답에 추가
    answer.push(threeArr[0]);
  }

  return answer;
}