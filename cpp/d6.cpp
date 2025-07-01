#include "aoc.h"

int main() {
    vector<vector<char>> map;
    ifstream file("puzzles/d6.txt");
    string line;
    pair<int, int> pos;
    int y;
    while (getline(file, line)) {
        int x{};
        stringstream ss(line);
        char c;
        vector<char> row;
        while (ss >> c) {
            if (c == '^') {
                pos = {y, x};
            }
            row.push_back(c);
            x++;
        }
        map.push_back(row);
        y++;
    }
    int dirs[4][2] = {{0,-1}, {1, 0}, {0, 1}, {-1, 0}};
    int d = 0;
    set<pair<int, int>> travelled;
    while (true) {
        travelled.insert(pos);
        int nextY = pos.first + dirs[d][1];
        int nextX = pos.second + dirs[d][0];
        if (nextX < 0 || nextX >= map[0].size() || nextY < 0 || nextY >= map.size()) break;
        if (map[nextY][nextX] == '.') {
            pos = {nextY, nextX};
        }
        else {
            d = (d + 1) % 4;
        }
    }
    cout << travelled.size() << endl;
}