const fs = require("fs");

const arr1 = [];
const arr2 = [];
const map = {};

//convert buffer to string and pass into function to extract
fs.readFile("puzzles/d1.txt", "utf8", (err, data) => {
  if (err) throw err;

  const lines = data.split(/\n|\r\n/); //only need \n but windows wanna be special
  for (let i = 0; i < lines.length; i++) {
    if (lines[i] === "") {
      continue;
    }
    const [a, b] = lines[i].split(/\s+/);
    arr1.push(+a);
    const bInt = +b;
    arr2.push(bInt);
    if (map[bInt]) {
      map[bInt]++;
    } else {
      map[bInt] = 1;
    }
  }

  // Sort ascending order
  arr1.sort((x, y) => x - y);
  arr2.sort((x, y) => x - y);
  let ans = 0;
  let ans2 = 0;
  for (let i = 0; i < arr1.length; i++) {
    ans += Math.abs(arr1[i] - arr2[i]);
    if (map[arr1[i]]) { //if left value exist in the right side
      ans2 += arr1[i] * map[arr1[i]];
    }
  }
  console.log("part1:", ans, "part2:", ans2); //part1: 2057374 part2: 23177084
});
