function solution(M, N) {
  var answer = 0;
  // 가로 먼저 자르기 N-1
  // 세로 자르기 => (M-1) * (N)
  answer = (N-1)+(M-1)*N;
  return answer;
}