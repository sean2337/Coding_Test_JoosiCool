function getPermutations(arr, selectNumber) {
  const result = [];
  if (selectNumber === 1) return arr.map((value) => [value]);
  arr.forEach((fixed, index, origin) => {
    const rest = [...origin.slice(0, index), ...origin.slice(index + 1)];
    const permutations = getPermutations(rest, selectNumber - 1);
    const attached = permutations.map((permutation) => [fixed, ...permutation]);
    result.push(...attached);
  });
  return result;
}

const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
let num = Number(input[0]);
let arr = new Array(num);
for (let i = 0; i < num; i++) {
  arr[i] = i + 1;
}

const result = getPermutations(arr, num)
  .map((v) => v.join(' '))
  .join('\n');
console.log(result);
