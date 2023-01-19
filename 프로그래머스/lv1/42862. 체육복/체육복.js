function solution(n, lost, reserve) {
  var answer = 0;
  // student 번호 하나씩 체크
  for (var studentNum = 1; studentNum <= n; studentNum++) {
    //만약 잃어버렸는데, 여벌 배열에 있는지 먼저 체크
    if (lost.indexOf(studentNum) !== -1) {
      if (reserve.indexOf(studentNum) !== -1) {
        reserve.splice(reserve.indexOf(studentNum), 1);
        lost.splice(lost.indexOf(studentNum), 1);
      }
    }
  }

  for (var studentNum = 1; studentNum <= n; studentNum++) {
    // 잃어버린 리스트에 없다면, 체육복 있는 것 => answer++;
    if (lost.indexOf(studentNum) === -1) {
      answer++;
    }
    // 잃어버린 리스트에 있다면, reserve에 있는 배열 중에 입을 수 있는게 있나 작은것부터 체크
    else {
      //사이즈 -1 한게 있다면
      if (reserve.indexOf(studentNum - 1) !== -1) {
        answer++;
        reserve.splice(reserve.indexOf(studentNum - 1), 1);
      } else if (reserve.indexOf(studentNum + 1) !== -1) {
        answer++;
        reserve.splice(reserve.indexOf(studentNum + 1), 1);
      }
    }
  }

  return answer;
}

