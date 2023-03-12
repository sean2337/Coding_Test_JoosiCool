function solution(files) {
    var answer = [];
    let numberRegex = /[0-9]/;
    let englishRegex =  /[\-.A-Za-z ]/;

    //HEAD, NUMBER, TAIL 나누기
    var arr = [];
    var numberStartIndex;
    var tailStartIndex;
    var head, number, tail;

    files.forEach((element,index) => {
        //숫자 시작하는 곳 찾기
        numberStartIndex = element.search(numberRegex);
        //head 구하기
        head = element.substring(0,numberStartIndex)
        //head 이후로 자르기
        element = element.substring(numberStartIndex);
        tailStartIndex = element.search(englishRegex);
        //number구하기
        if(tailStartIndex>5){tailStartIndex = 5;}
        //뒤에 공백일때 예외 처리
        if(tailStartIndex===-1){
            number = element.substring(0,5);
        }
        else{
            number = element.substring(0,tailStartIndex);
        } 
        //tail 구하기
        tail = element.substring(tailStartIndex)
        arr.push([head, number, tail,index])

    });

    //정렬 알고리즘
    arr.sort((a,b)=>{
        if(a[0].toLowerCase()>b[0].toLowerCase()){
            return 1;
        }
        else if(a[0].toLowerCase()===b[0].toLowerCase()){
            if(Number(a[1])>Number(b[1])){
                return 1;
            }
            else if(Number(a[1])===Number(b[1])){
                return 0;
            }
            else{
                 return -1;
            }
        }
        else{
            return -1;
        }
    })

    arr.forEach(element=>{
        answer.push(files[element[3]]);
    })
    return answer;
}