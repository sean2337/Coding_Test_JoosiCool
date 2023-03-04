function permutate(arr) {
    const result = [];
    //DFS
    const dfs = (i, arr) => {
      // base condition
      if (i === arr.length) {
        return result.push([...arr]);
      }
  
      for (let j = i; j < arr.length; j++) {
        //swap
        [arr[i], arr[j]] = [arr[j], arr[i]];
        //dfs
        dfs(i + 1, arr);
        //swap back
        [arr[i], arr[j]] = [arr[j], arr[i]];
      }
    };
    dfs(0, arr);
    return result;
}


function solution(k, dungeons) {
    //순서를 나타낼 배열 생성
    var orderArr = new Array(dungeons.length);
    for( var i =0;i<orderArr.length;i++){
        orderArr[i]=i;
    }
    //그 순서를 순열로 가능한 순서 다 구함
    permutateArr = permutate(orderArr);
    var max_Count = 0;
    for(var i = 0;i<permutateArr.length;i++){
        var sum = k;
        var count = 0;
        for(var permutateIndex = 0;permutateIndex<permutateArr[i].length;permutateIndex++){
            //최소 조건 체크
            if(sum>=dungeons[permutateArr[i][permutateIndex]][0]){
                sum-=dungeons[permutateArr[i][permutateIndex]][1];
                count++;
            }
            else{
                break;
            }
        }
        

        if(max_Count<count){
            max_Count=count;
        }
    }
    return max_Count;
}