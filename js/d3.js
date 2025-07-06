const fs = require("fs");

fs.readFile("puzzles/d3.txt", "utf-8", (lol, data) => {
    const lines = data.split(/\n|\r\n/);
    let ans1 = 0;
    let ans2 = 0;
    let enabled = true;
    lines.forEach((line) => {
        if (line == "") return;
        // Getting all mul(int, int), do() and don't()
        const res = line.match(/mul\(\d+,\d+\)|do\(\)|don\'t\(\)/g);
        res.forEach((mul) => {
            if (mul == "do()") {
                enabled = true;
            } else if (mul == "don't()") {
                enabled = false;
            } else {
                const nums = mul.match(/\d+/g);
                ans1 += nums[0] * nums[1];
                if (enabled) {
                    ans2 += nums[0] * nums[1];
                }
            }
        });
    });
    console.log("part1:", ans1, " part2:", ans2);
});
