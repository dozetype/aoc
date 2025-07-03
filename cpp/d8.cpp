#include "aoc.h"
#include <set>

int main(){
    ifstream file("puzzles/d8.txt");
    string line;
    unordered_map<char, vector<pair<int, int>>> allAntenna;
    pair<int, int> map;
    while(getline(file, line)){
        map.second = 0;
        stringstream ss(line);
        char c;
        while(ss>>c){
            if(c!='.') allAntenna[c].push_back(map);
            map.second++;
        }
        map.first++;
    }
    set<pair<int, int>> nodes;
    for(auto letter: allAntenna){
        auto& ants = letter.second;
        for(int i=0; i<ants.size(); i++){
            for(int j=0; j<ants.size(); j++){
                if(i==j) continue;
                pair<int, int> dist;
                dist.first = ants[i].first-ants[j].first;
                dist.second = ants[i].second-ants[j].second;
                int node1Y = ants[i].first + dist.first;
                int node1X = ants[i].second + dist.second;
                int node2Y = ants[j].first - dist.first;
                int node2X = ants[j].second - dist.second;
                if(node1Y>=0 && node1Y<map.first && node1X>=0 && node1X<map.second){
                    nodes.insert({node1Y, node1X});
                }
                if(node2Y>=0 && node2Y<map.first && node2X>=0 && node2X<map.second){
                    nodes.insert({node2Y, node2X});
                }
            }
        }
    }
    cout << nodes.size();
}
