function solution(today, terms, privacies) {
    
    var answer = [];
    
    // 날짜를 넣으면 총 일수를 알려주는 함수
    //인자: 2022.05.19
    function dateFun(day){
        let [year,month,date] = day.split(".");
        //2000이상이기 때문에 100아래 숫자만을 남김 => 계산을 위해
        year = year-2000;
        
        //문자열인 숫자를 숫자형태로 변환
        year = Number(year); month = Number(month); date = Number(date);
        return year * 28* 12 + month * 28 + date; 
    }
    
    //terms에 따른 hashMap만들기 key = 종류 A,B,C... value: 기간 day기준
    var termMap = new Map();
    terms.forEach((element)=>{
        let[kind, term] = element.split(" ");
        termMap.set(kind, Number(term)*28);
    })
    
    
    //오늘을 일수로 계산한 변수 생성
    var todayDate = dateFun(today);
    
    
    privacies.forEach((element,idx)=>{
        let[day, kind] = element.split(" ");
        //파기되어야 하는 날짜 확인
        var eraseDate = dateFun(day) + termMap.get(kind);
        
        if(eraseDate<=todayDate){
            answer.push(idx+1);
        }    
    })
    
    return answer;
}