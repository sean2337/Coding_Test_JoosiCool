


function solution(word) {
    var answer = 0;
    var num = new Array(5).fill("");
    var alphaArr = ["U","O","I","E","A"];
    word = word.split("");

    while(true){
        //값이 없는게 있다면

        //입력값과 배열을 합쳤을때 같다면 리턴
        if(num.join("")===word.join(""))break;
        //num에 공백이 있다면 A로 채움
        if(num.indexOf("")!==-1){
            num[num.indexOf("")] = "A";
            answer++;
        }
        // 전부 채워졌다면
        else{
            //뒤부터 체크
            var i = 4;
            while(true){
                //요소가 U라면 삭제하고, 다음 꺼를 체크
                if(num[i]==="U"){
                    num[i] = "";
                    i--;
                }
                else{
                    // 체크 한 값을 업그레이드
                    num[i] = alphaArr[alphaArr.indexOf(num[i])-1];
                    answer++;
                    break;
                }
            }
        }
    }
    

    return answer;
}