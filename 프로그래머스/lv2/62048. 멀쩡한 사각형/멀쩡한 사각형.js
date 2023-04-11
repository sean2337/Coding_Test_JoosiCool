let getGCD = (num1, num2) => (num2 > 0 ? getGCD(num2, num1 % num2) : num1);

function solution(w, h) {
    // 최대 공약수 구하기
    let getGCD = (num1, num2) => (num2 > 0 ? getGCD(num2, num1 % num2) : num1);
    let GCD = getGCD(w,h);
    var eachW = w / GCD;
    var eachH = h / GCD;

    var plus = eachH + eachW - 1;

    answer = w * h - plus * GCD;
    return answer;
}