function solution(progresses, speeds) {
    var answer = [];
    //progresses가 빌때까지 계속진행
    while(progresses.length){
        if(progresses[0]>=100){
            var count = 0;
            var stack = [];
            var speedStack = [];
            var check = true;
            for(var i = 0;i<progresses.length;i++){
                if(progresses[i]>=100&&check===true){
                    count++;
                }
                else{
                    if(check===true) check = false;
                    stack.push(progresses[i]);
                    speedStack.push(speeds[i]);
                }
            }
            if(count>0) answer.push(count);
            progresses = stack;
            speeds = speedStack;
        }
        
        else{for(var i = 0;i<progresses.length;i++){
            progresses[i] += speeds[i];
        }}
    }
    return answer;
}