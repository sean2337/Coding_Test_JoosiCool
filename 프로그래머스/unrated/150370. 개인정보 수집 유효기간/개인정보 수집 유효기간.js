function solution(today, terms, privacies) {
  var answer = [];
  //today 배열로 쪼개기
  //. 기준으로 쪼개면서 계산하기 편하게 숫자로 바꾸기 -> 2022, 5, 19
  var todayArr = today.split(".").map((item) => {
    return Number(item);
  });
  //term Hash 만들기
  var termsHash = [];
  var plusHash;
  for (var i = 0; i < terms.length; i++) {
    //공백 기준으로 나누기 -> A, 6
    plusHash = terms[i].split(" ");
    // A라는 값에 6을 저장
    termsHash[plusHash[0]] = Number(plusHash[1]);
  }
  //privacies 계산 시작
  var contractArr, contractKind;
  var contractDay = [];
  for (var i = 0; i < privacies.length; i++) {
    //"2021.05.02 A" -> 2021, 05, 02, A
    contractArr = privacies[i].split(/\.| /);
    // 무슨 종류인지 저장 -> A
    contractKind = contractArr[3];
    //contractDay 날짜 배열 생성 2021, 5, 2
    for (var k = 0; k < 3; k++) {
      contractDay[k] = Number(contractArr[k]);
    }

    var expiration_Date = [];
    // 연도, 월, 일
    expiration_Date[2] = contractDay[2];
    // A의 해당하는 월 더하기 -> 12개월이 넘어가면 12개월을 뺀다.
    expiration_Date[1] = (contractDay[1] + termsHash[contractKind]) % 12;
    if (expiration_Date[1] === 0) expiration_Date[1] = 12;
    // A의 연도 구하기
    if (contractDay[1] + termsHash[contractKind] <= 12) {
      expiration_Date[0] = contractDay[0];
    } else {
      if ((contractDay[1] + termsHash[contractKind]) % 12 === 0) {
        expiration_Date[0] =
          contractDay[0] +
          Math.floor((contractDay[1] + termsHash[contractKind]) / 12) -
          1;
      } else {
        expiration_Date[0] =
          contractDay[0] +
          Math.floor((contractDay[1] + termsHash[contractKind]) / 12);
      }
    }
    //expiration_Date와 todayArr 비교 연도 부터 비교
    //만료일이 오늘보다 지나있으면 파기

    for (var check = 0; check < 3; check++) {
      if (expiration_Date[check] < todayArr[check]) {
        answer.push(i + 1);
        break;
      } else if (expiration_Date[check] > todayArr[check]) {
        break;
      } else if (check === 2) {
        answer.push(i + 1);
      }
    }
  }

  return answer;
}