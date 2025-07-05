#include "aoc.h"

int main() {
    auto start = Clock::now();

    ifstream file("puzzles/d10.txt");
    string line;
    vector<vector<int>> trail;
    vector<array<int, 2>> heads;      // y, x
    pair<int, int> currPos = {0, 0};  // y, x
    while (getline(file, line)) {
        currPos.second = 0;
        vector<int> currLine;
        int num{};
        for (char i : line) {
            num = i - '0';
            if (num == 0) {
                heads.push_back({currPos.first, currPos.second});
            }
            currLine.push_back(num);
            currPos.second++;
        }
        trail.push_back(currLine);
        currPos.first++;
    }

    set<pair<int, int>> visited;
    int ans2{};
    function<int(array<int, 2>, int)> dfs = [&](array<int, 2> pos, int height){
        if (pos[0] < 0 || pos[0] >= trail.size() || pos[1] < 0 || pos[1] >= trail[0].size()) {
            return 0;
        }
        int currHeight = trail[pos[0]][pos[1]];
        if (height + 1 != currHeight) {
            return 0;
        }
        if (currHeight == 9) {
            ans2++;
            if (visited.contains({pos[0], pos[1]})) {
                return 0;
            }
            visited.insert({pos[0], pos[1]});
            return 1;
        }
        return dfs({pos[0] - 1, pos[1]}, currHeight) + dfs({pos[0] + 1, pos[1]}, currHeight) +
               dfs({pos[0], pos[1] - 1}, currHeight) + dfs({pos[0], pos[1] + 1}, currHeight);
    };

    int ans{};
    for (auto head : heads) {
        visited.clear();
        ans += dfs(head, -1);
    }
    cout << ans <<" " << ans2 << '\n';

    duration<double> elapsed = Clock::now() - start;
    cout << elapsed.count() << " sec" << endl;
}
