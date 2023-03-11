function solution(dirs) {
    //중복을 제거하기 위해, Set사용
    var set = new Set();
    var location = [0,0];
    dirs = dirs.split("");
    var plus;
    dirs.forEach((element)=>{
        // 00 -> 11 = 0011푸쉬
        if(element==='U'&&location[1]<5){
            plus = ""+location[0] + location[1] + location[0] + (location[1]+1);
            set.add(plus);
            plus = "" + location[0] + (location[1]+1)+location[0] + location[1];
            set.add(plus);
            location[1]++;
        }
        else if(element ==='D'&&location[1]>-5){
            plus = ""+location[0] + location[1] + location[0] + (location[1]-1);
            set.add(plus);
            plus = ""+ location[0] + (location[1]-1)+location[0] + location[1];
            set.add(plus);
            location[1]--;
        }
        else if(element ==='R'&&location[0]<5){
            plus = ""+location[0] + location[1] + (location[0]+1) + location[1];
            set.add(plus);
            plus = "" + (location[0]+1) + location[1]+location[0] + location[1];
            set.add(plus);
            location[0]++;
        }
        else if(element ==='L'&&location[0]>-5){
            plus = ""+location[0] + location[1] + (location[0]-1) + location[1];
            set.add(plus);
            plus = ""+ (location[0]-1) + location[1]+location[0] + location[1];
            set.add(plus);
            location[0]--;
        }
    })
    return set.size/2;
}

console.log(solution("ULURRDLLU"));