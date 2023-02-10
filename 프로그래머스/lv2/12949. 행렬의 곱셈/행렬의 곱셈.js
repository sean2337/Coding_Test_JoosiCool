function solution(arr1, arr2) {
    var answer = [];
    var row = arr1.length;
    var col = arr2[0].length;
    var middle = arr2.length;
    for(var r = 0;r<row;r++){
         var plusArr = [];
        for(var c = 0 ; c<col;c++){
            var plusNum =0;
            // 결과 배열 값 각각 구하는 구간
            for(var i = 0;i<middle;i++){
                plusNum += (arr1[r][i] * arr2[i][c]);
            }
            plusArr.push(plusNum);
        }
        answer.push(plusArr);
    }
    return answer;
}