#include "aoc.h"

int main() {
    vector<string> map;
    ifstream file("puzzles/d6.txt");
    string line;
    pair<int, int> pos;
    int ans2{};
    while (getline(file, line)) {
        map.push_back(line);
    }
    const int H = map.size();
    const int W = map[0].size();
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            if (map[y][x] == '^') {
                pos = {y, x};
                map[y][x] = '.';
            }
        }
    }

    constexpr int dirs[4][2] = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};

    auto checkLoop = [&]() {
        int d = 0;
        vector<bool> allPos(map.size() * map[0].size() * 4, false);
        pair<int, int> me = pos;
        while (true) {
            const int hash = (me.first*map[0].size()+me.second)*4 + d;
            if (allPos[hash]){ return true;} //if I've been here before with same direction. Means its a loop
            allPos[hash] = true;
            int nextY = me.first + dirs[d][0];
            int nextX = me.second + dirs[d][1];
            if (nextX < 0 || nextX >= map[0].size() || nextY < 0 || nextY >= map.size()){return false;}
            if (map[nextY][nextX] == '.') {
                me = {nextY, nextX};
            }
            else {
                d = (d + 1) % 4;
            }
        }
    };
    set<pair<int, int>> travelled;
    pair<int, int> me = pos;
    int d{0};
    while (true) {
        travelled.insert(me);
        int nextY = me.first + dirs[d][0];
        int nextX = me.second + dirs[d][1];
        if (nextX < 0 || nextX >= map[0].size() || nextY < 0 || nextY >= map.size()){break;}
        if (map[nextY][nextX] == '.') {
            me = {nextY, nextX};
        }
        else {
            d = (d + 1) % 4;
        }
    }

    for (int j=0; j<map.size(); j++) {
        for (int k=0; k<map[0].size(); k++) {
            if (map[j][k]=='.' && pos!=make_pair(j,k)) {
                map[j][k] = '#';
                if (checkLoop()) ans2++;
                map[j][k] = '.';
            }
        }
    }
    cout <<travelled.size()<< " "<< ans2 << endl;
}
