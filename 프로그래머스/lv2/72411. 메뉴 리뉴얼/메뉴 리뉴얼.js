function solution(orders, course) {
    var answer = [];

    const getCombinations = function (arr, selectNumber) {
        const results = [];
        if (selectNumber === 1) return arr.map((el) => [el]); 
        // n개중에서 1개 선택할 때(nC1), 바로 모든 배열의 원소 return
    
        arr.forEach((fixed, index, origin) => {
          const rest = origin.slice(index + 1); 
          const combinations = getCombinations(rest, selectNumber - 1); 
          const attached = combinations.map((el) => [fixed, ...el]); 
          results.push(...attached); 
          
        });
        return results;
    }


    course.forEach((count)=>{
        var hashMap = new Map();
        orders.forEach((element)=>{
            element = element.split("");
            var divArr = getCombinations(element,count);
            for(var index = 0;index<divArr.length;index++){
                var word = divArr[index].sort().join("");
                // 있다면?
                if(hashMap.has(word)){
                    hashMap.set(word,hashMap.get(word)+1);
                }
                
                //없다면?
                else{
                    hashMap.set(word,1);
                }
            }            
        })

        //최대 구하기
        var maxValue = 0;
        for(let [key,value] of hashMap){
            if(maxValue<value&&key.length>=2&&value>=2){
                maxValue = value;
            }
        }

        for(let [key,value] of hashMap){
            if(maxValue===value){
                answer.push(key);
            }
        }
        //console.log(hashMap);
        hashMap.clear();
    })
    return answer.sort();
}