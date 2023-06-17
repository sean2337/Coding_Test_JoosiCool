function solution(players, callings) {

    //key=선수이름 ,key=랭킹
    var mapPlayer = new Map();
    var mapRank = new Map();
    
    
    players.forEach((element,index)=>{
        mapPlayer.set(element,index+1);
        mapRank.set(index+1,element)
    })
    
    
    callings.forEach((name)=>{
        var curRank = mapPlayer.get(name);
        // 현재 선수보다 앞썬 선수에 이름을 가져온다.
        var front_Player = mapRank.get(curRank-1);
        mapPlayer.set(name,curRank-1);
        mapPlayer.set(front_Player, curRank);
        
        mapRank.set(curRank, front_Player);
        mapRank.set(curRank-1, name);
    })
    
    var arr = new Array(...mapRank).sort((a,b)=>a[0]-b[0]).map((element)=>element[1]);
    

    return arr;
}