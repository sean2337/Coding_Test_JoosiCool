function check(num){
  if (num < 5 && num != 2) return true;
  if ((num - 2) % 5 === 0) return false;

  return check(Math.floor(num / 5));
}

function solution(n, l, r) {
    var answer = 0;
    for(var i = l-1; i<r;i++){
      if(check(i)){
        answer++;
      }
    }
    return answer;
}