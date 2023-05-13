function solution(n, info) {
  //라이언이 어떻게 쏠지에 대한 answer 배열
  var answer= new Array(11).fill(0);
  var maxDif = 0;
  function shootRyan(apeachCount,ryanCount, usedShotCount, point, arr){
    // 화살수가 이미 n을 넘었다면 패스
    if(n<usedShotCount)return;

    // 한바퀴를 돌았다면 값들을 체크
    if(point>10){
      // 둘의 점수를 체크
      var dif = ryanCount - apeachCount;
      //max보다 크다면
      if(maxDif<dif){
        //아직 못쏜 값은 마지막에 쏜다.
        arr[10] = n-usedShotCount;
        maxDif = dif;
        answer = arr;
      }
      return;
    }

    //라이언이 이길때
    if(n>usedShotCount){
      // 기존 arr을 받음
      var current = [...arr];
      // point에 해당하는 배열에 인덱스를 1추가
      current[10 - point] = info[10-point] + 1;
      // 라이언이 10-point번째 점수를 얻기 위해선 info에 해당하는 값보다 1은 커야 됌. 그만큼을 쏜다고 가정
      shootRyan(apeachCount,ryanCount + point, usedShotCount + info[10-point] + 1, point+1,current);
    };

    //어피치가 이기는 경우
    if(info[10-point]>0){
      // 어피치 점수에 point만큼을 더해주고 다음 포인터로 이동
      shootRyan(apeachCount+point,ryanCount,usedShotCount,point+1,arr);
    }
    else{
      //둘다 점수를 못얻는 상황: 둘다 0,0 번씩 쏜 경우는 다음 point로만 이동
      shootRyan(apeachCount,ryanCount,usedShotCount,point+1,arr);
    }
  }

  shootRyan(0,0,0,0,answer);

  if(maxDif===0){
    return [-1];
  }
  else{
    return answer;
  }
}