function solution(a, b) {
    var first = Number(a.toString() + b.toString());
    var second =  Number(b.toString() +a.toString());
    return first>second? first:second;
}