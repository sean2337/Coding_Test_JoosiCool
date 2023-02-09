
  function solution(n) {
      var ansArr = [0,1,2];
      if(n<=2) return ansArr[n];
      for(var i =3;i<=n;i++){
          ansArr[i] = (ansArr[i-1] + ansArr[i-2])%1234567;
      }
      return ansArr[n];
  }