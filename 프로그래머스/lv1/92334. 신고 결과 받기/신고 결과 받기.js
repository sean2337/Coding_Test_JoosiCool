function solution(id_list, report, check) {
  var answer = new Array(id_list.length).fill(0);

  var declationArr = [];
  var cancelArr = [];
  //신고 당한것을 카운트할 배열 생성
  for (var i = 0; i < id_list.length; i++) {
    var plusArr = [];
    for (var k = 0; k < id_list.length; k++) {
      plusArr.push(0);
    }
    declationArr.push(plusArr);
    cancelArr.push(0);
  }

  //[ [ 0, 0, 0, 0 ], [ 0, 0, 0, 0 ], [ 0, 0, 0, 0 ], [ 0, 0, 0, 0 ] ]
  //신고 카운트
  for (var i = 0; i < report.length; i++) {
    declationArr[id_list.indexOf(report[i].split(" ")[0])][
      id_list.indexOf(report[i].split(" ")[1])
    ]++;
    if (
      declationArr[id_list.indexOf(report[i].split(" ")[0])][
        id_list.indexOf(report[i].split(" ")[1])
      ] === 1
    ) {
      cancelArr[id_list.indexOf(report[i].split(" ")[1])]++;
    }
  }

  //메일 보낼 횟수 선정
  for (var i = 0; i < declationArr.length; i++) {
    for (var k = 0; k < declationArr[i].length; k++) {
      if (declationArr[i][k] !== 0 && cancelArr[k] >= check) {
        answer[i]++;
      }
    }
  }

  return answer;
}
