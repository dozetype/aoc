const fs = require("fs");

fs.readFile("puzzles/d5.txt", "utf-8", (lol, data) => {
    const rules = {};
    const lines = data.split(/\n/);
    let firstPart = true;
    let ans1 = 0;
    let ans2 = 0;
    for (const line of lines) {
        if (line == "") firstPart = false;
        else if (firstPart) {
            const [a, b] = line.split(/\|/);
            if (!rules[a]) {
                rules[a] = [];
            }
            rules[a].push(b);
        } else {
            let ok = true;
            const currLine = line.split(/\,/);
            for (let i = 1; i < currLine.length; i++) {
                for (let j = 0; j < i; j++) {
                    if (rules[currLine[i]].includes(currLine[j])) {
                        ok = false;
                        [currLine[i], currLine[j]] = [currLine[j], currLine[i]];
                    }
                }
            }
            if (ok) {
                ans1 += +currLine[Math.floor(currLine.length / 2)];
            } else {
                ans2 += +currLine[Math.floor(currLine.length / 2)];
            }
        }
    }
    console.log("part1:", ans1, "part2:", ans2);
});
