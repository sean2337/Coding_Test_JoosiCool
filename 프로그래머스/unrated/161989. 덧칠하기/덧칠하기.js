function solution(n, m, section) {
    var answer = 0;
    for(var i =0;i<n;i++){
        //값이 있다면
        if(section.indexOf(i+1)!==-1){
            i+=(m-1);
            answer++;
        }
    }
    return answer;
}