function solution(arr1, arr2) {
    var answer = [];
    
    //배열의 크기 지정
    var height = arr1.length;
    var width = arr1[0].length;
    
    for(var h = 0;h<height;h++){
        plusArr = [];
        for(var w =0;w<width;w++){
            plusArr.push(arr1[h][w]+arr2[h][w]);
        }
        answer.push(plusArr);
    }
    
    
    return answer;
}