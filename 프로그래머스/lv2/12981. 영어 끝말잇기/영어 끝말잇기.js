function solution(n, words) {
    var answer = [0,0];
    var memoryWords = [words[0]];
    
    for(var index = 1;index<words.length;index++){
        if((words[index-1][words[index-1].length-1]===words[index][0])&&(memoryWords.includes(words[index])===false)){
          memoryWords.push(words[index]);
        }
        else{
            answer[0] = index % n +1;
            answer[1] = Math.floor(index/n) + 1;
            break;
        }
        
    }
    return answer;
}