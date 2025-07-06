const fs = require("fs");

function good(arr) {
    let increasing = false;
    let decreasing = false;
    for (let i = 0; i < arr.length - 1; i++) {
        const res = +arr[i] - +arr[i + 1];
        if (res < 0) increasing = true;
        if (res > 0) decreasing = true;
        if (res === 0 || Math.abs(res) > 3) return 0;
    }
    return increasing ^ decreasing;
}

fs.readFile("puzzles/d2.txt", "utf-8", (err, data) => {
    const lines = data.split(/\n/);

    let ans = 0;
    let ans2 = 0;
    lines.forEach((line) => {
        if (line == "") return;
        const arr = line.split(/\s+/);

        for (let i = 0; i < arr.length; i++) {
            // Removing 1 index from line
            const copy = arr.slice(0, i).concat(arr.slice(i + 1));
            if (good(copy)) {
                ans2++;
                break;
            }
        }
        ans += +good(arr);
    });
    console.log("part1:", ans, "part2:", ans2);
});
