function solution(citations) {
    //내림차순으로 정렬
    citations = citations.sort((a,b)=>{return a>b?-1:1});
    var num = citations[0];
   while(true){
       var left = 0;
       var right =0;
       citations.forEach(element=>{
           if(num<=element){
               left++
           }
           else{
               right++;
           }
       })
       if(num<=left&&num>=right)return num;
       else{
        num--;
       }
   }
}