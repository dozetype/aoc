#include "aoc.h"

struct Node{
    int dist{INT_MAX};
    pair<int, int> prev;
    bool wall;
    
    Node(bool isWall = false):wall(isWall){};
};

int main(){
    ifstream file("puzzles/d16.txt");
    string line;
    vector<vector<Node>> maze;
    pair<int, int> startPos;
    pair<int, int> endPos;
    int x{}, y{};
    while(getline(file, line)){
        x = 0;
        stringstream ss(line);
        char c;
        vector<Node> currLine;
        while(ss >> c){
            if(c == 'S') startPos = {y, x};
            else if(c == 'E') startPos = {y, x};
            if(c != '#') currLine.emplace_back(Node(false));
            else currLine.emplace_back(Node(true));
        }
        maze.push_back(currLine);
        ++y;
    }
    for(auto i: maze){
        for(auto x: i){
            cout << x.wall;
        }
        cout << "\n";
    }
}
