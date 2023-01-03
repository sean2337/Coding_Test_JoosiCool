function solution(dots) {
    var answer = 0;
    var length;
    var height;
    for(var i = 0;i<dots.length;i++){
        for(var k = 0;k<dots.length;k++){
            if((dots[i][0]!=dots[k][0])&&(dots[i][1]!=dots[k][1])){
                length = Math.abs(dots[i][0]-dots[k][0]);
                height = Math.abs(dots[i][1]-dots[k][1]);
                answer = length * height;
                return answer;
            }
        }
    }
    return answer;
}