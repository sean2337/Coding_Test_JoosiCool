function solution(lottos, win_nums) {
    var answer = [];
    var collectMax = 0;
    var collect = 0;
    lottos.forEach(element=>{
        if(win_nums.indexOf(element)!==-1){
            collectMax++;
            collect++;
        }
        else if(element ===0){
            collectMax++;
        }
    })
    var Rank = [6,6,5,4,3,2,1];
    answer = [Rank[collectMax],Rank[collect]];
    
    return answer;
}