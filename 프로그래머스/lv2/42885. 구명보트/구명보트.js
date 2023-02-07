function solution(people, limit) {
    var answer = 0;
    // 내림차순으로 정렬
    people = people.sort((a,b)=>{
        return a>b? -1:1;
    })
    var left = 0;
    var right = people.length-1;

    while(left<right){
        //넘지 않는다면 이 둘을 채택
        if(people[left]+people[right]<=limit){
            left++;
            right--;
        }
        //넘는다면 무거운 사람 한명만 구명보트에 태움
         else{
            left++;
        }
        answer++;
    }
    //중간에 한명이 남았다면 그 사람 구명보트 태움
    if(right === left){
        answer++;
    }
    return answer;

}
