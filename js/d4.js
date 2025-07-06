const fs = require("fs");

const dirs = [
    [0, 1],
    [1, 1],
    [1, 0],
    [1, -1],
    [0, -1],
    [-1, -1],
    [-1, 0],
    [-1, 1],
]; // eight principal wind

const MAS = "M".charCodeAt(0) + /*'A'*/ "S".charCodeAt(0);

fs.readFile("puzzles/d4.txt", "utf-8", (lol, data) => {
    const letters = [];
    const lines = data.split(/\n/);
    lines.forEach((line) => {
        if (line == "") return;
        letters.push(line);
    });
    let ans1 = 0;
    let ans2 = 0;
    const width = letters[0].length;
    const height = letters.length;
    for (let i = 0; i < height; i++) {
        for (let j = 0; j < width; j++) {
            if (letters[i][j] == "X") {
                dirs.forEach((dir) => {
                    const yMax = i + 3 * dir[0];
                    const xMax = j + 3 * dir[1];
                    if (
                        yMax >= 0 &&
                        yMax < height &&
                        xMax >= 0 &&
                        xMax < width
                    ) {
                        if (
                            letters[i + dir[0]][j + dir[1]] == "M" &&
                            letters[i + 2 * dir[0]][j + 2 * dir[1]] == "A" &&
                            letters[yMax][xMax] == "S"
                        ) {
                            ans1++;
                        }
                    }
                });
            }
            if (letters[i][j] == "A") {
                if (
                    i - 1 >= 0 &&
                    i + 1 < height &&
                    j - 1 >= 0 &&
                    j + 1 < width
                ) {
                    let diagonal1 = 0;
                    let diagonal2 = 0;
                    for (let k = 1; k < 8; k += 2) {
                        if (k == 1 || k == 5)
                            diagonal1 +=
                                letters[i + dirs[k][0]][
                                    j + dirs[k][1]
                                ].charCodeAt(0);
                        else
                            diagonal2 +=
                                letters[i + dirs[k][0]][
                                    j + dirs[k][1]
                                ].charCodeAt(0);
                    }
                    if (diagonal1 == MAS && diagonal2 == MAS) ans2++;
                }
            }
        }
    }
    console.log("part1:", ans1, " part2:", ans2);
});
