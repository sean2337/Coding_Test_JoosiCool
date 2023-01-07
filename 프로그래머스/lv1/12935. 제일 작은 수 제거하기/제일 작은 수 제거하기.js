function solution(arr) {
  var answer = [];

  var min = arr[0];
  //최소값 찾기
  for (var i = 1; i < arr.length; i++) {
    if (min > arr[i]) min = arr[i];
  }

  //최고값 찾아서 삭제시키기
  console.log(arr.indexOf(min), min);
  arr.splice(arr.indexOf(min), 1);
  //그런데 삭제시키고 보니 요소가 없으면 -1을 추가
  if (arr.length === 0) {
    arr.push(-1);
  }

  return arr;
}
