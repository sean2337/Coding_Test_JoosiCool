function solution(id_pw, db) {
  var answer = "";
  var index = -1;
  //id 있는지 check
  for (var i = 0; i < db.length; i++) {
    if (db[i][0] === id_pw[0]) {
      index = i;
      break;
    } else {
      if (i === db.length - 1) {
        answer = "fail";
        return answer;
      }
    }
  }

  if (id_pw[1] === db[index][1]) {
    answer = "login";
  } else {
    answer = "wrong pw";
  }

  return answer;
}