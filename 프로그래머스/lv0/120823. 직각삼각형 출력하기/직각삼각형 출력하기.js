let input = require("fs").readFileSync('/dev/stdin').toString().split("\n");

var star = "*";

for (var i = 0; i < input[0]; i++) {
  console.log(star);
  star += "*";
}
