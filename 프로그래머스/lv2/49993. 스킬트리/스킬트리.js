function solution(skill, skill_trees) {
    var answer = 0;
    //스킬트리 찍을 수 있는 순서 경우 구하기 => C CB CBD
    var chanceSkill = [];
    for(var i = 1;i<=skill.length+1;i++){
        chanceSkill.push(skill.substr(0,i));
    }    
    //스킬 쪼개기
    skill = skill.split("");
    var checkSkill;
    for(var i = 0; i<skill_trees.length;i++){
        //BACDE => B, A, C, D, E 
        // Skill에 있는 것만 남겨둠. B C D
        //B C D => BCD
        checkSkill = skill_trees[i].split("").filter((element)=> skill.indexOf(element)!==-1).join("");
        if(chanceSkill.indexOf(checkSkill)!==-1||checkSkill.length===0) answer++;
    }
    return answer;
}