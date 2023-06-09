function solution(myString, pat) {
     return myString.split("").map((element)=>{
         if(element==='A'){
             return 'B';
         }
         else{
             return 'A';
         }
     }).join("").includes(pat)===true? 1: 0;
}