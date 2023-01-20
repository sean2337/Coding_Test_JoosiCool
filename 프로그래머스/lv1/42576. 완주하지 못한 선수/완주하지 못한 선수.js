function solution(participant, completion) {
  var answer = "";
  //해쉬 맵 생성
  let hashMap = new Map();
  var value;

  //참여자들의 이름을 key, 참여자는들의 명수를 value로 저장.
  participant.forEach((element) => {
    if (hashMap.get(element) > 0) {
      value = hashMap.get(element) + 1;
      hashMap.set(element, value);
    } else {
      hashMap.set(element, 1);
    }
  });


  //완주자의 이름을 key로 찾아서 명수를 한명 떨어뜨림.
  completion.forEach((element) => {
    value = hashMap.get(element) - 1;
    hashMap.set(element, value);
  });

  //그리고 해쉬테이블에 남은 명수의 key 값이 답
  for (const [key, value] of hashMap) {
    if (value === 1) {
      answer = key;
    }
  }

  return answer;
}