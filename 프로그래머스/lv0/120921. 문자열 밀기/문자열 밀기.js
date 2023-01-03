function solution(A, B) {
    if(A===B){
        return 0;
    }
  var check = A;
  var len = check.length;
  var answer = 0;
  for (var i = 0; i < 101; i++) {
    check = A;
    A = "";
    A += check[check.length - 1];
    for (var k = 0; k < check.length - 1; k++) {
      A += check[k];
    }
    
    answer++;

    if (A == B) {
      return answer;
    }
  }

  return -1;
}


