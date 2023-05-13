function solution(users, emoticons) {
  var answer = [];
  var answerCheck = [];

  function permutation(arr, selectNum) {
    const result = [];
    if (selectNum === 1) return arr.map((v) => [v]);
  
    arr.forEach((v, idx, arr) => {
      const fixed = v;
      const restArr = arr;
      const permutationArr = permutation(restArr, selectNum - 1);
      const combineFix = permutationArr.map((v) => [fixed, ...v]);
      result.push(...combineFix);
    });
    return result;
  }
  
// 할인 가능성을 중복 순열로 경우의 수 뽑아낸다. 
var disCountArr = permutation([40,30,20,10],emoticons.length);

// 할인율 적용해서 서비스 가입자 수, 판매액 구하기 
var joinCount = 0;
var sale = 0;

for(var element of disCountArr){
  //element는 정한 할인율로 [40,40] 이런식으로 되어 있음.
  for(var i = 0;i<users.length;i++){
    var eachSale = 0;
    let[discountStand, moneyStand] = users[i];
    // discountStand => 이용자의 기준 할인 이 이하의 할인율은 고려하지 않는다.
    // moneyStand => 서비스 가입으로 돌리는 기준 돈 => 이를 넘어서면 서비스를 가입한다. 

    // 이모티콘에 할인율을 적용한 값을 sale에 더해줌,
    for(var eI = 0; eI<emoticons.length;eI++){
      //이모티콘 가격에 그 할인율 적용
      if(discountStand<=element[eI]){
        eachSale+= (emoticons[eI]* (100-element[eI])/100);
      }
    }

    // 값이 넘어간다면 서비스 가입자에 추가
    if(eachSale>=moneyStand){
      joinCount++;
    }
    // 그렇지 않으면 그 돈은 sale에 더해줌.
    else{
      sale+=eachSale;
    }
  }

  //그래서 유저를 통해서 나온 joinCount와 sale을 푸쉬해줌.
  answer.push([joinCount,sale]);
  joinCount = 0;
  sale = 0;
}

// 정렬
answer.sort((a,b)=>{
  if(a[0]>b[0]){
    return -1;
  }
  else if(a[0]===b[0]){
    if(a[1]>b[1]){
      return -1;
    }
    else{
      return 1;
    }
  }
  else{
    return 1;
  }
})

  return answer[0];
}