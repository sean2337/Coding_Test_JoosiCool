function solution(survey, choices) {
  var answer = "";
  var score = [];
  //각 유형 점수 해쉬 생성
  score["R"] = 0;
  score["T"] = 0;
  score["C"] = 0;
  score["F"] = 0;
  score["J"] = 0;
  score["M"] = 0;
  score["A"] = 0;
  score["N"] = 0;

  //각 요소마다 계산 시작
  for (var i = 0; i < survey.length; i++) {
    if (choices[i] > 4) {
      score[survey[i][1]] += choices[i] - 4;
    } else {
      score[survey[i][0]] += 4 - choices[i];
    }
  }
  //R,T 유형도 점수 비교
  if (score["R"] >= score["T"]) {
    answer += "R";
  } else {
    answer += "T";
  }
  //C,F 유형도 점수 비교
  if (score["C"] >= score["F"]) {
    answer += "C";
  } else {
    answer += "F";
  }

  //J,M 유형도 점수 비교
  if (score["J"] >= score["M"]) {
    answer += "J";
  } else {
    answer += "M";
  }
  //A,N 유형도 점수 비교
  if (score["A"] >= score["N"]) {
    answer += "A";
  } else {
    answer += "N";
  }
  return answer;
}