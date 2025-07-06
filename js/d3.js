const fs = require("fs");

fs.readFile("puzzles/d3.txt", "utf-8", (lol, data) => {
    const lines = data.split(/\n|\r\n/);
    let ans = 0;
    let enabled = true;
    lines.forEach((line) => {
        if (line == "") return;
        const res = line.match(/mul\(\d+,\d+\)|do\(\)|don\'t\(\)/g);
        res.forEach((mul) => {
            // console.log(mul);
            if (mul == "do()") {
                enabled = true;
            } else if (mul == "don't()") {
                enabled = false;
            } else if (enabled) {
                const nums = mul.match(/\d+/g);
                ans += nums[0] * nums[1];
            }
        });
    });
    console.log(ans);
});
