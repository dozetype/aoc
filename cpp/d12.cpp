#include "aoc.h"

pair<int, int> getPerimeter(vector<array<int, 2>>& plantType);
array<array<int, 2>, 4> dirs = {{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};

unordered_map<char, vector<array<int, 2>>> farm;  // store pos of each letter
int main() {
    ifstream file("puzzles/d12.txt");
    string line;
    array<int, 2> currPos{};  // y, x
    while (getline(file, line)) {
        currPos[1] = 0;
        stringstream ss(line);
        char plant;
        while (ss >> plant) {
            farm[plant].push_back(currPos);
            currPos[1]++;
        }
        currPos[0]++;
    }

    int ans{};
    for (auto& i : farm) {
        // cout << i.first<< endl;
        while (i.second.size()) {
            pair<int, int> damn = getPerimeter(i.second);
            // cout << damn.first << " " << damn.second << '\n';
            ans += damn.first * damn.second;
        }
    }
    cout << ans << endl;
}

pair<int, int> getPerimeter(vector<array<int, 2>>& pType) {
    set<array<int, 2>> plantsPos;  // bc we cannot increase perim if it is facing another plant
    pair<int, int> areaPerim{};
    array<int, 2> startPlant = pType[0];
    auto it = find(pType.begin(), pType.end(), startPlant);
    pType.erase(it);
    areaPerim.first++;
    plantsPos.insert(startPlant);
    vector<array<int, 2>> stack = {startPlant};
    while (stack.size()) {
        array<int, 2> currPlant = stack.back();
        stack.pop_back();
        for (auto dir : dirs) {
            array<int, 2> nextPlant = {currPlant[0] + dir[0], currPlant[1] + dir[1]};
            auto it = find(pType.begin(), pType.end(), nextPlant);
            if (it != pType.end()) {
                stack.push_back(nextPlant);
                pType.erase(it);
                areaPerim.first++;
                plantsPos.insert(nextPlant);
            } else if (plantsPos.find(nextPlant) == plantsPos.end()) {
                areaPerim.second++;
            }
        }
    }
    return areaPerim;
}
