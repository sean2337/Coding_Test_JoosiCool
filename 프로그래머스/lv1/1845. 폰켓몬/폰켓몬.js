function solution(nums) {
  var answer = 0;
  //중복되는 값 제거
  var singleArr = [...new Set(nums)];
  var choice = nums.length / 2;

  if (choice > singleArr.length) {
    answer = singleArr.length;
  } else {
    answer = choice;
  }
  return answer;
}
