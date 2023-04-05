function solution(N, road, K) {
    var answer = 0;
    //K이하인 수를 기준으로 하기 때문에 안전하게 제일 큰수를 넣어둔다.
    const dist = Array(N + 1).fill(Number.MAX_SAFE_INTEGER);
    //line을 받을 배열의 배열을 만듬.
    var lines = Array.from(Array(N+1),()=>[]);

    //road를 값으로 나눈다. 
    //a=> 출발지, b=>가는 곳, c=> 걸리는 시간 (비용)
    //단, b->a도 가능하기 때문에 이도 고려
    road.forEach(element => {
        let [a,b,c] = element;
        lines[a].push({to: b, cost: c});
        lines[b].push({to: a, cost: c});
    });
    //BFS 사용
    //먼저 큐에 초기값 1, 0대입.
    let queue = [{to: 1, cost: 0}];
    dist[1] = 0;

    while(queue.length){
        // 큐에 잇는 요소 뺸다. -> to가 2라면 2까지 온것을 의미
        let {to,cost} = queue.pop();

        //2가 갈 수 있는 곳을 서치해서 그 다음에 해당하는 값보다 지금 코스트 더한 값이 더 작을 경우
        // 그 배열 초기화 
        //ex) 2-> 3, cost =2; 현재 3의 최소 값은 5인데, 2까지 오는데는 2만큼 걸렸어.
        //그러면 더해도 4밖에 안되네! 이게 최솟값이다!
        lines[to].forEach((next)=>{
            if(dist[next.to]>dist[to]+ next.cost){
                dist[next.to] = dist[to]+ next.cost;
                queue.push(next);
            }
        }
         
        )
    }
    answer = dist.filter((item)=>item<=K).length;

    return answer;
}