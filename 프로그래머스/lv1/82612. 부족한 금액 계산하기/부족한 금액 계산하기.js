function solution(price, money, count) {
  var answer = 0;
  var plusPrice;
  for (var i = 1; i <= count; i++) {
    plusPrice = price * i;
    money -= plusPrice;
    console.log(plusPrice, money);
  }

  if (money < 0) {
    answer = -money;
  }

  return answer;
}