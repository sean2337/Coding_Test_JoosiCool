function solution(spell, dic) {
  var answer = 0;
  var check = true;
  // 숫자 체크
  for (var i = 0; i < dic.length; i++) {
    check = true;
    for (var k = 0; k < spell.length; k++) {
      if (dic[i].indexOf(spell[k]) == -1) {
        check = false;
        break;
      }
    }

    if (check === true) {
      answer = 1;
      break;
    } else {
      answer = 2;
    }
  }

  return answer;
}


