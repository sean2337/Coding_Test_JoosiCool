function solution(m, n, startX, startY, balls) {
    var answer = [];
    // 점 두개를 입력시에 거리를 리턴하는 함수 => 거리는 제곱기준으로 리턴
    function disFun(point1,point2){
        return ((point1[0] - point2[0])**2+ (point1[1]- point2[1])**2);
    }
    
    
    balls.forEach((element)=>{
        let [x,y] = element;
        let resultArr = [];
        let result;
        if(startX===x && startY === y){
            console.log("같음");
        }
        // y 축으로 평행할때
        else if(startX === x){
            if(startY>y){
                result = (n- startY + n-y)**2;
                resultArr.push(result);
            }
            // 탐색 y값이 더 크다면
            else{
                result = (startY + y) **2;
                resultArr.push(result);
            }

            result = disFun([startX,startY],[-x,y]);
            resultArr.push(result);

            result = disFun([startX,startY],[m+m-x,y]);
            resultArr.push(result);


        }
        else if(startY === y){
            if(startX>x){
                result = (m- startX + m-x)**2;
                resultArr.push(result);
            }
            // 탐색 y값이 더 크다면
            else{
                result = (startX + x) **2;
                resultArr.push(result);
            }
            result = disFun([startX,startY],[x,-y]);
            resultArr.push(result);

            result = disFun([startX,startY],[x,n+n-y]);
            resultArr.push(result);
        }
        // 전부 다르다면
        else{
            result = disFun([startX,startY],[x,-y]);
            resultArr.push(result);

            result = disFun([startX,startY],[x,n+n-y]);
            resultArr.push(result);

            result = disFun([startX,startY],[-x,y]);
            resultArr.push(result);

            result = disFun([startX,startY],[m+m-x,y]);
            resultArr.push(result);
        }

        answer.push(Math.min(...resultArr));
        
    })    
    return answer;
}