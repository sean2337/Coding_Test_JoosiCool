function solution(bridge_length, weight, truck_weights) {
    var answer = 0;
    var copyTruck = [...truck_weights];
    //다리를 건너는 트럭 배열 만들기
    var bridgeArr = new Array(bridge_length).fill(0);
    //다리를 다 건넌 트럭 배열
    var completeArr = [];
    var truckLen = truck_weights.length;
     var sum = 0;
    var count=0;
    while(true){
        //모든 차가 완료되었다면 끝
        answer++;
        //차 지나가고 무게가 넘지않는다면 하나 푸쉬하기.
        var popTruck = bridgeArr.pop();
        sum -= popTruck;
        if(copyTruck.indexOf(popTruck)!==-1) count++;
        if(count === truckLen){
            break;
        }
        if(sum+truck_weights[0]<=weight){
            var plus =truck_weights.shift();
            bridgeArr.unshift(plus);
            sum+=plus;           
        }
        else{
            bridgeArr.unshift(0);
        } 
    }  
    return answer;
}