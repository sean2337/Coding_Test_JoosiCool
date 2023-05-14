function solution(n) {
  const MOD = 1000000007;
  var dp = [0,3,11];
    if(n%2===1){
        return 0;
    }
    else{
        n = n/2;
    }
    // dp[i] = dp[i-1] * 3 - dp[i-2]  
    
    for(var i =3;i<=n;i++){
        dp[i] = ((dp[i-1] * 4 % MOD) - (dp[i-2] % MOD) + MOD) % MOD;
    }
  return dp[n];
}