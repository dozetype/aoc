#include "aoc.h"

array<array<int, 2>, 4> dirs = {{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};

int getSide(vector<array<int, 3>>& edges) {
    int sides{};
    while (!edges.empty()) {
        array<int, 3> startEdge = edges[0];
        auto it = find(edges.begin(), edges.end(), startEdge);
        edges.erase(it);
        vector<array<int, 3>> stack = {startEdge};

        // removing all edges on same side
        while (!stack.empty()) {
            array<int, 3> currEdge = stack.back();
            stack.pop_back();
            for (int i = 0, j = 0; i < 2; i++) {
                j = (currEdge[2] + 1 + (i * 2)) % 4;  // reduce loop count by half
                array<int, 3> nextEdge = {currEdge[0] + dirs[j][0], currEdge[1] + dirs[j][1],
                                          currEdge[2]};
                it = find(edges.begin(), edges.end(), nextEdge);
                if (it != edges.end()) {
                    stack.push_back(nextEdge);
                    edges.erase(it);
                }
            }
        }
        sides++;
    }
    return sides;
}

array<int, 3> getPerimeter(vector<array<int, 2>>& pType) {
    vector<array<int, 3>> edges;   // holds the pos and direction of edge
    set<array<int, 2>> plantsPos;  // bc we cannot increase perim if it is facing another plant
    array<int, 3> res{}; //area, perimeter, sides
    array<int, 2> startPlant = pType[0];
    auto it = find(pType.begin(), pType.end(), startPlant);
    pType.erase(it);
    res[0]++;
    plantsPos.insert(startPlant);
    vector<array<int, 2>> stack = {startPlant};
    while (!stack.empty()) {
        array<int, 2> currPlant = stack.back();
        stack.pop_back();
        for (int i = 0; i < 4; i++) {
            array<int, 2> nextPlant = {currPlant[0] + dirs[i][0], currPlant[1] + dirs[i][1]};
            it = find(pType.begin(), pType.end(), nextPlant);
            if (it != pType.end()) {
                stack.push_back(nextPlant);
                pType.erase(it);
                res[0]++;
                plantsPos.insert(nextPlant);
            } else if (plantsPos.find(nextPlant) == plantsPos.end()) {  // facing outside
                res[1]++;
                edges.push_back({currPlant[0], currPlant[1], i});
            }
        }
    }

    res[2] = getSide(edges);
    return res;
}

int main() {
    auto start = Clock::now();

    unordered_map<char, vector<array<int, 2>>> farm;  // store pos of each letter
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

    int ans1{};
    int ans2{};
    for (auto& i : farm) {
        while (!i.second.empty()) {
            array<int, 3> res = getPerimeter(i.second);
            ans1 += res[0] * res[1];
            ans2 += res[0] * res[2];
        }
    }
    cout << "part 1: " << ans1 << " part 2: " << ans2 << endl;

    duration<double> elapsed = Clock::now() - start;
    cout << elapsed.count() << " sec" << endl;
}
