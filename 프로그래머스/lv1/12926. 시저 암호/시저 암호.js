function solution(s, n) {
  var answer = "";
  s = s.split("");
  s.forEach((element) => {
    //공백은 그냥 공백으로
    if (element === " ") {
      answer += " ";
    }
    //문자열이라면,
    else {
      //소문자 기준
      if (element.charCodeAt() >= 97 && element.charCodeAt() <= 122) {
        //더해서 넘으면 a로 이동
        if (element.charCodeAt() + n > 122) {
          answer += String.fromCharCode(element.charCodeAt() + n - 26);
        }
        //아니면 그냥 진행
        else {
          answer += String.fromCharCode(element.charCodeAt() + n);
        }
      } else {
        //대문자라면
        if (element.charCodeAt() + n > 90) {
          answer += String.fromCharCode(element.charCodeAt() + n - 26);
        }
        //아니면 그냥 진행
        else {
          answer += String.fromCharCode(element.charCodeAt() + n);
        }
      }
    }
  });

  return answer;
}

console.log(solution("Zzabe", 1));
