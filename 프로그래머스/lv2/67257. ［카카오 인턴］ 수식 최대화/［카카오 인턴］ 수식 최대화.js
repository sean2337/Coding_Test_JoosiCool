const getPermutations = function (arr, selectNumber) {
    if (selectNumber === 1) return arr.map((el) => [el]); 
    // n개중에서 1개 선택할 때(nP1), 바로 모든 배열의 원소 return. 1개선택이므로 순서가 의미없음.

    const results = [];

    arr.forEach((fixed, index, origin) => {
      const rest = [...origin.slice(0, index), ...origin.slice(index+1)] 
      // 해당하는 fixed를 제외한 나머지 배열 
      const permutations = getPermutations(rest, selectNumber - 1); 
      // 나머지에 대해서 순열을 구한다.
      const attached = permutations.map((el) => [fixed, ...el]); 
      //  돌아온 순열에 떼 놓은(fixed) 값 붙이기
      results.push(...attached); 
      // 배열 spread syntax 로 모두다 push
    });

    return results; // 결과 담긴 results return
}

function solution(expression) {
    //부호 파싱하기
    var signArr = [];  
    if(expression.includes("*")){
        signArr.push("*");
    }
    if(expression.includes("+")){
        signArr.push("+");
    }
    if(expression.includes("-")){
        signArr.push("-");
    }
    //  부호 우선 순위 두기
    var rankSignArr  = getPermutations(signArr,signArr.length);



    const regex = /[*\-+]/;
    //부호 순서 파싱하기 
    signArr = [];
    for(var i = 0;i<expression.length;i++){
        if(expression[i]==="+"||expression[i]==="*"||expression[i]==="-"){
            signArr.push(expression[i]);
        }
    }
    //숫자 파싱하기
    var numArr = expression.split(regex);

    var maxNum = 0;

    //랭킹 순으로 결과값 계산하기
    rankSignArr.forEach((rankArr)=>{
        var exSignArr = [...signArr];
        var exNumArr= [...numArr];
        var result  = 0;
        for(var i = 0;i<rankArr.length;i++){
            for(var signIndex = 0;signIndex<exSignArr.length;signIndex++){
               while(exSignArr.indexOf(rankArr[i])!==-1){
                var minusIndex =exSignArr.indexOf(rankArr[i]);
                if(exSignArr[minusIndex]==="*"){
                    exNumArr[minusIndex]= (Number(exNumArr[minusIndex]) *  Number(exNumArr[minusIndex+1]));
                }
                else if(exSignArr[minusIndex]==="+"){
                    exNumArr[minusIndex]= (Number(exNumArr[minusIndex]) +  Number(exNumArr[minusIndex+1]));
                }
                else if(exSignArr[minusIndex]==="-"){
                    exNumArr[minusIndex]= (Number(exNumArr[minusIndex]) -  Number(exNumArr[minusIndex+1]));
                }
                exSignArr.splice(minusIndex,1);
                exNumArr.splice(minusIndex+1,1);
               }
            }
        }

        exNumArr[0] = Math.abs(exNumArr[0]);
        if(exNumArr[0]>maxNum){
            maxNum = exNumArr[0];
        }
    })

    return maxNum;
}