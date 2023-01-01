function solution(letter) {
    var answer = '';
    var mosArr = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
    var plus;

    //공백을 기준으로 잘라서 배열의 형태로 만듬.
    letter = letter.split(" ");
    for(var i=0;i<letter.length;i++){
        plus = String.fromCharCode(mosArr.indexOf(letter[i]) + 97);
        answer += plus;
    }

    return answer;
}
