#include "aoc.h"

int main() {
    auto start = Clock::now();
    ifstream file("puzzles/d8.txt");
    string line;
    unordered_map<char, vector<pair<int, int>>> allAntenna;
    pair<int, int> map;
    while (getline(file, line)) {
        map.second = 0;
        stringstream ss(line);
        char c;
        while (ss >> c) {
            if (c != '.') allAntenna[c].push_back(map);
            map.second++;
        }
        map.first++;
    }
    set<pair<int, int>> nodes;
    for (auto letter : allAntenna) {
        auto& ants = letter.second;
        for (int i = 0; i < ants.size(); i++) {
            for (int j = 0; j < ants.size(); j++) {
                if (i == j) continue;
                pair<int, int> dist;
                dist.first = ants[i].first - ants[j].first;
                dist.second = ants[i].second - ants[j].second;
                int mul{1};
                while (ants[i].first + mul * dist.first >= 0 &&
                       ants[i].first + mul * dist.first < map.first &&
                       ants[i].second + mul * dist.second >= 0 &&
                       ants[i].second + mul * dist.second < map.second) {
                    int node1Y = ants[i].first + mul * dist.first;
                    int node1X = ants[i].second + mul * dist.second;
                    nodes.insert({node1Y, node1X});
                    mul++;
                }
                mul = 1;
                while (ants[j].first - mul * dist.first >= 0 &&
                       ants[j].first - mul * dist.first < map.first &&
                       ants[j].second - mul * dist.second >= 0 &&
                       ants[j].second - mul * dist.second < map.second) {
                    int node2Y = ants[j].first - dist.first;
                    int node2X = ants[j].second - dist.second;
                    nodes.insert({node2Y, node2X});
                    mul++;
                }
                // inserting antenna itself as a node
                nodes.insert({ants[i].first, ants[i].second});
                nodes.insert({ants[j].first, ants[j].second});
            }
        }
    }
    cout << nodes.size() << endl;
    duration<double> elapsed = Clock::now() - start;
    cout << elapsed.count() << endl;
}
